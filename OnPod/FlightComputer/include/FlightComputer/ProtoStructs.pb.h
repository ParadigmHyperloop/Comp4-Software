// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ProtoStructs.proto

#ifndef PROTOBUF_INCLUDED_ProtoStructs_2eproto
#define PROTOBUF_INCLUDED_ProtoStructs_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_ProtoStructs_2eproto 

namespace protobuf_ProtoStructs_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_ProtoStructs_2eproto
namespace fc {
class brakeNodeData;
class brakeNodeDataDefaultTypeInternal;
extern brakeNodeDataDefaultTypeInternal _brakeNodeData_default_instance_;
}  // namespace fc
namespace google {
namespace protobuf {
template<> ::fc::brakeNodeData* Arena::CreateMaybeMessage<::fc::brakeNodeData>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace fc {

enum brakeNodeData_breakNodeState {
  brakeNodeData_breakNodeState_bnsBooting = 0,
  brakeNodeData_breakNodeState_bnsStandby = 1,
  brakeNodeData_breakNodeState_bnsArming = 2,
  brakeNodeData_breakNodeState_bnsArmed = 3,
  brakeNodeData_breakNodeState_bnsFlight = 4,
  brakeNodeData_breakNodeState_bnsBraking = 5,
  brakeNodeData_breakNodeState_bnsVenting = 6,
  brakeNodeData_breakNodeState_bnsRetrieval = 7,
  brakeNodeData_breakNodeState_bnsError = 8
};
bool brakeNodeData_breakNodeState_IsValid(int value);
const brakeNodeData_breakNodeState brakeNodeData_breakNodeState_breakNodeState_MIN = brakeNodeData_breakNodeState_bnsBooting;
const brakeNodeData_breakNodeState brakeNodeData_breakNodeState_breakNodeState_MAX = brakeNodeData_breakNodeState_bnsError;
const int brakeNodeData_breakNodeState_breakNodeState_ARRAYSIZE = brakeNodeData_breakNodeState_breakNodeState_MAX + 1;

const ::google::protobuf::EnumDescriptor* brakeNodeData_breakNodeState_descriptor();
inline const ::std::string& brakeNodeData_breakNodeState_Name(brakeNodeData_breakNodeState value) {
  return ::google::protobuf::internal::NameOfEnum(
    brakeNodeData_breakNodeState_descriptor(), value);
}
inline bool brakeNodeData_breakNodeState_Parse(
    const ::std::string& name, brakeNodeData_breakNodeState* value) {
  return ::google::protobuf::internal::ParseNamedEnum<brakeNodeData_breakNodeState>(
    brakeNodeData_breakNodeState_descriptor(), name, value);
}
// ===================================================================

class brakeNodeData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:fc.brakeNodeData) */ {
 public:
  brakeNodeData();
  virtual ~brakeNodeData();

  brakeNodeData(const brakeNodeData& from);

  inline brakeNodeData& operator=(const brakeNodeData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  brakeNodeData(brakeNodeData&& from) noexcept
    : brakeNodeData() {
    *this = ::std::move(from);
  }

  inline brakeNodeData& operator=(brakeNodeData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const brakeNodeData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const brakeNodeData* internal_default_instance() {
    return reinterpret_cast<const brakeNodeData*>(
               &_brakeNodeData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(brakeNodeData* other);
  friend void swap(brakeNodeData& a, brakeNodeData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline brakeNodeData* New() const final {
    return CreateMaybeMessage<brakeNodeData>(NULL);
  }

  brakeNodeData* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<brakeNodeData>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const brakeNodeData& from);
  void MergeFrom(const brakeNodeData& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(brakeNodeData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef brakeNodeData_breakNodeState breakNodeState;
  static const breakNodeState bnsBooting =
    brakeNodeData_breakNodeState_bnsBooting;
  static const breakNodeState bnsStandby =
    brakeNodeData_breakNodeState_bnsStandby;
  static const breakNodeState bnsArming =
    brakeNodeData_breakNodeState_bnsArming;
  static const breakNodeState bnsArmed =
    brakeNodeData_breakNodeState_bnsArmed;
  static const breakNodeState bnsFlight =
    brakeNodeData_breakNodeState_bnsFlight;
  static const breakNodeState bnsBraking =
    brakeNodeData_breakNodeState_bnsBraking;
  static const breakNodeState bnsVenting =
    brakeNodeData_breakNodeState_bnsVenting;
  static const breakNodeState bnsRetrieval =
    brakeNodeData_breakNodeState_bnsRetrieval;
  static const breakNodeState bnsError =
    brakeNodeData_breakNodeState_bnsError;
  static inline bool breakNodeState_IsValid(int value) {
    return brakeNodeData_breakNodeState_IsValid(value);
  }
  static const breakNodeState breakNodeState_MIN =
    brakeNodeData_breakNodeState_breakNodeState_MIN;
  static const breakNodeState breakNodeState_MAX =
    brakeNodeData_breakNodeState_breakNodeState_MAX;
  static const int breakNodeState_ARRAYSIZE =
    brakeNodeData_breakNodeState_breakNodeState_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  breakNodeState_descriptor() {
    return brakeNodeData_breakNodeState_descriptor();
  }
  static inline const ::std::string& breakNodeState_Name(breakNodeState value) {
    return brakeNodeData_breakNodeState_Name(value);
  }
  static inline bool breakNodeState_Parse(const ::std::string& name,
      breakNodeState* value) {
    return brakeNodeData_breakNodeState_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // required int32 id = 1;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // optional bool sol1 = 2;
  bool has_sol1() const;
  void clear_sol1();
  static const int kSol1FieldNumber = 2;
  bool sol1() const;
  void set_sol1(bool value);

  // optional bool sol2 = 3;
  bool has_sol2() const;
  void clear_sol2();
  static const int kSol2FieldNumber = 3;
  bool sol2() const;
  void set_sol2(bool value);

  // optional bool sol3 = 4;
  bool has_sol3() const;
  void clear_sol3();
  static const int kSol3FieldNumber = 4;
  bool sol3() const;
  void set_sol3(bool value);

  // optional bool sol4 = 5;
  bool has_sol4() const;
  void clear_sol4();
  static const int kSol4FieldNumber = 5;
  bool sol4() const;
  void set_sol4(bool value);

  // optional bool sol5 = 6;
  bool has_sol5() const;
  void clear_sol5();
  static const int kSol5FieldNumber = 6;
  bool sol5() const;
  void set_sol5(bool value);

  // optional bool sol6 = 7;
  bool has_sol6() const;
  void clear_sol6();
  static const int kSol6FieldNumber = 7;
  bool sol6() const;
  void set_sol6(bool value);

  // optional int32 hp = 8;
  bool has_hp() const;
  void clear_hp();
  static const int kHpFieldNumber = 8;
  ::google::protobuf::int32 hp() const;
  void set_hp(::google::protobuf::int32 value);

  // optional int32 lp1 = 9;
  bool has_lp1() const;
  void clear_lp1();
  static const int kLp1FieldNumber = 9;
  ::google::protobuf::int32 lp1() const;
  void set_lp1(::google::protobuf::int32 value);

  // optional int32 lp2 = 10;
  bool has_lp2() const;
  void clear_lp2();
  static const int kLp2FieldNumber = 10;
  ::google::protobuf::int32 lp2() const;
  void set_lp2(::google::protobuf::int32 value);

  // optional int32 lp3 = 11;
  bool has_lp3() const;
  void clear_lp3();
  static const int kLp3FieldNumber = 11;
  ::google::protobuf::int32 lp3() const;
  void set_lp3(::google::protobuf::int32 value);

  // optional int32 lp4 = 12;
  bool has_lp4() const;
  void clear_lp4();
  static const int kLp4FieldNumber = 12;
  ::google::protobuf::int32 lp4() const;
  void set_lp4(::google::protobuf::int32 value);

  // optional int32 temp = 13;
  bool has_temp() const;
  void clear_temp();
  static const int kTempFieldNumber = 13;
  ::google::protobuf::int32 temp() const;
  void set_temp(::google::protobuf::int32 value);

  // optional .fc.brakeNodeData.breakNodeState state = 14;
  bool has_state() const;
  void clear_state();
  static const int kStateFieldNumber = 14;
  ::fc::brakeNodeData_breakNodeState state() const;
  void set_state(::fc::brakeNodeData_breakNodeState value);

  // @@protoc_insertion_point(class_scope:fc.brakeNodeData)
 private:
  void set_has_id();
  void clear_has_id();
  void set_has_state();
  void clear_has_state();
  void set_has_sol1();
  void clear_has_sol1();
  void set_has_sol2();
  void clear_has_sol2();
  void set_has_sol3();
  void clear_has_sol3();
  void set_has_sol4();
  void clear_has_sol4();
  void set_has_sol5();
  void clear_has_sol5();
  void set_has_sol6();
  void clear_has_sol6();
  void set_has_hp();
  void clear_has_hp();
  void set_has_lp1();
  void clear_has_lp1();
  void set_has_lp2();
  void clear_has_lp2();
  void set_has_lp3();
  void clear_has_lp3();
  void set_has_lp4();
  void clear_has_lp4();
  void set_has_temp();
  void clear_has_temp();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::int32 id_;
  bool sol1_;
  bool sol2_;
  bool sol3_;
  bool sol4_;
  bool sol5_;
  bool sol6_;
  ::google::protobuf::int32 hp_;
  ::google::protobuf::int32 lp1_;
  ::google::protobuf::int32 lp2_;
  ::google::protobuf::int32 lp3_;
  ::google::protobuf::int32 lp4_;
  ::google::protobuf::int32 temp_;
  int state_;
  friend struct ::protobuf_ProtoStructs_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// brakeNodeData

// required int32 id = 1;
inline bool brakeNodeData::has_id() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void brakeNodeData::set_has_id() {
  _has_bits_[0] |= 0x00000001u;
}
inline void brakeNodeData::clear_has_id() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void brakeNodeData::clear_id() {
  id_ = 0;
  clear_has_id();
}
inline ::google::protobuf::int32 brakeNodeData::id() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.id)
  return id_;
}
inline void brakeNodeData::set_id(::google::protobuf::int32 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.id)
}

// optional .fc.brakeNodeData.breakNodeState state = 14;
inline bool brakeNodeData::has_state() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void brakeNodeData::set_has_state() {
  _has_bits_[0] |= 0x00002000u;
}
inline void brakeNodeData::clear_has_state() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void brakeNodeData::clear_state() {
  state_ = 0;
  clear_has_state();
}
inline ::fc::brakeNodeData_breakNodeState brakeNodeData::state() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.state)
  return static_cast< ::fc::brakeNodeData_breakNodeState >(state_);
}
inline void brakeNodeData::set_state(::fc::brakeNodeData_breakNodeState value) {
  assert(::fc::brakeNodeData_breakNodeState_IsValid(value));
  set_has_state();
  state_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.state)
}

// optional bool sol1 = 2;
inline bool brakeNodeData::has_sol1() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void brakeNodeData::set_has_sol1() {
  _has_bits_[0] |= 0x00000002u;
}
inline void brakeNodeData::clear_has_sol1() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void brakeNodeData::clear_sol1() {
  sol1_ = false;
  clear_has_sol1();
}
inline bool brakeNodeData::sol1() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.sol1)
  return sol1_;
}
inline void brakeNodeData::set_sol1(bool value) {
  set_has_sol1();
  sol1_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.sol1)
}

// optional bool sol2 = 3;
inline bool brakeNodeData::has_sol2() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void brakeNodeData::set_has_sol2() {
  _has_bits_[0] |= 0x00000004u;
}
inline void brakeNodeData::clear_has_sol2() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void brakeNodeData::clear_sol2() {
  sol2_ = false;
  clear_has_sol2();
}
inline bool brakeNodeData::sol2() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.sol2)
  return sol2_;
}
inline void brakeNodeData::set_sol2(bool value) {
  set_has_sol2();
  sol2_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.sol2)
}

// optional bool sol3 = 4;
inline bool brakeNodeData::has_sol3() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void brakeNodeData::set_has_sol3() {
  _has_bits_[0] |= 0x00000008u;
}
inline void brakeNodeData::clear_has_sol3() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void brakeNodeData::clear_sol3() {
  sol3_ = false;
  clear_has_sol3();
}
inline bool brakeNodeData::sol3() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.sol3)
  return sol3_;
}
inline void brakeNodeData::set_sol3(bool value) {
  set_has_sol3();
  sol3_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.sol3)
}

// optional bool sol4 = 5;
inline bool brakeNodeData::has_sol4() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void brakeNodeData::set_has_sol4() {
  _has_bits_[0] |= 0x00000010u;
}
inline void brakeNodeData::clear_has_sol4() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void brakeNodeData::clear_sol4() {
  sol4_ = false;
  clear_has_sol4();
}
inline bool brakeNodeData::sol4() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.sol4)
  return sol4_;
}
inline void brakeNodeData::set_sol4(bool value) {
  set_has_sol4();
  sol4_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.sol4)
}

// optional bool sol5 = 6;
inline bool brakeNodeData::has_sol5() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void brakeNodeData::set_has_sol5() {
  _has_bits_[0] |= 0x00000020u;
}
inline void brakeNodeData::clear_has_sol5() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void brakeNodeData::clear_sol5() {
  sol5_ = false;
  clear_has_sol5();
}
inline bool brakeNodeData::sol5() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.sol5)
  return sol5_;
}
inline void brakeNodeData::set_sol5(bool value) {
  set_has_sol5();
  sol5_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.sol5)
}

// optional bool sol6 = 7;
inline bool brakeNodeData::has_sol6() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void brakeNodeData::set_has_sol6() {
  _has_bits_[0] |= 0x00000040u;
}
inline void brakeNodeData::clear_has_sol6() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void brakeNodeData::clear_sol6() {
  sol6_ = false;
  clear_has_sol6();
}
inline bool brakeNodeData::sol6() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.sol6)
  return sol6_;
}
inline void brakeNodeData::set_sol6(bool value) {
  set_has_sol6();
  sol6_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.sol6)
}

// optional int32 hp = 8;
inline bool brakeNodeData::has_hp() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void brakeNodeData::set_has_hp() {
  _has_bits_[0] |= 0x00000080u;
}
inline void brakeNodeData::clear_has_hp() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void brakeNodeData::clear_hp() {
  hp_ = 0;
  clear_has_hp();
}
inline ::google::protobuf::int32 brakeNodeData::hp() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.hp)
  return hp_;
}
inline void brakeNodeData::set_hp(::google::protobuf::int32 value) {
  set_has_hp();
  hp_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.hp)
}

// optional int32 lp1 = 9;
inline bool brakeNodeData::has_lp1() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void brakeNodeData::set_has_lp1() {
  _has_bits_[0] |= 0x00000100u;
}
inline void brakeNodeData::clear_has_lp1() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void brakeNodeData::clear_lp1() {
  lp1_ = 0;
  clear_has_lp1();
}
inline ::google::protobuf::int32 brakeNodeData::lp1() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.lp1)
  return lp1_;
}
inline void brakeNodeData::set_lp1(::google::protobuf::int32 value) {
  set_has_lp1();
  lp1_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.lp1)
}

// optional int32 lp2 = 10;
inline bool brakeNodeData::has_lp2() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void brakeNodeData::set_has_lp2() {
  _has_bits_[0] |= 0x00000200u;
}
inline void brakeNodeData::clear_has_lp2() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void brakeNodeData::clear_lp2() {
  lp2_ = 0;
  clear_has_lp2();
}
inline ::google::protobuf::int32 brakeNodeData::lp2() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.lp2)
  return lp2_;
}
inline void brakeNodeData::set_lp2(::google::protobuf::int32 value) {
  set_has_lp2();
  lp2_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.lp2)
}

// optional int32 lp3 = 11;
inline bool brakeNodeData::has_lp3() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void brakeNodeData::set_has_lp3() {
  _has_bits_[0] |= 0x00000400u;
}
inline void brakeNodeData::clear_has_lp3() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void brakeNodeData::clear_lp3() {
  lp3_ = 0;
  clear_has_lp3();
}
inline ::google::protobuf::int32 brakeNodeData::lp3() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.lp3)
  return lp3_;
}
inline void brakeNodeData::set_lp3(::google::protobuf::int32 value) {
  set_has_lp3();
  lp3_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.lp3)
}

// optional int32 lp4 = 12;
inline bool brakeNodeData::has_lp4() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void brakeNodeData::set_has_lp4() {
  _has_bits_[0] |= 0x00000800u;
}
inline void brakeNodeData::clear_has_lp4() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void brakeNodeData::clear_lp4() {
  lp4_ = 0;
  clear_has_lp4();
}
inline ::google::protobuf::int32 brakeNodeData::lp4() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.lp4)
  return lp4_;
}
inline void brakeNodeData::set_lp4(::google::protobuf::int32 value) {
  set_has_lp4();
  lp4_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.lp4)
}

// optional int32 temp = 13;
inline bool brakeNodeData::has_temp() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void brakeNodeData::set_has_temp() {
  _has_bits_[0] |= 0x00001000u;
}
inline void brakeNodeData::clear_has_temp() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void brakeNodeData::clear_temp() {
  temp_ = 0;
  clear_has_temp();
}
inline ::google::protobuf::int32 brakeNodeData::temp() const {
  // @@protoc_insertion_point(field_get:fc.brakeNodeData.temp)
  return temp_;
}
inline void brakeNodeData::set_temp(::google::protobuf::int32 value) {
  set_has_temp();
  temp_ = value;
  // @@protoc_insertion_point(field_set:fc.brakeNodeData.temp)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace fc

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::fc::brakeNodeData_breakNodeState> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::fc::brakeNodeData_breakNodeState>() {
  return ::fc::brakeNodeData_breakNodeState_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_ProtoStructs_2eproto
