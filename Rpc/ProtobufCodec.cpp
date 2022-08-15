#include "ProtobufCodec.h"
#include "../Tcp/TcpConnection.h"
#include <cassert>
#include <google/protobuf/message.h>
#include <muduo/net/Endian.h>
using namespace ::QE;
using namespace ::QE::net;

void ProtobufCodecLite::send(const TcpConnectionPtr& conn,
    const ::google::protobuf::Message& message)
{
    // FIXME: serialize to TcpConnection::outputBuffer()
    muduo::net::Buffer buf;
    fillEmptyBuffer(&buf, message);
    conn->send(&buf);
}

void ProtobufCodecLite::fillEmptyBuffer(muduo::net::Buffer* buf,
    const google::protobuf::Message& message)
{
    assert(buf->readableBytes() == 0);
    // FIXME: can we move serialization & checksum to other thread?
    buf->append(tag_);

    int byte_size = serializeToBuffer(message, buf);

    int32_t checkSum = checksum(buf->peek(), static_cast<int>(buf->readableBytes()));
    buf->appendInt32(checkSum);
    assert(buf->readableBytes() == tag_.size() + byte_size + kChecksumLen);
    (void)byte_size;
    int32_t len = muduo::net::sockets::hostToNetwork32(static_cast<int32_t>(buf->readableBytes()));
    buf->prepend(&len, sizeof len);
}

void ProtobufCodecLite::onMessage(const TcpConnectionPtr& conn,
    Buffer* buf,
    Timestamp receiveTime)
{
    while (buf->readableBytes() >= static_cast<uint32_t>(kMinMessageLen + kHeaderLen)) {
        const int32_t len = buf->peekInt32();
        if (len > kMaxMessageLen || len < kMinMessageLen) {
            errorCallback_(conn, buf, receiveTime, kInvalidLength);
            break;
        } else if (buf->readableBytes() >= static_cast<size_t>(kHeaderLen + len)) {
            if (rawCb_ && !rawCb_(conn, StringPiece(buf->peek(), kHeaderLen + len), receiveTime)) {
                buf->retrieve(kHeaderLen + len);
                continue;
            }
            MessagePtr message(prototype_->New());
            // FIXME: can we move deserialization & callback to other thread?
            ErrorCode errorCode = parse(buf->peek() + kHeaderLen, len, message.get());
            if (errorCode == kNoError) {
                // FIXME: try { } catch (...) { }
                messageCallback_(conn, message, receiveTime);
                buf->retrieve(kHeaderLen + len);
            } else {
                errorCallback_(conn, buf, receiveTime, errorCode);
                break;
            }
        } else {
            break;
        }
    }
}

bool ProtobufCodecLite::parseFromBuffer(StringPiece buf, google::protobuf::Message* message)
{
    return message->ParseFromArray(buf.data(), buf.size());
}

int ProtobufCodecLite::serializeToBuffer(const google::protobuf::Message& message, Buffer* buf)
{
    auto byte_size = message.ByteSizeLong();
    buf->ensureWritableBytes(byte_size + kChecksumLen);

    uint8_t* start = reinterpret_cast<uint8_t*>(buf->beginWrite());
    uint8_t* end = message.SerializeWithCachedSizesToArray(start);
    assert(end - start == byte_size);
    buf->hasWritten(byte_size);
    return byte_size;
}

namespace {
using std::string;
const string kNoErrorStr = "NoError";
const string kInvalidLengthStr = "InvalidLength";
const string kCheckSumErrorStr = "CheckSumError";
const string kInvalidNameLenStr = "InvalidNameLen";
const string kUnknownMessageTypeStr = "UnknownMessageType";
const string kParseErrorStr = "ParseError";
const string kUnknownErrorStr = "UnknownError";
}

const string& ProtobufCodecLite::errorCodeToString(ErrorCode errorCode)
{
    switch (errorCode) {
    case kNoError:
        return kNoErrorStr;
    case kInvalidLength:
        return kInvalidLengthStr;
    case kCheckSumError:
        return kCheckSumErrorStr;
    case kInvalidNameLen:
        return kInvalidNameLenStr;
    case kUnknownMessageType:
        return kUnknownMessageTypeStr;
    case kParseError:
        return kParseErrorStr;
    default:
        return kUnknownErrorStr;
    }
}

void ProtobufCodecLite::defaultErrorCallback(const TcpConnectionPtr& conn,
    Buffer* buf,
    Timestamp,
    ErrorCode errorCode)
{
    LOG_ERROR << "ProtobufCodecLite::defaultErrorCallback - " << errorCodeToString(errorCode);
    if (conn && conn->connected()) {
        conn->shutdown();
    }
}

int32_t ProtobufCodecLite::asInt32(const char* buf)
{
    int32_t be32 = 0;
    ::memcpy(&be32, buf, sizeof(be32));
    return muduo::net::sockets::networkToHost32(be32);
}

int32_t ProtobufCodecLite::checksum(const void* buf, int len)
{
    const char* data = static_cast<const char*>(buf);
    const uint32_t MOD_ADLER = 65521;
    uint32_t a = 1, b = 0;
    int index;

    // Process each byte of the data in order
    for (index = 0; index < len; ++index) {
        a = (a + data[index]) % MOD_ADLER;
        b = (b + a) % MOD_ADLER;
    }

    return (b << 16) | a;
}
bool ProtobufCodecLite::validateChecksum(const char* buf, int len)
{
    // check sum
    int32_t expectedCheckSum = asInt32(buf + len - kChecksumLen);
    int32_t checkSum = checksum(buf, len - kChecksumLen);
    return checkSum == expectedCheckSum;
}

ProtobufCodecLite::ErrorCode ProtobufCodecLite::parse(const char* buf,
    int len,
    ::google::protobuf::Message* message)
{
    ErrorCode error = kNoError;

    if (validateChecksum(buf, len)) {
        if (memcmp(buf, tag_.data(), tag_.size()) == 0) {
            // parse from buffer
            const char* data = buf + tag_.size();
            int32_t dataLen = len - kChecksumLen - static_cast<int>(tag_.size());
            if (parseFromBuffer(StringPiece(data, dataLen), message)) {
                error = kNoError;
            } else {
                error = kParseError;
            }
        } else {
            error = kUnknownMessageType;
        }
    } else {
        error = kCheckSumError;
    }

    return error;
}
