// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PodCommand.proto

#include "PodCommand.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace pds {
class podCommandDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<podCommand>
      _instance;
} _podCommand_default_instance_;
}  // namespace pds
namespace protobuf_PodCommand_2eproto {
static void InitDefaultspodCommand() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::pds::_podCommand_default_instance_;
    new (ptr) ::pds::podCommand();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::pds::podCommand::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_podCommand =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultspodCommand}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_podCommand.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pds::podCommand, _has_bits_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pds::podCommand, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pds::podCommand, controlsinterfacestate_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pds::podCommand, manualpodstate_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pds::podCommand, manualbrakenodestate_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pds::podCommand, manualmotorstate_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pds::podCommand, manuallvdcnodestate_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::pds::podCommand, automaticstatetransitions_),
  0,
  1,
  2,
  3,
  4,
  5,
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 11, sizeof(::pds::podCommand)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::pds::_podCommand_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "PodCommand.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\020PodCommand.proto\022\003pds\032\014States.proto\"\223\002"
      "\n\npodCommand\0228\n\026controlsInterfaceState\030\001"
      " \001(\0162\030.ControlsInterfaceStates\022\"\n\016manual"
      "PodState\030\002 \001(\0162\n.PodStates\022.\n\024manualBrak"
      "eNodeState\030\003 \001(\0162\020.BrakeNodeStates\022&\n\020ma"
      "nualMotorState\030\004 \001(\0162\014.MotorStates\022,\n\023ma"
      "nualLvdcNodeState\030\005 \001(\0162\017.LvdcNodeStates"
      "\022!\n\031automaticStateTransitions\030\006 \001(\010"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 315);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "PodCommand.proto", &protobuf_RegisterTypes);
  ::protobuf_States_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_PodCommand_2eproto
namespace pds {

// ===================================================================

void podCommand::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int podCommand::kControlsInterfaceStateFieldNumber;
const int podCommand::kManualPodStateFieldNumber;
const int podCommand::kManualBrakeNodeStateFieldNumber;
const int podCommand::kManualMotorStateFieldNumber;
const int podCommand::kManualLvdcNodeStateFieldNumber;
const int podCommand::kAutomaticStateTransitionsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

podCommand::podCommand()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_PodCommand_2eproto::scc_info_podCommand.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:pds.podCommand)
}
podCommand::podCommand(const podCommand& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&controlsinterfacestate_, &from.controlsinterfacestate_,
    static_cast<size_t>(reinterpret_cast<char*>(&automaticstatetransitions_) -
    reinterpret_cast<char*>(&controlsinterfacestate_)) + sizeof(automaticstatetransitions_));
  // @@protoc_insertion_point(copy_constructor:pds.podCommand)
}

void podCommand::SharedCtor() {
  ::memset(&controlsinterfacestate_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&automaticstatetransitions_) -
      reinterpret_cast<char*>(&controlsinterfacestate_)) + sizeof(automaticstatetransitions_));
}

podCommand::~podCommand() {
  // @@protoc_insertion_point(destructor:pds.podCommand)
  SharedDtor();
}

void podCommand::SharedDtor() {
}

void podCommand::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* podCommand::descriptor() {
  ::protobuf_PodCommand_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_PodCommand_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const podCommand& podCommand::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_PodCommand_2eproto::scc_info_podCommand.base);
  return *internal_default_instance();
}


void podCommand::Clear() {
// @@protoc_insertion_point(message_clear_start:pds.podCommand)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  if (cached_has_bits & 63u) {
    ::memset(&controlsinterfacestate_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&automaticstatetransitions_) -
        reinterpret_cast<char*>(&controlsinterfacestate_)) + sizeof(automaticstatetransitions_));
  }
  _has_bits_.Clear();
  _internal_metadata_.Clear();
}

bool podCommand::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:pds.podCommand)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .ControlsInterfaceStates controlsInterfaceState = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::ControlsInterfaceStates_IsValid(value)) {
            set_controlsinterfacestate(static_cast< ::ControlsInterfaceStates >(value));
          } else {
            mutable_unknown_fields()->AddVarint(
                1, static_cast< ::google::protobuf::uint64>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .PodStates manualPodState = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::PodStates_IsValid(value)) {
            set_manualpodstate(static_cast< ::PodStates >(value));
          } else {
            mutable_unknown_fields()->AddVarint(
                2, static_cast< ::google::protobuf::uint64>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .BrakeNodeStates manualBrakeNodeState = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::BrakeNodeStates_IsValid(value)) {
            set_manualbrakenodestate(static_cast< ::BrakeNodeStates >(value));
          } else {
            mutable_unknown_fields()->AddVarint(
                3, static_cast< ::google::protobuf::uint64>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .MotorStates manualMotorState = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::MotorStates_IsValid(value)) {
            set_manualmotorstate(static_cast< ::MotorStates >(value));
          } else {
            mutable_unknown_fields()->AddVarint(
                4, static_cast< ::google::protobuf::uint64>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional .LvdcNodeStates manualLvdcNodeState = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::LvdcNodeStates_IsValid(value)) {
            set_manuallvdcnodestate(static_cast< ::LvdcNodeStates >(value));
          } else {
            mutable_unknown_fields()->AddVarint(
                5, static_cast< ::google::protobuf::uint64>(value));
          }
        } else {
          goto handle_unusual;
        }
        break;
      }

      // optional bool automaticStateTransitions = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {
          set_has_automaticstatetransitions();
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &automaticstatetransitions_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:pds.podCommand)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:pds.podCommand)
  return false;
#undef DO_
}

void podCommand::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:pds.podCommand)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .ControlsInterfaceStates controlsInterfaceState = 1;
  if (cached_has_bits & 0x00000001u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->controlsinterfacestate(), output);
  }

  // optional .PodStates manualPodState = 2;
  if (cached_has_bits & 0x00000002u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->manualpodstate(), output);
  }

  // optional .BrakeNodeStates manualBrakeNodeState = 3;
  if (cached_has_bits & 0x00000004u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->manualbrakenodestate(), output);
  }

  // optional .MotorStates manualMotorState = 4;
  if (cached_has_bits & 0x00000008u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      4, this->manualmotorstate(), output);
  }

  // optional .LvdcNodeStates manualLvdcNodeState = 5;
  if (cached_has_bits & 0x00000010u) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->manuallvdcnodestate(), output);
  }

  // optional bool automaticStateTransitions = 6;
  if (cached_has_bits & 0x00000020u) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->automaticstatetransitions(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:pds.podCommand)
}

::google::protobuf::uint8* podCommand::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:pds.podCommand)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // optional .ControlsInterfaceStates controlsInterfaceState = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->controlsinterfacestate(), target);
  }

  // optional .PodStates manualPodState = 2;
  if (cached_has_bits & 0x00000002u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->manualpodstate(), target);
  }

  // optional .BrakeNodeStates manualBrakeNodeState = 3;
  if (cached_has_bits & 0x00000004u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->manualbrakenodestate(), target);
  }

  // optional .MotorStates manualMotorState = 4;
  if (cached_has_bits & 0x00000008u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      4, this->manualmotorstate(), target);
  }

  // optional .LvdcNodeStates manualLvdcNodeState = 5;
  if (cached_has_bits & 0x00000010u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      5, this->manuallvdcnodestate(), target);
  }

  // optional bool automaticStateTransitions = 6;
  if (cached_has_bits & 0x00000020u) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->automaticstatetransitions(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:pds.podCommand)
  return target;
}

size_t podCommand::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:pds.podCommand)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  if (_has_bits_[0 / 32] & 63u) {
    // optional .ControlsInterfaceStates controlsInterfaceState = 1;
    if (has_controlsinterfacestate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->controlsinterfacestate());
    }

    // optional .PodStates manualPodState = 2;
    if (has_manualpodstate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->manualpodstate());
    }

    // optional .BrakeNodeStates manualBrakeNodeState = 3;
    if (has_manualbrakenodestate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->manualbrakenodestate());
    }

    // optional .MotorStates manualMotorState = 4;
    if (has_manualmotorstate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->manualmotorstate());
    }

    // optional .LvdcNodeStates manualLvdcNodeState = 5;
    if (has_manuallvdcnodestate()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->manuallvdcnodestate());
    }

    // optional bool automaticStateTransitions = 6;
    if (has_automaticstatetransitions()) {
      total_size += 1 + 1;
    }

  }
  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void podCommand::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:pds.podCommand)
  GOOGLE_DCHECK_NE(&from, this);
  const podCommand* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const podCommand>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:pds.podCommand)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:pds.podCommand)
    MergeFrom(*source);
  }
}

void podCommand::MergeFrom(const podCommand& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:pds.podCommand)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._has_bits_[0];
  if (cached_has_bits & 63u) {
    if (cached_has_bits & 0x00000001u) {
      controlsinterfacestate_ = from.controlsinterfacestate_;
    }
    if (cached_has_bits & 0x00000002u) {
      manualpodstate_ = from.manualpodstate_;
    }
    if (cached_has_bits & 0x00000004u) {
      manualbrakenodestate_ = from.manualbrakenodestate_;
    }
    if (cached_has_bits & 0x00000008u) {
      manualmotorstate_ = from.manualmotorstate_;
    }
    if (cached_has_bits & 0x00000010u) {
      manuallvdcnodestate_ = from.manuallvdcnodestate_;
    }
    if (cached_has_bits & 0x00000020u) {
      automaticstatetransitions_ = from.automaticstatetransitions_;
    }
    _has_bits_[0] |= cached_has_bits;
  }
}

void podCommand::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:pds.podCommand)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void podCommand::CopyFrom(const podCommand& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:pds.podCommand)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool podCommand::IsInitialized() const {
  return true;
}

void podCommand::Swap(podCommand* other) {
  if (other == this) return;
  InternalSwap(other);
}
void podCommand::InternalSwap(podCommand* other) {
  using std::swap;
  swap(controlsinterfacestate_, other->controlsinterfacestate_);
  swap(manualpodstate_, other->manualpodstate_);
  swap(manualbrakenodestate_, other->manualbrakenodestate_);
  swap(manualmotorstate_, other->manualmotorstate_);
  swap(manuallvdcnodestate_, other->manuallvdcnodestate_);
  swap(automaticstatetransitions_, other->automaticstatetransitions_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata podCommand::GetMetadata() const {
  protobuf_PodCommand_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_PodCommand_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace pds
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::pds::podCommand* Arena::CreateMaybeMessage< ::pds::podCommand >(Arena* arena) {
  return Arena::CreateInternal< ::pds::podCommand >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
