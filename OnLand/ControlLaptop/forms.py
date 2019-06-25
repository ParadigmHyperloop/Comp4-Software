from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField, BooleanField, IntegerField
from wtforms.validators import DataRequired, NumberRange


class PodConfigurationForm(FlaskForm):
    retrieval_timeout = StringField('Retrieval Timeout (s)',
                                    validators=[DataRequired("Timeout")])
    telemetry_port = StringField('PDS Telemetry Port',
                                 validators=[DataRequired("PDS Port")])
    command_port = StringField('PDS Command Port',
                               validators=[DataRequired("PDS Port")])
    heartbeat_timout = StringField('HeartBeat Timeout (s)',
                                   validators=[DataRequired("HeartBeat Timeout")])
    pod_ip = StringField('Pod Address (IP)',
                         validators=[DataRequired("Pod Address")])
    pod_driver = BooleanField('Pod Driver: ')
    submit = SubmitField('Send Configuration')


class FlightProfileForm(FlaskForm):
    max_flight_time = IntegerField('Maximum Flight Time (s)', validators=[DataRequired("Required"), NumberRange(0, 100, "0 < Flight Time < 100")])
    motor_speed = IntegerField('Motor Torque (N/m)', validators=[DataRequired("Required"), NumberRange(0, 10000, "0  < Distance < 100 ")])
    flight_distance = IntegerField('Flight Distance (meters)', validators=[DataRequired("Required"), NumberRange(0, 100, "0  < Flight Distance < 100 ")])
    #todo radial for air or vaccume



def validate_configuration_values(configuration_form):
    # TODO: implement once we know specifics of configuration
    return {
        'error': ['Error Messages'],
        'all_values_valid': True
    }


