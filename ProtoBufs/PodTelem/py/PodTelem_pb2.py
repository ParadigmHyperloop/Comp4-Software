# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: PodTelem.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='PodTelem.proto',
  package='pds',
  syntax='proto2',
  serialized_options=None,
  serialized_pb=_b('\n\x0ePodTelem.proto\x12\x03pds\"\x17\n\ttelemetry\x12\n\n\x02id\x18\x01 \x02(\x05')
)




_TELEMETRY = _descriptor.Descriptor(
  name='telemetry',
  full_name='pds.telemetry',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='id', full_name='pds.telemetry.id', index=0,
      number=1, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto2',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=23,
  serialized_end=46,
)

DESCRIPTOR.message_types_by_name['telemetry'] = _TELEMETRY
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

telemetry = _reflection.GeneratedProtocolMessageType('telemetry', (_message.Message,), dict(
  DESCRIPTOR = _TELEMETRY,
  __module__ = 'PodTelem_pb2'
  # @@protoc_insertion_point(class_scope:pds.telemetry)
  ))
_sym_db.RegisterMessage(telemetry)


# @@protoc_insertion_point(module_scope)
