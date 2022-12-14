// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_test_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_test_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_test_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
    class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_test_2eproto {
    static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
    static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
    static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
    static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
    static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
    static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_test_2eproto;
namespace mmath {
    class SudokuRequest;
    class SudokuRequestDefaultTypeInternal;
    extern SudokuRequestDefaultTypeInternal _SudokuRequest_default_instance_;
    class SudokuResponse;
    class SudokuResponseDefaultTypeInternal;
    extern SudokuResponseDefaultTypeInternal _SudokuResponse_default_instance_;
}  // namespace mmath
PROTOBUF_NAMESPACE_OPEN
template<> ::mmath::SudokuRequest* Arena::CreateMaybeMessage<::mmath::SudokuRequest>(Arena*);
template<> ::mmath::SudokuResponse* Arena::CreateMaybeMessage<::mmath::SudokuResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace mmath {

// ===================================================================

    class SudokuRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mmath.SudokuRequest) */ {
    public:
    inline SudokuRequest() : SudokuRequest(nullptr) {};
    virtual ~SudokuRequest();

    SudokuRequest(const SudokuRequest& from);
    SudokuRequest(SudokuRequest&& from) noexcept
    : SudokuRequest() {
        *this = ::std::move(from);
    }

    inline SudokuRequest& operator=(const SudokuRequest& from) {
        CopyFrom(from);
        return *this;
    }
    inline SudokuRequest& operator=(SudokuRequest&& from) noexcept {
    if (GetArena() == from.GetArena()) {
    if (this != &from) InternalSwap(&from);
} else {
CopyFrom(from);
}
return *this;
}

inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
}
inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
}
static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
}
static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
}
static const SudokuRequest& default_instance();

static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
static inline const SudokuRequest* internal_default_instance() {
    return reinterpret_cast<const SudokuRequest*>(
            &_SudokuRequest_default_instance_);
}
static constexpr int kIndexInFileMessages =
        0;

friend void swap(SudokuRequest& a, SudokuRequest& b) {
    a.Swap(&b);
}
inline void Swap(SudokuRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
        InternalSwap(other);
    } else {
        ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
}
void UnsafeArenaSwap(SudokuRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
}

// implements Message ----------------------------------------------

inline SudokuRequest* New() const final {
return CreateMaybeMessage<SudokuRequest>(nullptr);
}

SudokuRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
return CreateMaybeMessage<SudokuRequest>(arena);
}
void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
void CopyFrom(const SudokuRequest& from);
void MergeFrom(const SudokuRequest& from);
PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
bool IsInitialized() const final;

size_t ByteSizeLong() const final;
const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
        ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
int GetCachedSize() const final { return _cached_size_.Get(); }

private:
inline void SharedCtor();
inline void SharedDtor();
void SetCachedSize(int size) const final;
void InternalSwap(SudokuRequest* other);
friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mmath.SudokuRequest";
}
protected:
explicit SudokuRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
private:
static void ArenaDtor(void* object);
inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
public:

::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
private:
static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_test_2eproto);
    return ::descriptor_table_test_2eproto.file_level_metadata[kIndexInFileMessages];
}

public:

// nested types ----------------------------------------------------

// accessors -------------------------------------------------------

enum : int {
    kVal1FieldNumber = 1,
    kVal2FieldNumber = 2,
};
// required int32 val_1 = 1;
bool has_val_1() const;
private:
bool _internal_has_val_1() const;
public:
void clear_val_1();
::PROTOBUF_NAMESPACE_ID::int32 val_1() const;
void set_val_1(::PROTOBUF_NAMESPACE_ID::int32 value);
private:
::PROTOBUF_NAMESPACE_ID::int32 _internal_val_1() const;
void _internal_set_val_1(::PROTOBUF_NAMESPACE_ID::int32 value);
public:

// required int32 val_2 = 2;
bool has_val_2() const;
private:
bool _internal_has_val_2() const;
public:
void clear_val_2();
::PROTOBUF_NAMESPACE_ID::int32 val_2() const;
void set_val_2(::PROTOBUF_NAMESPACE_ID::int32 value);
private:
::PROTOBUF_NAMESPACE_ID::int32 _internal_val_2() const;
void _internal_set_val_2(::PROTOBUF_NAMESPACE_ID::int32 value);
public:

// @@protoc_insertion_point(class_scope:mmath.SudokuRequest)
private:
class _Internal;

// helper for ByteSizeLong()
size_t RequiredFieldsByteSizeFallback() const;

template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
typedef void InternalArenaConstructable_;
typedef void DestructorSkippable_;
::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
::PROTOBUF_NAMESPACE_ID::int32 val_1_;
::PROTOBUF_NAMESPACE_ID::int32 val_2_;
friend struct ::TableStruct_test_2eproto;
};
// -------------------------------------------------------------------

class SudokuResponse PROTOBUF_FINAL :
public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:mmath.SudokuResponse) */ {
public:
inline SudokuResponse() : SudokuResponse(nullptr) {};
virtual ~SudokuResponse();

SudokuResponse(const SudokuResponse& from);
SudokuResponse(SudokuResponse&& from) noexcept
: SudokuResponse() {
    *this = ::std::move(from);
}

inline SudokuResponse& operator=(const SudokuResponse& from) {
    CopyFrom(from);
    return *this;
}
inline SudokuResponse& operator=(SudokuResponse&& from) noexcept {
if (GetArena() == from.GetArena()) {
if (this != &from) InternalSwap(&from);
} else {
CopyFrom(from);
}
return *this;
}

inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
}
inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
}
static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
}
static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
}
static const SudokuResponse& default_instance();

static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
static inline const SudokuResponse* internal_default_instance() {
    return reinterpret_cast<const SudokuResponse*>(
            &_SudokuResponse_default_instance_);
}
static constexpr int kIndexInFileMessages =
        1;

friend void swap(SudokuResponse& a, SudokuResponse& b) {
    a.Swap(&b);
}
inline void Swap(SudokuResponse* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
        InternalSwap(other);
    } else {
        ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
}
void UnsafeArenaSwap(SudokuResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
}

// implements Message ----------------------------------------------

inline SudokuResponse* New() const final {
return CreateMaybeMessage<SudokuResponse>(nullptr);
}

SudokuResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
return CreateMaybeMessage<SudokuResponse>(arena);
}
void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
void CopyFrom(const SudokuResponse& from);
void MergeFrom(const SudokuResponse& from);
PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
bool IsInitialized() const final;

size_t ByteSizeLong() const final;
const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
        ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
int GetCachedSize() const final { return _cached_size_.Get(); }

private:
inline void SharedCtor();
inline void SharedDtor();
void SetCachedSize(int size) const final;
void InternalSwap(SudokuResponse* other);
friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "mmath.SudokuResponse";
}
protected:
explicit SudokuResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
private:
static void ArenaDtor(void* object);
inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
public:

::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
private:
static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_test_2eproto);
    return ::descriptor_table_test_2eproto.file_level_metadata[kIndexInFileMessages];
}

public:

// nested types ----------------------------------------------------

// accessors -------------------------------------------------------

enum : int {
    kSolvedFieldNumber = 1,
    kResFieldNumber = 3,
};
// optional bool solved = 1 [default = false];
bool has_solved() const;
private:
bool _internal_has_solved() const;
public:
void clear_solved();
bool solved() const;
void set_solved(bool value);
private:
bool _internal_solved() const;
void _internal_set_solved(bool value);
public:

// optional int32 res = 3;
bool has_res() const;
private:
bool _internal_has_res() const;
public:
void clear_res();
::PROTOBUF_NAMESPACE_ID::int32 res() const;
void set_res(::PROTOBUF_NAMESPACE_ID::int32 value);
private:
::PROTOBUF_NAMESPACE_ID::int32 _internal_res() const;
void _internal_set_res(::PROTOBUF_NAMESPACE_ID::int32 value);
public:

// @@protoc_insertion_point(class_scope:mmath.SudokuResponse)
private:
class _Internal;

template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
typedef void InternalArenaConstructable_;
typedef void DestructorSkippable_;
::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
bool solved_;
::PROTOBUF_NAMESPACE_ID::int32 res_;
friend struct ::TableStruct_test_2eproto;
};
// ===================================================================

class SudokuService_Stub;

class SudokuService : public ::PROTOBUF_NAMESPACE_ID::Service {
protected:
    // This class should be treated as an abstract interface.
    inline SudokuService() {};
public:
    virtual ~SudokuService();

    typedef SudokuService_Stub Stub;

    static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* descriptor();

    virtual void Solve(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::mmath::SudokuRequest* request,
                       ::mmath::SudokuResponse* response,
                       ::google::protobuf::Closure* done);

    // implements Service ----------------------------------------------

    const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* GetDescriptor();
    void CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                    ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                    const ::PROTOBUF_NAMESPACE_ID::Message* request,
                    ::PROTOBUF_NAMESPACE_ID::Message* response,
                    ::google::protobuf::Closure* done);
    const ::PROTOBUF_NAMESPACE_ID::Message& GetRequestPrototype(
            const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;
    const ::PROTOBUF_NAMESPACE_ID::Message& GetResponsePrototype(
            const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;

private:
    GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(SudokuService);
};

class SudokuService_Stub : public SudokuService {
public:
    SudokuService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
    SudokuService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                       ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
    ~SudokuService_Stub();

    inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }

    // implements SudokuService ------------------------------------------

    void Solve(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
               const ::mmath::SudokuRequest* request,
               ::mmath::SudokuResponse* response,
               ::google::protobuf::Closure* done);
private:
    ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
    bool owns_channel_;
    GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(SudokuService_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// SudokuRequest

// required int32 val_1 = 1;
inline bool SudokuRequest::_internal_has_val_1() const {
    bool value = (_has_bits_[0] & 0x00000001u) != 0;
    return value;
}
inline bool SudokuRequest::has_val_1() const {
    return _internal_has_val_1();
}
inline void SudokuRequest::clear_val_1() {
    val_1_ = 0;
    _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SudokuRequest::_internal_val_1() const {
    return val_1_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SudokuRequest::val_1() const {
    // @@protoc_insertion_point(field_get:mmath.SudokuRequest.val_1)
    return _internal_val_1();
}
inline void SudokuRequest::_internal_set_val_1(::PROTOBUF_NAMESPACE_ID::int32 value) {
    _has_bits_[0] |= 0x00000001u;
    val_1_ = value;
}
inline void SudokuRequest::set_val_1(::PROTOBUF_NAMESPACE_ID::int32 value) {
    _internal_set_val_1(value);
    // @@protoc_insertion_point(field_set:mmath.SudokuRequest.val_1)
}

// required int32 val_2 = 2;
inline bool SudokuRequest::_internal_has_val_2() const {
    bool value = (_has_bits_[0] & 0x00000002u) != 0;
    return value;
}
inline bool SudokuRequest::has_val_2() const {
    return _internal_has_val_2();
}
inline void SudokuRequest::clear_val_2() {
    val_2_ = 0;
    _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SudokuRequest::_internal_val_2() const {
    return val_2_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SudokuRequest::val_2() const {
    // @@protoc_insertion_point(field_get:mmath.SudokuRequest.val_2)
    return _internal_val_2();
}
inline void SudokuRequest::_internal_set_val_2(::PROTOBUF_NAMESPACE_ID::int32 value) {
    _has_bits_[0] |= 0x00000002u;
    val_2_ = value;
}
inline void SudokuRequest::set_val_2(::PROTOBUF_NAMESPACE_ID::int32 value) {
    _internal_set_val_2(value);
    // @@protoc_insertion_point(field_set:mmath.SudokuRequest.val_2)
}

// -------------------------------------------------------------------

// SudokuResponse

// optional bool solved = 1 [default = false];
inline bool SudokuResponse::_internal_has_solved() const {
    bool value = (_has_bits_[0] & 0x00000001u) != 0;
    return value;
}
inline bool SudokuResponse::has_solved() const {
    return _internal_has_solved();
}
inline void SudokuResponse::clear_solved() {
    solved_ = false;
    _has_bits_[0] &= ~0x00000001u;
}
inline bool SudokuResponse::_internal_solved() const {
    return solved_;
}
inline bool SudokuResponse::solved() const {
    // @@protoc_insertion_point(field_get:mmath.SudokuResponse.solved)
    return _internal_solved();
}
inline void SudokuResponse::_internal_set_solved(bool value) {
    _has_bits_[0] |= 0x00000001u;
    solved_ = value;
}
inline void SudokuResponse::set_solved(bool value) {
    _internal_set_solved(value);
    // @@protoc_insertion_point(field_set:mmath.SudokuResponse.solved)
}

// optional int32 res = 3;
inline bool SudokuResponse::_internal_has_res() const {
    bool value = (_has_bits_[0] & 0x00000002u) != 0;
    return value;
}
inline bool SudokuResponse::has_res() const {
    return _internal_has_res();
}
inline void SudokuResponse::clear_res() {
    res_ = 0;
    _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SudokuResponse::_internal_res() const {
    return res_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 SudokuResponse::res() const {
    // @@protoc_insertion_point(field_get:mmath.SudokuResponse.res)
    return _internal_res();
}
inline void SudokuResponse::_internal_set_res(::PROTOBUF_NAMESPACE_ID::int32 value) {
    _has_bits_[0] |= 0x00000002u;
    res_ = value;
}
inline void SudokuResponse::set_res(::PROTOBUF_NAMESPACE_ID::int32 value) {
    _internal_set_res(value);
    // @@protoc_insertion_point(field_set:mmath.SudokuResponse.res)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace mmath

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_test_2eproto
