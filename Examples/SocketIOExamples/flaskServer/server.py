import json
from flask import Flask, render_template, request
from flask_socketio import SocketIO

app = Flask(__name__)
socket_io = SocketIO(app)


@app.route('/')
def landing_page():
    with open('DtsSensors.json') as json_file:
        sensor_params = json.load(json_file)
    return render_template('DtsControl.html', sensors=sensor_params)


@socket_io.on('json')
def handle_json(message):
    print('received json: ' + message)


@socket_io.on('disconnect')
def handle_disconnect():
    a = request
    print("someone left")


@socket_io.on('connect')
def print_connect():
    print('User Connected')


@socket_io.on('pds packet')
def pds_packet(packet):
    print('packet')
    socket_io.emit("pds packet", packet)


@socket_io.on('pod pulse')
def pod_pulse(pulse):
    print('pulse')
    socket_io.emit("pod pulse", pulse)


@socket_io.on('command')
def interface_command(command):
    print('command')
    socket_io.emit("command", command)


@socket_io.on('ping')
def interface_command(ping):
    print(ping)
    socket_io.emit("ping", ping)


if __name__ == "__main__":
    socket_io.run(app, debug=True)

