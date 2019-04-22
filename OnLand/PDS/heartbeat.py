import socketio
import time
from UDP.Paradigm_pb2 import *
from TCP.heartbeat_timer import HeartbeatTimer
from TCP.PodTcpConnection import PodTcpConnection
from config import *

# Create socket to connect to server
sio = socketio.Client()
@sio.on('connect')
def on_connect():
    print("Connected to Server")
    sio.emit('connected', "commander thread")


@sio.on('disconnect')
def on_disconnect():
    # Set the state to disconnected so that the pod knows?
    print('I\'m disconnected!')


@sio.on('command')
def on_command(command):
    if command is '1':
        podMessage.manualBrakeNodeState = bnsBraking
    else:
        podMessage.manualBrakeNodeState = bnsStandby


sio.connect('http://localhost:5000')
podMessage = podCommand()
podMessage.controlsInterfaceState = ciFlight


def main():
    pod = PodTcpConnection(ip=POD_IP, port=POD_COMMANDER_PORT, MAX_MESSAGE_SIZE=MAX_MESSAGE_SIZE)
    timer = HeartbeatTimer()

    while not pod.is_connected():
        time.sleep(1)
        pod.connect()

        while pod.is_connected():
            # Send Packet, non blocking sockets require a little extra magic to make sure the whole
            # packet gets sent.
            # Send a packets every PULSE_SPEED milliseconds.
            if timer.time_since_pulse() > COMMANDER_PULSE_SPEED:
                pod.send_packet(podMessage.SerializeToString())

                # Receive Packet
                while timer.time_since_pulse() > COMMANDER_PULSE_SPEED and pod.is_connected():
                    msg = pod.receive()
                    if not msg:
                        if timer.time_since_pulse() > COMMANDER_TIMEOUT_TIME:
                            pod.close()
                        elif timer.time_since_pulse() > COMMANDER_BACKUP_PULSE:
                            pod.send_packet(podMessage.SerializeToString())
                    else:  # Msg received
                        sio.emit('ping', 1)
                        timer.pulse()
        # Connection lost, tell GUI
        sio.emit('ping', '0')

if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print('Killed by user')
        exit(0)