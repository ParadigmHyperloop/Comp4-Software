/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.3 at Sat May 18 20:50:04 2019. */

#include "Paradigm.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

const int32_t DtsNodeToFc_packetNum_default = 0;
const BrakeNodeStates DtsNodeToFc_brakeNodeState_default = BrakeNodeStates_bnsStandby;
const bool DtsNodeToFc_brakeSolenoidState_default = false;
const bool DtsNodeToFc_ventSolenoidState_default = false;
const float DtsNodeToFc_rotorTemperature_default = 0;
const float DtsNodeToFc_pneumaticTemperature_default = 0;
const float DtsNodeToFc_tankPressure_default = 0;
const float DtsNodeToFc_brakePressure_default = 0;
const int32_t RearNodeToFc_packetNum_default = 0;
const float RearNodeToFc_tubePressure_default = 0;
const float RearNodeToFc_coolantPressure1_default = 0;
const float RearNodeToFc_coolantPressure2_default = 0;
const float RearNodeToFc_coolantPressure3_default = 0;
const float RearNodeToFc_coolantTemperature_default = 0;


const pb_field_t brakeNodeData_fields[15] = {
    PB_FIELD(  1, INT32   , REQUIRED, STATIC  , FIRST, brakeNodeData, id, id, 0),
    PB_FIELD(  2, BOOL    , OPTIONAL, STATIC  , OTHER, brakeNodeData, sol1, id, 0),
    PB_FIELD(  3, BOOL    , OPTIONAL, STATIC  , OTHER, brakeNodeData, sol2, sol1, 0),
    PB_FIELD(  4, BOOL    , OPTIONAL, STATIC  , OTHER, brakeNodeData, sol3, sol2, 0),
    PB_FIELD(  5, BOOL    , OPTIONAL, STATIC  , OTHER, brakeNodeData, sol4, sol3, 0),
    PB_FIELD(  6, BOOL    , OPTIONAL, STATIC  , OTHER, brakeNodeData, sol5, sol4, 0),
    PB_FIELD(  7, BOOL    , OPTIONAL, STATIC  , OTHER, brakeNodeData, sol6, sol5, 0),
    PB_FIELD(  8, INT32   , OPTIONAL, STATIC  , OTHER, brakeNodeData, hp, sol6, 0),
    PB_FIELD(  9, INT32   , OPTIONAL, STATIC  , OTHER, brakeNodeData, lp1, hp, 0),
    PB_FIELD( 10, INT32   , OPTIONAL, STATIC  , OTHER, brakeNodeData, lp2, lp1, 0),
    PB_FIELD( 11, INT32   , OPTIONAL, STATIC  , OTHER, brakeNodeData, lp3, lp2, 0),
    PB_FIELD( 12, INT32   , OPTIONAL, STATIC  , OTHER, brakeNodeData, lp4, lp3, 0),
    PB_FIELD( 13, INT32   , OPTIONAL, STATIC  , OTHER, brakeNodeData, temp, lp4, 0),
    PB_FIELD( 14, UENUM   , OPTIONAL, STATIC  , OTHER, brakeNodeData, state, temp, 0),
    PB_LAST_FIELD
};

const pb_field_t podCommand_fields[7] = {
    PB_FIELD(  1, UENUM   , OPTIONAL, STATIC  , FIRST, podCommand, controlsInterfaceState, controlsInterfaceState, 0),
    PB_FIELD(  2, UENUM   , OPTIONAL, STATIC  , OTHER, podCommand, manualPodState, controlsInterfaceState, 0),
    PB_FIELD(  3, UENUM   , OPTIONAL, STATIC  , OTHER, podCommand, manualBrakeNodeState, manualPodState, 0),
    PB_FIELD(  4, UENUM   , OPTIONAL, STATIC  , OTHER, podCommand, manualMotorState, manualBrakeNodeState, 0),
    PB_FIELD(  5, UENUM   , OPTIONAL, STATIC  , OTHER, podCommand, manualLvdcNodeState, manualMotorState, 0),
    PB_FIELD(  6, BOOL    , OPTIONAL, STATIC  , OTHER, podCommand, automaticStateTransitions, manualLvdcNodeState, 0),
    PB_LAST_FIELD
};

const pb_field_t telemetry_fields[73] = {
    PB_FIELD(  1, UENUM   , OPTIONAL, STATIC  , FIRST, telemetry, podState, podState, 0),
    PB_FIELD(  2, UENUM   , OPTIONAL, STATIC  , OTHER, telemetry, breakNodeState, podState, 0),
    PB_FIELD(  3, UENUM   , OPTIONAL, STATIC  , OTHER, telemetry, motorState, breakNodeState, 0),
    PB_FIELD(  4, UENUM   , OPTIONAL, STATIC  , OTHER, telemetry, controlsInterfaceState, motorState, 0),
    PB_FIELD(  5, UENUM   , OPTIONAL, STATIC  , OTHER, telemetry, inverterState, controlsInterfaceState, 0),
    PB_FIELD(  6, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, missionTime, inverterState, 0),
    PB_FIELD(  7, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, flightTime, missionTime, 0),
    PB_FIELD(  8, INT32   , REPEATED, CALLBACK, OTHER, telemetry, heartbeatFlags, flightTime, 0),
    PB_FIELD(  9, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, podPosition, heartbeatFlags, 0),
    PB_FIELD( 10, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, podVelocity, podPosition, 0),
    PB_FIELD( 11, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, podAccelerationX, podVelocity, 0),
    PB_FIELD( 12, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, podAccelerationY, podAccelerationX, 0),
    PB_FIELD( 13, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, podAccelerationZ, podAccelerationY, 0),
    PB_FIELD( 14, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, imuVelocity, podAccelerationZ, 0),
    PB_FIELD( 15, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, imuAccelerationX, imuVelocity, 0),
    PB_FIELD( 16, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, tachometerVelocity, imuAccelerationX, 0),
    PB_FIELD( 17, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, resolverVelocity, tachometerVelocity, 0),
    PB_FIELD( 18, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, inverterTemperature1, resolverVelocity, 0),
    PB_FIELD( 19, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, inverterTemperature2, inverterTemperature1, 0),
    PB_FIELD( 20, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, inverterTemperature3, inverterTemperature2, 0),
    PB_FIELD( 21, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, motorCurrent, inverterTemperature3, 0),
    PB_FIELD( 22, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, motorVoltage, motorCurrent, 0),
    PB_FIELD( 23, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, inverterVoltages, motorVoltage, 0),
    PB_FIELD( 24, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, inverterCurrents, inverterVoltages, 0),
    PB_FIELD( 25, UENUM   , OPTIONAL, STATIC  , OTHER, telemetry, batteryManagementState, inverterCurrents, 0),
    PB_FIELD( 26, INT32   , REPEATED, CALLBACK, OTHER, telemetry, batteryPackVoltages, batteryManagementState, 0),
    PB_FIELD( 27, INT32   , REPEATED, CALLBACK, OTHER, telemetry, batteryPackCurrent, batteryPackVoltages, 0),
    PB_FIELD( 28, INT32   , REPEATED, CALLBACK, OTHER, telemetry, batteryCellTemperatures, batteryPackCurrent, 0),
    PB_FIELD( 29, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, batteryPackMinimumVoltage, batteryCellTemperatures, 0),
    PB_FIELD( 30, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, batteryPackMaxVoltage, batteryPackMinimumVoltage, 0),
    PB_FIELD( 31, UENUM   , OPTIONAL, STATIC  , OTHER, telemetry, breakNodePerceivedPodState, batteryPackMaxVoltage, 0),
    PB_FIELD( 32, BOOL    , OPTIONAL, STATIC  , OTHER, telemetry, bSolenoid1, breakNodePerceivedPodState, 0),
    PB_FIELD( 33, BOOL    , OPTIONAL, STATIC  , OTHER, telemetry, bSolenoid2, bSolenoid1, 0),
    PB_FIELD( 34, BOOL    , OPTIONAL, STATIC  , OTHER, telemetry, bSolenoid3, bSolenoid2, 0),
    PB_FIELD( 35, BOOL    , OPTIONAL, STATIC  , OTHER, telemetry, bSolenoid4, bSolenoid3, 0),
    PB_FIELD( 36, BOOL    , OPTIONAL, STATIC  , OTHER, telemetry, bSolenoid5, bSolenoid4, 0),
    PB_FIELD( 37, BOOL    , OPTIONAL, STATIC  , OTHER, telemetry, bSolenoid6, bSolenoid5, 0),
    PB_FIELD( 38, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, iHighPressure, bSolenoid6, 0),
    PB_FIELD( 39, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, iLowPressure1, iHighPressure, 0),
    PB_FIELD( 40, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, iLowPressure2, iLowPressure1, 0),
    PB_FIELD( 41, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, iLowPressure3, iLowPressure2, 0),
    PB_FIELD( 42, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, iLowPressure4, iLowPressure3, 0),
    PB_FIELD( 43, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, pressureVesselTemperature, iLowPressure4, 0),
    PB_FIELD( 44, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, electronicsEnclosurePressure, pressureVesselTemperature, 0),
    PB_FIELD( 45, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railDisplacementX, electronicsEnclosurePressure, 0),
    PB_FIELD( 46, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railDisplacementY, railDisplacementX, 0),
    PB_FIELD( 48, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, tubePressure, railDisplacementY, 0),
    PB_FIELD( 49, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, coolantPressure1, tubePressure, 0),
    PB_FIELD( 50, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, coolantPressure2, coolantPressure1, 0),
    PB_FIELD( 51, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, coolantPressure3, coolantPressure2, 0),
    PB_FIELD( 52, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, coolantTemperature, coolantPressure3, 0),
    PB_FIELD( 53, FLOAT   , OPTIONAL, STATIC  , OTHER, telemetry, railTemperature, coolantTemperature, 0),
    PB_FIELD( 54, UENUM   , OPTIONAL, STATIC  , OTHER, telemetry, lvdcNodeState, railTemperature, 0),
    PB_FIELD( 55, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, pack1Voltage, lvdcNodeState, 0),
    PB_FIELD( 56, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, pack2Voltage, pack1Voltage, 0),
    PB_FIELD( 57, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, pack1Current, pack2Voltage, 0),
    PB_FIELD( 58, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, pack2Current, pack1Current, 0),
    PB_FIELD( 59, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, rail1Voltage, pack2Current, 0),
    PB_FIELD( 60, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, rail2Voltage, rail1Voltage, 0),
    PB_FIELD( 61, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, rail3Voltage, rail2Voltage, 0),
    PB_FIELD( 62, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, rail4Voltage, rail3Voltage, 0),
    PB_FIELD( 63, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railCurrentSensor1, rail4Voltage, 0),
    PB_FIELD( 64, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railCurrentSensor2, railCurrentSensor1, 0),
    PB_FIELD( 65, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railCurrentSensor3, railCurrentSensor2, 0),
    PB_FIELD( 66, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railCurrentSensor4, railCurrentSensor3, 0),
    PB_FIELD( 67, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railCurrentSensor5, railCurrentSensor4, 0),
    PB_FIELD( 68, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railCurrentSensor6, railCurrentSensor5, 0),
    PB_FIELD( 69, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railCurrentSensor7, railCurrentSensor6, 0),
    PB_FIELD( 70, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railCurrentSensor8, railCurrentSensor7, 0),
    PB_FIELD( 71, INT32   , REPEATED, CALLBACK, OTHER, telemetry, heartbeatValues, railCurrentSensor8, 0),
    PB_FIELD( 72, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railVoltageFlag, heartbeatValues, 0),
    PB_FIELD( 73, INT32   , OPTIONAL, STATIC  , OTHER, telemetry, railCurrentFlag, railVoltageFlag, 0),
    PB_LAST_FIELD
};

const pb_field_t FcToBrakeNode_fields[4] = {
    PB_FIELD(  1, INT32   , OPTIONAL, STATIC  , FIRST, FcToBrakeNode, packetNum, packetNum, 0),
    PB_FIELD(  2, UENUM   , OPTIONAL, STATIC  , OTHER, FcToBrakeNode, podState, packetNum, 0),
    PB_FIELD(  3, UENUM   , OPTIONAL, STATIC  , OTHER, FcToBrakeNode, manualNodeState, podState, 0),
    PB_LAST_FIELD
};

const pb_field_t DtsNodeToFc_fields[9] = {
    PB_FIELD(  1, INT32   , REQUIRED, STATIC  , FIRST, DtsNodeToFc, packetNum, packetNum, &DtsNodeToFc_packetNum_default),
    PB_FIELD(  2, UENUM   , REQUIRED, STATIC  , OTHER, DtsNodeToFc, brakeNodeState, packetNum, &DtsNodeToFc_brakeNodeState_default),
    PB_FIELD(  3, BOOL    , REQUIRED, STATIC  , OTHER, DtsNodeToFc, brakeSolenoidState, brakeNodeState, &DtsNodeToFc_brakeSolenoidState_default),
    PB_FIELD(  4, BOOL    , REQUIRED, STATIC  , OTHER, DtsNodeToFc, ventSolenoidState, brakeSolenoidState, &DtsNodeToFc_ventSolenoidState_default),
    PB_FIELD(  5, FLOAT   , REQUIRED, STATIC  , OTHER, DtsNodeToFc, rotorTemperature, ventSolenoidState, &DtsNodeToFc_rotorTemperature_default),
    PB_FIELD(  6, FLOAT   , REQUIRED, STATIC  , OTHER, DtsNodeToFc, pneumaticTemperature, rotorTemperature, &DtsNodeToFc_pneumaticTemperature_default),
    PB_FIELD(  7, FLOAT   , REQUIRED, STATIC  , OTHER, DtsNodeToFc, tankPressure, pneumaticTemperature, &DtsNodeToFc_tankPressure_default),
    PB_FIELD(  8, FLOAT   , REQUIRED, STATIC  , OTHER, DtsNodeToFc, brakePressure, tankPressure, &DtsNodeToFc_brakePressure_default),
    PB_LAST_FIELD
};

const pb_field_t RearNodeToFc_fields[7] = {
    PB_FIELD(  1, INT32   , REQUIRED, STATIC  , FIRST, RearNodeToFc, packetNum, packetNum, &RearNodeToFc_packetNum_default),
    PB_FIELD(  2, FLOAT   , REQUIRED, STATIC  , OTHER, RearNodeToFc, tubePressure, packetNum, &RearNodeToFc_tubePressure_default),
    PB_FIELD(  3, FLOAT   , REQUIRED, STATIC  , OTHER, RearNodeToFc, coolantPressure1, tubePressure, &RearNodeToFc_coolantPressure1_default),
    PB_FIELD(  4, FLOAT   , REQUIRED, STATIC  , OTHER, RearNodeToFc, coolantPressure2, coolantPressure1, &RearNodeToFc_coolantPressure2_default),
    PB_FIELD(  5, FLOAT   , REQUIRED, STATIC  , OTHER, RearNodeToFc, coolantPressure3, coolantPressure2, &RearNodeToFc_coolantPressure3_default),
    PB_FIELD(  6, FLOAT   , REQUIRED, STATIC  , OTHER, RearNodeToFc, coolantTemperature, coolantPressure3, &RearNodeToFc_coolantTemperature_default),
    PB_LAST_FIELD
};

const pb_field_t flightConfig_fields[9] = {
    PB_FIELD(  1, UINT32  , REQUIRED, STATIC  , FIRST, flightConfig, retrieval_timeout, retrieval_timeout, 0),
    PB_FIELD(  2, UINT64  , REQUIRED, STATIC  , OTHER, flightConfig, max_flight_time, retrieval_timeout, 0),
    PB_FIELD(  3, UINT64  , REQUIRED, STATIC  , OTHER, flightConfig, motor_speed, max_flight_time, 0),
    PB_FIELD(  4, INT32   , REQUIRED, STATIC  , OTHER, flightConfig, telemetry_port, motor_speed, 0),
    PB_FIELD(  5, INT32   , REQUIRED, STATIC  , OTHER, flightConfig, command_port, telemetry_port, 0),
    PB_FIELD(  6, UINT64  , REQUIRED, STATIC  , OTHER, flightConfig, flight_length, command_port, 0),
    PB_FIELD(  7, INT32   , REQUIRED, STATIC  , OTHER, flightConfig, heartbeat_timeout, flight_length, 0),
    PB_FIELD(  8, STRING  , REQUIRED, CALLBACK, OTHER, flightConfig, pod_driver, heartbeat_timeout, 0),
    PB_LAST_FIELD
};

const pb_field_t defaultFcToNode_fields[2] = {
    PB_FIELD(  1, UENUM   , OPTIONAL, STATIC  , FIRST, defaultFcToNode, podState, podState, 0),
    PB_LAST_FIELD
};










/* @@protoc_insertion_point(eof) */
