// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#include "test.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace mmath {
    class SudokuRequestDefaultTypeInternal {
    public:
        ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SudokuRequest> _instance;
    } _SudokuRequest_default_instance_;
    class SudokuResponseDefaultTypeInternal {
    public:
        ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<SudokuResponse> _instance;
    } _SudokuResponse_default_instance_;
}  // namespace mmath
static void InitDefaultsscc_info_SudokuRequest_test_2eproto() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    {
        void* ptr = &::mmath::_SudokuRequest_default_instance_;
        new (ptr) ::mmath::SudokuRequest();
        ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
    }
    ::mmath::SudokuRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SudokuRequest_test_2eproto =
        {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_SudokuRequest_test_2eproto}, {}};

static void InitDefaultsscc_info_SudokuResponse_test_2eproto() {
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    {
        void* ptr = &::mmath::_SudokuResponse_default_instance_;
        new (ptr) ::mmath::SudokuResponse();
        ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
    }
    ::mmath::SudokuResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SudokuResponse_test_2eproto =
        {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_SudokuResponse_test_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_test_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_test_2eproto = nullptr;
static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* file_level_service_descriptors_test_2eproto[1];

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_test_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::mmath::SudokuRequest, _has_bits_),
        PROTOBUF_FIELD_OFFSET(::mmath::SudokuRequest, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        PROTOBUF_FIELD_OFFSET(::mmath::SudokuRequest, val_1_),
        PROTOBUF_FIELD_OFFSET(::mmath::SudokuRequest, val_2_),
        0,
        1,
        PROTOBUF_FIELD_OFFSET(::mmath::SudokuResponse, _has_bits_),
        PROTOBUF_FIELD_OFFSET(::mmath::SudokuResponse, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        PROTOBUF_FIELD_OFFSET(::mmath::SudokuResponse, solved_),
        PROTOBUF_FIELD_OFFSET(::mmath::SudokuResponse, res_),
        0,
        1,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        { 0, 7, sizeof(::mmath::SudokuRequest)},
        { 9, 16, sizeof(::mmath::SudokuResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
        reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mmath::_SudokuRequest_default_instance_),
        reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::mmath::_SudokuResponse_default_instance_),
};

const char descriptor_table_protodef_test_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
        "\n\ntest.proto\022\005mmath\"-\n\rSudokuRequest\022\r\n\005"
        "val_1\030\001 \002(\005\022\r\n\005val_2\030\002 \002(\005\"4\n\016SudokuResp"
        "onse\022\025\n\006solved\030\001 \001(\010:\005false\022\013\n\003res\030\003 \001(\005"
        "2E\n\rSudokuService\0224\n\005Solve\022\024.mmath.Sudok"
        "uRequest\032\025.mmath.SudokuResponseB\003\200\001\001"
;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_test_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_test_2eproto_sccs[2] = {
        &scc_info_SudokuRequest_test_2eproto.base,
        &scc_info_SudokuResponse_test_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_test_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_test_2eproto = {
        false, false, descriptor_table_protodef_test_2eproto, "test.proto", 196,
        &descriptor_table_test_2eproto_once, descriptor_table_test_2eproto_sccs, descriptor_table_test_2eproto_deps, 2, 0,
        schemas, file_default_instances, TableStruct_test_2eproto::offsets,
        file_level_metadata_test_2eproto, 2, file_level_enum_descriptors_test_2eproto, file_level_service_descriptors_test_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_test_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_test_2eproto)), true);
namespace mmath {

// ===================================================================

    void SudokuRequest::InitAsDefaultInstance() {
    }
    class SudokuRequest::_Internal {
    public:
        using HasBits = decltype(std::declval<SudokuRequest>()._has_bits_);
        static void set_has_val_1(HasBits* has_bits) {
            (*has_bits)[0] |= 1u;
        }
        static void set_has_val_2(HasBits* has_bits) {
            (*has_bits)[0] |= 2u;
        }
        static bool MissingRequiredFields(const HasBits& has_bits) {
            return ((has_bits[0] & 0x00000003) ^ 0x00000003) != 0;
        }
    };

    SudokuRequest::SudokuRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
            : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
        SharedCtor();
        RegisterArenaDtor(arena);
        // @@protoc_insertion_point(arena_constructor:mmath.SudokuRequest)
    }
    SudokuRequest::SudokuRequest(const SudokuRequest& from)
            : ::PROTOBUF_NAMESPACE_ID::Message(),
              _has_bits_(from._has_bits_) {
        _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
        ::memcpy(&val_1_, &from.val_1_,
                 static_cast<size_t>(reinterpret_cast<char*>(&val_2_) -
                                     reinterpret_cast<char*>(&val_1_)) + sizeof(val_2_));
        // @@protoc_insertion_point(copy_constructor:mmath.SudokuRequest)
    }

    void SudokuRequest::SharedCtor() {
        ::memset(&val_1_, 0, static_cast<size_t>(
                                     reinterpret_cast<char*>(&val_2_) -
                                     reinterpret_cast<char*>(&val_1_)) + sizeof(val_2_));
    }

    SudokuRequest::~SudokuRequest() {
        // @@protoc_insertion_point(destructor:mmath.SudokuRequest)
        SharedDtor();
        _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
    }

    void SudokuRequest::SharedDtor() {
        GOOGLE_DCHECK(GetArena() == nullptr);
    }

    void SudokuRequest::ArenaDtor(void* object) {
        SudokuRequest* _this = reinterpret_cast< SudokuRequest* >(object);
        (void)_this;
    }
    void SudokuRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
    }
    void SudokuRequest::SetCachedSize(int size) const {
        _cached_size_.Set(size);
    }
    const SudokuRequest& SudokuRequest::default_instance() {
        ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SudokuRequest_test_2eproto.base);
        return *internal_default_instance();
    }


    void SudokuRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:mmath.SudokuRequest)
        ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
        // Prevent compiler warnings about cached_has_bits being unused
        (void) cached_has_bits;

        cached_has_bits = _has_bits_[0];
        if (cached_has_bits & 0x00000003u) {
            ::memset(&val_1_, 0, static_cast<size_t>(
                                         reinterpret_cast<char*>(&val_2_) -
                                         reinterpret_cast<char*>(&val_1_)) + sizeof(val_2_));
        }
        _has_bits_.Clear();
        _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
    }

    const char* SudokuRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
        _Internal::HasBits has_bits{};
        ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
        while (!ctx->Done(&ptr)) {
            ::PROTOBUF_NAMESPACE_ID::uint32 tag;
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
            CHK_(ptr);
            switch (tag >> 3) {
                // required int32 val_1 = 1;
                case 1:
                    if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
                        _Internal::set_has_val_1(&has_bits);
                        val_1_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
                        CHK_(ptr);
                    } else goto handle_unusual;
                    continue;
                    // required int32 val_2 = 2;
                case 2:
                    if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
                        _Internal::set_has_val_2(&has_bits);
                        val_2_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
                        CHK_(ptr);
                    } else goto handle_unusual;
                    continue;
                default: {
                    handle_unusual:
                    if ((tag & 7) == 4 || tag == 0) {
                        ctx->SetLastTag(tag);
                        goto success;
                    }
                    ptr = UnknownFieldParse(tag,
                                            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
                                            ptr, ctx);
                    CHK_(ptr != nullptr);
                    continue;
                }
            }  // switch
        }  // while
        success:
        _has_bits_.Or(has_bits);
        return ptr;
        failure:
        ptr = nullptr;
        goto success;
#undef CHK_
    }

    ::PROTOBUF_NAMESPACE_ID::uint8* SudokuRequest::_InternalSerialize(
            ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
        // @@protoc_insertion_point(serialize_to_array_start:mmath.SudokuRequest)
        ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
        (void) cached_has_bits;

        cached_has_bits = _has_bits_[0];
        // required int32 val_1 = 1;
        if (cached_has_bits & 0x00000001u) {
            target = stream->EnsureSpace(target);
            target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_val_1(), target);
        }

        // required int32 val_2 = 2;
        if (cached_has_bits & 0x00000002u) {
            target = stream->EnsureSpace(target);
            target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(2, this->_internal_val_2(), target);
        }

        if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
            target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
                    _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
        }
        // @@protoc_insertion_point(serialize_to_array_end:mmath.SudokuRequest)
        return target;
    }

    size_t SudokuRequest::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:mmath.SudokuRequest)
        size_t total_size = 0;

        if (_internal_has_val_1()) {
            // required int32 val_1 = 1;
            total_size += 1 +
                          ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
                                  this->_internal_val_1());
        }

        if (_internal_has_val_2()) {
            // required int32 val_2 = 2;
            total_size += 1 +
                          ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
                                  this->_internal_val_2());
        }

        return total_size;
    }
    size_t SudokuRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mmath.SudokuRequest)
        size_t total_size = 0;

        if (((_has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
            // required int32 val_1 = 1;
            total_size += 1 +
                          ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
                                  this->_internal_val_1());

            // required int32 val_2 = 2;
            total_size += 1 +
                          ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
                                  this->_internal_val_2());

        } else {
            total_size += RequiredFieldsByteSizeFallback();
        }
        ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
        // Prevent compiler warnings about cached_has_bits being unused
        (void) cached_has_bits;

        if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
            return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
                    _internal_metadata_, total_size, &_cached_size_);
        }
        int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
        SetCachedSize(cached_size);
        return total_size;
    }

    void SudokuRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mmath.SudokuRequest)
        GOOGLE_DCHECK_NE(&from, this);
        const SudokuRequest* source =
                ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SudokuRequest>(
                        &from);
        if (source == nullptr) {
            // @@protoc_insertion_point(generalized_merge_from_cast_fail:mmath.SudokuRequest)
            ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
        } else {
            // @@protoc_insertion_point(generalized_merge_from_cast_success:mmath.SudokuRequest)
            MergeFrom(*source);
        }
    }

    void SudokuRequest::MergeFrom(const SudokuRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mmath.SudokuRequest)
        GOOGLE_DCHECK_NE(&from, this);
        _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
        ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
        (void) cached_has_bits;

        cached_has_bits = from._has_bits_[0];
        if (cached_has_bits & 0x00000003u) {
            if (cached_has_bits & 0x00000001u) {
                val_1_ = from.val_1_;
            }
            if (cached_has_bits & 0x00000002u) {
                val_2_ = from.val_2_;
            }
            _has_bits_[0] |= cached_has_bits;
        }
    }

    void SudokuRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mmath.SudokuRequest)
        if (&from == this) return;
        Clear();
        MergeFrom(from);
    }

    void SudokuRequest::CopyFrom(const SudokuRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mmath.SudokuRequest)
        if (&from == this) return;
        Clear();
        MergeFrom(from);
    }

    bool SudokuRequest::IsInitialized() const {
        if (_Internal::MissingRequiredFields(_has_bits_)) return false;
        return true;
    }

    void SudokuRequest::InternalSwap(SudokuRequest* other) {
        using std::swap;
        _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
        swap(_has_bits_[0], other->_has_bits_[0]);
        ::PROTOBUF_NAMESPACE_ID::internal::memswap<
                PROTOBUF_FIELD_OFFSET(SudokuRequest, val_2_)
                + sizeof(SudokuRequest::val_2_)
                - PROTOBUF_FIELD_OFFSET(SudokuRequest, val_1_)>(
                reinterpret_cast<char*>(&val_1_),
                reinterpret_cast<char*>(&other->val_1_));
    }

    ::PROTOBUF_NAMESPACE_ID::Metadata SudokuRequest::GetMetadata() const {
        return GetMetadataStatic();
    }


// ===================================================================

    void SudokuResponse::InitAsDefaultInstance() {
    }
    class SudokuResponse::_Internal {
    public:
        using HasBits = decltype(std::declval<SudokuResponse>()._has_bits_);
        static void set_has_solved(HasBits* has_bits) {
            (*has_bits)[0] |= 1u;
        }
        static void set_has_res(HasBits* has_bits) {
            (*has_bits)[0] |= 2u;
        }
    };

    SudokuResponse::SudokuResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
            : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
        SharedCtor();
        RegisterArenaDtor(arena);
        // @@protoc_insertion_point(arena_constructor:mmath.SudokuResponse)
    }
    SudokuResponse::SudokuResponse(const SudokuResponse& from)
            : ::PROTOBUF_NAMESPACE_ID::Message(),
              _has_bits_(from._has_bits_) {
        _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
        ::memcpy(&solved_, &from.solved_,
                 static_cast<size_t>(reinterpret_cast<char*>(&res_) -
                                     reinterpret_cast<char*>(&solved_)) + sizeof(res_));
        // @@protoc_insertion_point(copy_constructor:mmath.SudokuResponse)
    }

    void SudokuResponse::SharedCtor() {
        ::memset(&solved_, 0, static_cast<size_t>(
                                      reinterpret_cast<char*>(&res_) -
                                      reinterpret_cast<char*>(&solved_)) + sizeof(res_));
    }

    SudokuResponse::~SudokuResponse() {
        // @@protoc_insertion_point(destructor:mmath.SudokuResponse)
        SharedDtor();
        _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
    }

    void SudokuResponse::SharedDtor() {
        GOOGLE_DCHECK(GetArena() == nullptr);
    }

    void SudokuResponse::ArenaDtor(void* object) {
        SudokuResponse* _this = reinterpret_cast< SudokuResponse* >(object);
        (void)_this;
    }
    void SudokuResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
    }
    void SudokuResponse::SetCachedSize(int size) const {
        _cached_size_.Set(size);
    }
    const SudokuResponse& SudokuResponse::default_instance() {
        ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_SudokuResponse_test_2eproto.base);
        return *internal_default_instance();
    }


    void SudokuResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:mmath.SudokuResponse)
        ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
        // Prevent compiler warnings about cached_has_bits being unused
        (void) cached_has_bits;

        cached_has_bits = _has_bits_[0];
        if (cached_has_bits & 0x00000003u) {
            ::memset(&solved_, 0, static_cast<size_t>(
                                          reinterpret_cast<char*>(&res_) -
                                          reinterpret_cast<char*>(&solved_)) + sizeof(res_));
        }
        _has_bits_.Clear();
        _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
    }

    const char* SudokuResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
        _Internal::HasBits has_bits{};
        ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
        while (!ctx->Done(&ptr)) {
            ::PROTOBUF_NAMESPACE_ID::uint32 tag;
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
            CHK_(ptr);
            switch (tag >> 3) {
                // optional bool solved = 1 [default = false];
                case 1:
                    if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
                        _Internal::set_has_solved(&has_bits);
                        solved_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
                        CHK_(ptr);
                    } else goto handle_unusual;
                    continue;
                    // optional int32 res = 3;
                case 3:
                    if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 24)) {
                        _Internal::set_has_res(&has_bits);
                        res_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
                        CHK_(ptr);
                    } else goto handle_unusual;
                    continue;
                default: {
                    handle_unusual:
                    if ((tag & 7) == 4 || tag == 0) {
                        ctx->SetLastTag(tag);
                        goto success;
                    }
                    ptr = UnknownFieldParse(tag,
                                            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
                                            ptr, ctx);
                    CHK_(ptr != nullptr);
                    continue;
                }
            }  // switch
        }  // while
        success:
        _has_bits_.Or(has_bits);
        return ptr;
        failure:
        ptr = nullptr;
        goto success;
#undef CHK_
    }

    ::PROTOBUF_NAMESPACE_ID::uint8* SudokuResponse::_InternalSerialize(
            ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
        // @@protoc_insertion_point(serialize_to_array_start:mmath.SudokuResponse)
        ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
        (void) cached_has_bits;

        cached_has_bits = _has_bits_[0];
        // optional bool solved = 1 [default = false];
        if (cached_has_bits & 0x00000001u) {
            target = stream->EnsureSpace(target);
            target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(1, this->_internal_solved(), target);
        }

        // optional int32 res = 3;
        if (cached_has_bits & 0x00000002u) {
            target = stream->EnsureSpace(target);
            target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(3, this->_internal_res(), target);
        }

        if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
            target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
                    _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
        }
        // @@protoc_insertion_point(serialize_to_array_end:mmath.SudokuResponse)
        return target;
    }

    size_t SudokuResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:mmath.SudokuResponse)
        size_t total_size = 0;

        ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
        // Prevent compiler warnings about cached_has_bits being unused
        (void) cached_has_bits;

        cached_has_bits = _has_bits_[0];
        if (cached_has_bits & 0x00000003u) {
            // optional bool solved = 1 [default = false];
            if (cached_has_bits & 0x00000001u) {
                total_size += 1 + 1;
            }

            // optional int32 res = 3;
            if (cached_has_bits & 0x00000002u) {
                total_size += 1 +
                              ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32Size(
                                      this->_internal_res());
            }

        }
        if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
            return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
                    _internal_metadata_, total_size, &_cached_size_);
        }
        int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
        SetCachedSize(cached_size);
        return total_size;
    }

    void SudokuResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:mmath.SudokuResponse)
        GOOGLE_DCHECK_NE(&from, this);
        const SudokuResponse* source =
                ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<SudokuResponse>(
                        &from);
        if (source == nullptr) {
            // @@protoc_insertion_point(generalized_merge_from_cast_fail:mmath.SudokuResponse)
            ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
        } else {
            // @@protoc_insertion_point(generalized_merge_from_cast_success:mmath.SudokuResponse)
            MergeFrom(*source);
        }
    }

    void SudokuResponse::MergeFrom(const SudokuResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:mmath.SudokuResponse)
        GOOGLE_DCHECK_NE(&from, this);
        _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
        ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
        (void) cached_has_bits;

        cached_has_bits = from._has_bits_[0];
        if (cached_has_bits & 0x00000003u) {
            if (cached_has_bits & 0x00000001u) {
                solved_ = from.solved_;
            }
            if (cached_has_bits & 0x00000002u) {
                res_ = from.res_;
            }
            _has_bits_[0] |= cached_has_bits;
        }
    }

    void SudokuResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:mmath.SudokuResponse)
        if (&from == this) return;
        Clear();
        MergeFrom(from);
    }

    void SudokuResponse::CopyFrom(const SudokuResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:mmath.SudokuResponse)
        if (&from == this) return;
        Clear();
        MergeFrom(from);
    }

    bool SudokuResponse::IsInitialized() const {
        return true;
    }

    void SudokuResponse::InternalSwap(SudokuResponse* other) {
        using std::swap;
        _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
        swap(_has_bits_[0], other->_has_bits_[0]);
        ::PROTOBUF_NAMESPACE_ID::internal::memswap<
                PROTOBUF_FIELD_OFFSET(SudokuResponse, res_)
                + sizeof(SudokuResponse::res_)
                - PROTOBUF_FIELD_OFFSET(SudokuResponse, solved_)>(
                reinterpret_cast<char*>(&solved_),
                reinterpret_cast<char*>(&other->solved_));
    }

    ::PROTOBUF_NAMESPACE_ID::Metadata SudokuResponse::GetMetadata() const {
        return GetMetadataStatic();
    }


// ===================================================================

    SudokuService::~SudokuService() {}

    const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* SudokuService::descriptor() {
        ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_test_2eproto);
        return file_level_service_descriptors_test_2eproto[0];
    }

    const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* SudokuService::GetDescriptor() {
        return descriptor();
    }

    void SudokuService::Solve(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                              const ::mmath::SudokuRequest*,
                              ::mmath::SudokuResponse*,
                              ::google::protobuf::Closure* done) {
        controller->SetFailed("Method Solve() not implemented.");
        done->Run();
    }

    void SudokuService::CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                                   ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                                   const ::PROTOBUF_NAMESPACE_ID::Message* request,
                                   ::PROTOBUF_NAMESPACE_ID::Message* response,
                                   ::google::protobuf::Closure* done) {
        GOOGLE_DCHECK_EQ(method->service(), file_level_service_descriptors_test_2eproto[0]);
        switch(method->index()) {
            case 0:
                Solve(controller,
                      ::PROTOBUF_NAMESPACE_ID::internal::DownCast<const ::mmath::SudokuRequest*>(
                              request),
                      ::PROTOBUF_NAMESPACE_ID::internal::DownCast<::mmath::SudokuResponse*>(
                              response),
                      done);
                break;
            default:
                GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
                break;
        }
    }

    const ::PROTOBUF_NAMESPACE_ID::Message& SudokuService::GetRequestPrototype(
            const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
        GOOGLE_DCHECK_EQ(method->service(), descriptor());
        switch(method->index()) {
            case 0:
                return ::mmath::SudokuRequest::default_instance();
            default:
                GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
                return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
                        ->GetPrototype(method->input_type());
        }
    }

    const ::PROTOBUF_NAMESPACE_ID::Message& SudokuService::GetResponsePrototype(
            const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const {
        GOOGLE_DCHECK_EQ(method->service(), descriptor());
        switch(method->index()) {
            case 0:
                return ::mmath::SudokuResponse::default_instance();
            default:
                GOOGLE_LOG(FATAL) << "Bad method index; this should never happen.";
                return *::PROTOBUF_NAMESPACE_ID::MessageFactory::generated_factory()
                        ->GetPrototype(method->output_type());
        }
    }

    SudokuService_Stub::SudokuService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel)
            : channel_(channel), owns_channel_(false) {}
    SudokuService_Stub::SudokuService_Stub(
            ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
            ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership)
            : channel_(channel),
              owns_channel_(ownership == ::PROTOBUF_NAMESPACE_ID::Service::STUB_OWNS_CHANNEL) {}
    SudokuService_Stub::~SudokuService_Stub() {
        if (owns_channel_) delete channel_;
    }

    void SudokuService_Stub::Solve(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                                   const ::mmath::SudokuRequest* request,
                                   ::mmath::SudokuResponse* response,
                                   ::google::protobuf::Closure* done) {
        channel_->CallMethod(descriptor()->method(0),
                             controller, request, response, done);
    }

// @@protoc_insertion_point(namespace_scope)
}  // namespace mmath
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::mmath::SudokuRequest* Arena::CreateMaybeMessage< ::mmath::SudokuRequest >(Arena* arena) {
    return Arena::CreateMessageInternal< ::mmath::SudokuRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::mmath::SudokuResponse* Arena::CreateMaybeMessage< ::mmath::SudokuResponse >(Arena* arena) {
    return Arena::CreateMessageInternal< ::mmath::SudokuResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
