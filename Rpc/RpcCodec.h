#ifndef QE_NET_PROTORPC_RPCCODEC_H
#define QE_NET_PROTORPC_RPCCODEC_H
//--------------------------------------------------
#include "ProtobufCodec.h"

namespace QE
{
namespace net
{

class TcpConnection;
typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;

class RpcMessage;
typedef std::shared_ptr<RpcMessage> RpcMessagePtr;
extern const char rpctag[];// = "RPC0";

// wire format
//
// Field     Length  Content
//
// size      4-byte  N+8
// "RPC0"    4-byte
// payload   N-byte
// checksum  4-byte  adler32 of "RPC0"+payload
//

typedef ProtobufCodecLiteT<RpcMessage, rpctag> RpcCodec;

}  // namespace net
}  // namespace muduo



//--------------------------------------------------
#endif