import socket
import time
import random
from config import POD_COMMANDER_PORT, UDP_TELEM_PORT
from Paradigm_pb2 import Telemetry

def create_telem(packet):
    packet.podState = random.randint(0, 8)
    packet.controlsInterfaceState = random.randint(0, 5)
    packet.lvdcNodeState = random.randint(0, 3)
    packet.breakNodePerceivedPodState = random.randint(0, 7)
    packet.brakeNodeState = random.randint(0, 5)
    packet.brakingDistance = random.randint(0, 101)
    packet.maxStripCount = random.randint(0, 101)
    packet.maxVelocity = random.randint(0, 101)
    packet.navNodeState = random.randint(0, 1)

    packet.flightTime = random.randint(0, 101)
    packet.podPosition = random.randint(0, 101)
    packet.podVelocity = random.randint(0, 101)
    packet.resolverVelocity = random.randint(0, 101)

    packet.maxIgbtTemperature = random.randint(0, 101)
    packet.gateDriverTemperature = random.randint(0, 101)
    packet.inverterControlBoardTemperature = random.randint(0, 101)
    packet.motorTemperature = random.randint(0, 101)
    packet.inverterBusVoltage = random.randint(0, 101)
    packet.inverterHeartbeat = random.randint(0, 101)
    packet.motorSpeed = random.randint(0, 101)
    packet.inverterRunFaultLo = 0 # random.randint(0, 101)
    packet.inverterRunFaultHi = 0 # random.randint(0, 101)
    packet.inverterPostFaultLo = 0 # random.randint(0, 101)
    packet.inverterPostFaultHi = 0 # random.randint(0, 101)

    packet.hvBatteryPackVoltage = random.randint(0, 101)
    packet.hvBatteryPackCurrent = random.randint(0, 101)
    packet.hvBatteryPackMaxCellTemperature = random.randint(0, 101)
    packet.hvBatteryPackMaxCellVoltage = random.randint(0, 101)
    packet.hvBatteryPackMinimumCellVoltage = random.randint(0, 101)
    packet.hvBatteryPackStateOfCharge = random.randint(0, 101)

    packet.lv1BatteryPackStateOfCharge = random.randint(0, 101)
    packet.lv1BatteryPackVoltage = random.randint(0, 101)
    packet.lv1BatteryPackCellTemperature = random.randint(0, 101)
    packet.lv2BatteryPackStateOfCharge = random.randint(0, 101)
    packet.lv2BatteryPackVoltage = random.randint(0, 101)
    packet.lv2BatteryPackCellTemperature = random.randint(0, 101)
    packet.hvFaultCode1 = 0 # random.randint(0, 101)
    packet.hvFaultCode2 = 0 # random.randint(0, 101)

    packet.solenoid1 = random.randint(0, 101)
    packet.solenoid2 = random.randint(0, 101)
    packet.solenoid3 = random.randint(0, 101)
    packet.solenoid4 = random.randint(0, 101)
    packet.highPressure  = random.randint(0, 101)
    packet.lowPressure1 = random.randint(0, 101)
    packet.lowPressure2 = random.randint(0, 101)
    packet.lowPressure3 = random.randint(0, 101)
    packet.lowPressure4 = random.randint(0, 101)
    packet.pressureVesselTemperature = random.randint(0, 101)
    packet.coolantTemperature = random.randint(0, 101)

    packet.enclosurePressure = random.randint(0, 101)
    packet.enclosureTemperature = random.randint(0, 101)

    packet.tubePressure = random.randint(0, 101)
    packet.coolantPressure1 = random.randint(0, 101)
    packet.coolantPressure2 = random.randint(0, 101)

    packet.gtPack1Voltage = random.randint(0, 101)
    packet.gtPack2Voltage = random.randint(0, 101)
    packet.gtPack1Current = random.randint(0, 101)
    packet.gtPack2Current = random.randint(0, 101)
    packet.gtLp5Current = random.randint(0, 101)
    packet.gtLp12Current = random.randint(0, 101)
    packet.gtNodeCurrent = random.randint(0, 101)
    packet.gtInverterCurrent = random.randint(0, 101)

    packet.motorTorque = random.randint(0, 101)
    packet.flightDistance = random.randint(0, 101)
    packet.maxFlightTime = random.randint(0, 101)
    packet.startTorque = random.randint(0, 101)
    packet.accelerationTime = random.randint(0, 101)
    packet.taxi = random.randint(0, 101)
    packet.expectedTubePressure = random.randint(0, 101)

    packet.tachRpm = random.randint(0, 101)
    packet.irRpm = random.randint(0, 101)
    packet.tachDistance = random.randint(0, 101)
    packet.irDistance = random.randint(0, 101)

    packet.totalStripCount = random.randint(0, 101)

    for i in range(0, 192):
        packet.hvBatteryCellVoltages.extend([random.randint(0, 200)])

    return packet


def main():
    sudp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    stcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    stcp.bind(("127.0.0.1", POD_COMMANDER_PORT))
    stcp.listen()
    conn, addr = stcp.accept()
    print(conn, addr)

    while(1):
        pod_data = Telemetry()
        create_telem(pod_data)
        sudp.sendto(pod_data.SerializeToString(), ("127.0.0.1", UDP_TELEM_PORT))

        data = conn.recv(1024)

        if data:
            print("recved:", data)
            conn.send(b'1')

        time.sleep(1)

    stcp.close()


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print('Killed by user')
        exit(0)
