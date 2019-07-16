
var sensor_ranges = false;
var table_sensors = [];
var pod_state = ""

$( document ).ready(function() {
    socket.emit('join_room','telemetry_updates');
    $("#sensorTable").find("tr").each(function(){ table_sensors.push(this.id); });
    getSensorRanges();
});

function getSensorRanges() {
    $.get($SCRIPT_ROOT + '/sensor_ranges', function (data) {
        sensor_ranges = JSON.parse(data)
    });
}

function updateRowStatus( value_name ,$value_cell, value){
    let min,max;
    min = sensor_ranges[value_name][pod_state][0]
    max = sensor_ranges[value_name][pod_state][1]

    if(!sensor_ranges.hasOwnProperty(value_name)){
        console.log(value_name + " not found in sensor ranges")
        return
    }
    if(value > max || value < min){
        $value_cell.addClass('danger');
        $value_cell.removeClass('success');
    }
    else{
        $value_cell.addClass('success');
        $value_cell.removeClass('danger');
    }
}

function ParsePodState(state) {
    let new_min;
    let new_max;
    let success;
    let sensor_name;
    if (!sensor_ranges) {
        getSensorRanges();
        console.log("No sensor Ranges yet")
        return
    }
    if (state !== pod_state){
        pod_state = state;
        $(".max-min-value").each(function (index) {
             sensor_name = $(this).attr('id');
             success = true;
            try {
                new_min = sensor_ranges[sensor_name][state][0];
                new_max = sensor_ranges[sensor_name][state][1];
            }
            catch(error) {
              console.error("Error getting max and min values for " + sensor_name + "in state " + podState);
              success = false;
            }
            if(success){
                $('#' + sensor_name + '-min').text(new_min);
                $('#' + sensor_name + '-max').text(new_max);
            }
        });
    }
}

var telemetry_value_elements = [];
$( document ).ready(function() {
    socket.emit('join_room','telemetry_updates');
    $(".telemetry-value").each(function(){ telemetry_value_elements.push(this); });
});


socket.on('pod_telemetry', function (data) {
    let value, value_cell, value_name, current_state;
    data = JSON.parse(data);
    console.log(data)
    const length = telemetry_value_elements.length;

    current_state = data['podState']
    ParsePodState(current_state);

    for (let index = 0; index < length; index++) {

        value_cell = telemetry_value_elements[index];
        value_name = value_cell.id;

        if(!data.hasOwnProperty(value_name)){
            console.log(value_name + " not found in packet")
            continue;
        }
        value = data[value_name];
        let $value_cell = $('#'+value_name);

        if(value_name === 'inverterFaultBitHi' || value_name === 'inverterFaultBitLo' || value_name === 'hvFaultCode1' || value_name === 'hvFaultCode2') {
            convertFaultCode(value_name, value)
        }

        if(typeof(data[value_name]) == "boolean" || isNaN(data[value_name])){
            $value_cell.text(value)
        }
        else if($value_cell.hasClass('boolean')){
            value = (value === 1) ? 'True' : 'False';
            $value_cell.text(value)
        }
        else{
            $value_cell.text(value.toFixed(2));
            if($value_cell.hasClass('max-min-value')){
                updateRowStatus(value_name, $value_cell, value);
            }
        }
    }
});


function convertFaultCode(value_name, value) {
    if(value_name === 'inverterFaultBitLo') {
        errors = converInverterFaultCodeLo(value)
        console.error(`INVERTER FAULTS: ${errors}`)

    }
    if(value_name === 'inverterFaultBitLo') {
        errors = converInverterFaultCodeHi(value)
        console.error(`INVERTER FAULTS: ${errors}`)
    }
    else if(value_name === 'hvFaultCode1') {
        console.log(value)
    }
    else if(value_name === 'hvFaultCode2') {
        console.log(value)
    }
    else {
        console.error(`COULD NOT CONVERT ERROR CODE FOR ${value_name}`)
    }
}


function addErrorsToUpdatesTable(errors) {
    // if error not in tabke add it
    for (const error of errors) {
        console.log(updatesTable)
        var flag = 0

        $('#events-table-body').find("tr").each(function () {
            var td2 = $(this).find("td:eq(1)").text();
            
            if (td2 === error) { 
                flag = 1; 
            }
        });
        console.log(flag)
        if (flag === 0) {
            let row = `<tr>
                      <td><i class="fa fa-info text-info"></i></td>
                      <td>${error}</td>
                    </tr>`;

            $('#events-table-body').prepend(row);
        }
    }
}


function converInverterFaultCodeLo(value) {
    let errors = []

    if(value & 1) {
        errors.push('Inverter: Motor Over-speed Fault')   
    }
    if(value & 2) {
        errors.push('Inverter: Over-current Fault')
    }
    if(value & 4) {
        errors.push('Inverter: Over-voltage Fault')
    }
    if(value & 8) {
        errors.push('Inverter: Inverter Over-temperature Fault')
    }
    if(value & 10) {
        errors.push('Inverter: Accelerator Input Shorted Fault')
    }
    if(value & 32) {
        errors.push('Inverter: Accelerator Input Open Fault')   
    }
    if(value & 64) {
        errors.push('Inverter: Direction Command Fault (Both directions active at the same time)')
    }
    if(value & 128) {
        errors.push('Inverter: Inverter Response Time-out Fault')
    }
    if(value & 256) {
        errors.push('Inverter: Hardware Desaturation Fault')
    }
    if(value & 512) {
        errors.push('Inverter: Hardware Over-current Fault')
    }
    if(value & 1024) {
        errors.push('Inverter: Under-voltage Fault')
    }
    if(value & 2048) {
        errors.push('Inverter: CAN Command Message Lost Fault')
    }
    if(value & 4096) {
        errors.push('Inverter: Motor Over-temperature Fault')
    }

    addErrorsToUpdatesTable(errors)
    return errors
}

function converInverterFaultCodeHi(value) {
    let errors = []

    if(value & 1) {
        errors.push('Inverter: Brake Input Shorted Fault')
    }
    if(value & 2) {
        errors.push('Inverter: Brake Input Open Fault')
    }

    addErrorsToUpdatesTable(errors)
    return errors
}