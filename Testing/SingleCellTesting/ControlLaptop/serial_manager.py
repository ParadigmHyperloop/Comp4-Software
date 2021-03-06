import sys
import glob
import serial


class SerialManager:
    def __init__(self):
        self.solenoid_event_queued = False
        self.solenoid_state = 0

    # sets the 'self.solenoid_event_queued' flag and self.solenoid_state,
    # signalling to the telemetry thread that the solenoid needs to be toggled
    def toggle_solenoid(self):
        if self.solenoid_state:
            self.solenoid_state = 0
        else:
            self.solenoid_state = 1
        self.solenoid_event_queued = True

    # returns a list of avaiable serial ports
    def get_available_serial_ports(self):
        if sys.platform.startswith('win'):
            ports = ['COM%s' % (i + 1) for i in range(256)]
        elif sys.platform.startswith('linux'):
            ports = glob.glob('/dev/tty[A-Za-z]*')
        elif sys.platform.startswith('darwin'):
            ports = glob.glob('/dev/tty.*')
        else:
            raise EnvironmentError('Unsupported platform')
        result = []
        for port in ports:
            try:
                s = serial.Serial(port)
                s.close()
                result.append(port)
            except (OSError, serial.SerialException):
                pass
        return result

    # creates a serial.Serial instance on a certain serial port
    def open_port(self, port):
        self.serial = serial.Serial(
            port=port,
            baudrate=9600,
            timeout=1
        )

    # reads a line from the serial port, parses it, and returns it as a dict
    def read_telemetry(self):
        telemetry = self.serial.readline()
        if not telemetry:
            return
        telemetry = str(telemetry)
        # create a list with ',' delimiter
        telemetry = telemetry.split(",")
        # remove excess start/end line characters
        telemetry[0] = telemetry[0][2:]
        del telemetry[-1]
        try:
            return {
                'milliseconds': float(telemetry[0]),
                'cell_voltage': float(telemetry[1]),
                'cell_current_low': float(telemetry[2]),
                'cell_current_high': float(telemetry[3]),
                'temp_1': float(telemetry[5]),
                'temp_2': float(telemetry[6]),
                'temp_3': telemetry[5]
            }
        except (IndexError, ValueError):
            return
