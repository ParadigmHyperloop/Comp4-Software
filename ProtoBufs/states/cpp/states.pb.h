// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: states.proto

#ifndef PROTOBUF_INCLUDED_states_2eproto
#define PROTOBUF_INCLUDED_states_2eproto

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
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_states_2eproto 

namespace protobuf_states_2eproto {
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
}  // namespace protobuf_states_2eproto

enum breakNodeStates {
  bnsBooting = 0,
  bnsStandby = 1,
  bnsArming = 2,
  bnsArmed = 3,
  bnsFlight = 4,
  bnsBraking = 5,
  bnsVenting = 6,
  bnsRetrieval = 7,
  bnsError = 8
};
bool breakNodeStates_IsValid(int value);
const breakNodeStates breakNodeStates_MIN = bnsBooting;
const breakNodeStates breakNodeStates_MAX = bnsError;
const int breakNodeStates_ARRAYSIZE = breakNodeStates_MAX + 1;

const ::google::protobuf::EnumDescriptor* breakNodeStates_descriptor();
inline const ::std::string& breakNodeStates_Name(breakNodeStates value) {
  return ::google::protobuf::internal::NameOfEnum(
    breakNodeStates_descriptor(), value);
}
inline bool breakNodeStates_Parse(
    const ::std::string& name, breakNodeStates* value) {
  return ::google::protobuf::internal::ParseNamedEnum<breakNodeStates>(
    breakNodeStates_descriptor(), name, value);
}
enum podStates {
  psBooting = 0,
  psStandby = 1,
  psArming = 2,
  psArmed = 3,
  psFlight = 4,
  psBraking = 5,
  psVenting = 6,
  psRetrieval = 7,
  psError = 8
};
bool podStates_IsValid(int value);
const podStates podStates_MIN = psBooting;
const podStates podStates_MAX = psError;
const int podStates_ARRAYSIZE = podStates_MAX + 1;

const ::google::protobuf::EnumDescriptor* podStates_descriptor();
inline const ::std::string& podStates_Name(podStates value) {
  return ::google::protobuf::internal::NameOfEnum(
    podStates_descriptor(), value);
}
inline bool podStates_Parse(
    const ::std::string& name, podStates* value) {
  return ::google::protobuf::internal::ParseNamedEnum<podStates>(
    podStates_descriptor(), name, value);
}
enum motorStates {
  msOff = 0,
  msCharging = 1,
  msIdle = 2,
  msEngaged = 3
};
bool motorStates_IsValid(int value);
const motorStates motorStates_MIN = msOff;
const motorStates motorStates_MAX = msEngaged;
const int motorStates_ARRAYSIZE = motorStates_MAX + 1;

const ::google::protobuf::EnumDescriptor* motorStates_descriptor();
inline const ::std::string& motorStates_Name(motorStates value) {
  return ::google::protobuf::internal::NameOfEnum(
    motorStates_descriptor(), value);
}
inline bool motorStates_Parse(
    const ::std::string& name, motorStates* value) {
  return ::google::protobuf::internal::ParseNamedEnum<motorStates>(
    motorStates_descriptor(), name, value);
}
enum controlsInterfaceStates {
  ciConnected = 0
};
bool controlsInterfaceStates_IsValid(int value);
const controlsInterfaceStates controlsInterfaceStates_MIN = ciConnected;
const controlsInterfaceStates controlsInterfaceStates_MAX = ciConnected;
const int controlsInterfaceStates_ARRAYSIZE = controlsInterfaceStates_MAX + 1;

const ::google::protobuf::EnumDescriptor* controlsInterfaceStates_descriptor();
inline const ::std::string& controlsInterfaceStates_Name(controlsInterfaceStates value) {
  return ::google::protobuf::internal::NameOfEnum(
    controlsInterfaceStates_descriptor(), value);
}
inline bool controlsInterfaceStates_Parse(
    const ::std::string& name, controlsInterfaceStates* value) {
  return ::google::protobuf::internal::ParseNamedEnum<controlsInterfaceStates>(
    controlsInterfaceStates_descriptor(), name, value);
}
enum inverterStates {
  iConnected = 0
};
bool inverterStates_IsValid(int value);
const inverterStates inverterStates_MIN = iConnected;
const inverterStates inverterStates_MAX = iConnected;
const int inverterStates_ARRAYSIZE = inverterStates_MAX + 1;

const ::google::protobuf::EnumDescriptor* inverterStates_descriptor();
inline const ::std::string& inverterStates_Name(inverterStates value) {
  return ::google::protobuf::internal::NameOfEnum(
    inverterStates_descriptor(), value);
}
inline bool inverterStates_Parse(
    const ::std::string& name, inverterStates* value) {
  return ::google::protobuf::internal::ParseNamedEnum<inverterStates>(
    inverterStates_descriptor(), name, value);
}
enum batteryManagementStates {
  bmsNominal = 0
};
bool batteryManagementStates_IsValid(int value);
const batteryManagementStates batteryManagementStates_MIN = bmsNominal;
const batteryManagementStates batteryManagementStates_MAX = bmsNominal;
const int batteryManagementStates_ARRAYSIZE = batteryManagementStates_MAX + 1;

const ::google::protobuf::EnumDescriptor* batteryManagementStates_descriptor();
inline const ::std::string& batteryManagementStates_Name(batteryManagementStates value) {
  return ::google::protobuf::internal::NameOfEnum(
    batteryManagementStates_descriptor(), value);
}
inline bool batteryManagementStates_Parse(
    const ::std::string& name, batteryManagementStates* value) {
  return ::google::protobuf::internal::ParseNamedEnum<batteryManagementStates>(
    batteryManagementStates_descriptor(), name, value);
}
enum rearNodeStates {
  rnBooting = 0,
  rnNominal = 1
};
bool rearNodeStates_IsValid(int value);
const rearNodeStates rearNodeStates_MIN = rnBooting;
const rearNodeStates rearNodeStates_MAX = rnNominal;
const int rearNodeStates_ARRAYSIZE = rearNodeStates_MAX + 1;

const ::google::protobuf::EnumDescriptor* rearNodeStates_descriptor();
inline const ::std::string& rearNodeStates_Name(rearNodeStates value) {
  return ::google::protobuf::internal::NameOfEnum(
    rearNodeStates_descriptor(), value);
}
inline bool rearNodeStates_Parse(
    const ::std::string& name, rearNodeStates* value) {
  return ::google::protobuf::internal::ParseNamedEnum<rearNodeStates>(
    rearNodeStates_descriptor(), name, value);
}
enum lvdcNodeStates {
  lvdcBooting = 0
};
bool lvdcNodeStates_IsValid(int value);
const lvdcNodeStates lvdcNodeStates_MIN = lvdcBooting;
const lvdcNodeStates lvdcNodeStates_MAX = lvdcBooting;
const int lvdcNodeStates_ARRAYSIZE = lvdcNodeStates_MAX + 1;

const ::google::protobuf::EnumDescriptor* lvdcNodeStates_descriptor();
inline const ::std::string& lvdcNodeStates_Name(lvdcNodeStates value) {
  return ::google::protobuf::internal::NameOfEnum(
    lvdcNodeStates_descriptor(), value);
}
inline bool lvdcNodeStates_Parse(
    const ::std::string& name, lvdcNodeStates* value) {
  return ::google::protobuf::internal::ParseNamedEnum<lvdcNodeStates>(
    lvdcNodeStates_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::breakNodeStates> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::breakNodeStates>() {
  return ::breakNodeStates_descriptor();
}
template <> struct is_proto_enum< ::podStates> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::podStates>() {
  return ::podStates_descriptor();
}
template <> struct is_proto_enum< ::motorStates> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::motorStates>() {
  return ::motorStates_descriptor();
}
template <> struct is_proto_enum< ::controlsInterfaceStates> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::controlsInterfaceStates>() {
  return ::controlsInterfaceStates_descriptor();
}
template <> struct is_proto_enum< ::inverterStates> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::inverterStates>() {
  return ::inverterStates_descriptor();
}
template <> struct is_proto_enum< ::batteryManagementStates> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::batteryManagementStates>() {
  return ::batteryManagementStates_descriptor();
}
template <> struct is_proto_enum< ::rearNodeStates> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::rearNodeStates>() {
  return ::rearNodeStates_descriptor();
}
template <> struct is_proto_enum< ::lvdcNodeStates> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::lvdcNodeStates>() {
  return ::lvdcNodeStates_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_states_2eproto
