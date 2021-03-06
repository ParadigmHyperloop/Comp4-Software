
"""
    Local File Storage Interface.
"""


class LocalStorage:
    @classmethod
    def get_default_configuration(cls):
        return DEFAULT_CONFIGURATION

    @classmethod
    def get_sensors(cls):
        return TempSensor()


# Working Sample Sensor Table Format.
class TempSensor:
    def __init__(self):
        self.name = 'name'
        self.min = 0
        self.max = 100


# Default Sample Configuration
DEFAULT_CONFIGURATION = {
    'retrieval_timeout': 2000,
    'max_flight_time': 30,
    'motor_speed': 1,
    'telemetry_port': 7000,
    'command_port': 6000,
    'flight_length': 60,
    'heartbeat_timeout': 2000,
    'pod_address': '192.168.5.4',
    'pod_driver': 'Simulation',
}