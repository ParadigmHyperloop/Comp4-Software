function showConfigurationUpdateStatus(from, align, message, status){
	$.notify({
		icon: "pe-7s-gift",
		message: `Flight Config - <b>${message}</b>`

	},{
	  type: status,
		timer: 4000,
		placement: {
			from: from,
			align: align
		}
	});
}

function validConfigFormValues() {
  let formHasNoError = true;
  // Ip Address Validation
  if (!(/^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/.test($('#pod-ip').val())))
  {
    formHasNoError = false;
    $('#pod-ip').parent().addClass('has-error');
  }
  if (isNaN($('#retrieval-timout').val()) && $('#retrieval-timout').val() > 0) { // Validated Retrieval timeout
    formHasNoError = false;
    $('#retrieval-timout').parent().addClass('has-error');
  }
  if (isNaN($('#telemetry-port').val()) || $('#telemetry-port').val().length !== 4) { // Validated Telemetry port
    formHasNoError = false;
    $('#telemetry-port').parent().addClass('has-error');
  }
  if (isNaN($('#command-port').val()) || $('#command-port').val().length !== 4) { // Validated command port
    formHasNoError = false;
    $('#command-port').parent().addClass('has-error');
  }
  if (isNaN($('#heartbeat-timeout').val()) && $('#heartbeat-timeout').val() > 0) { // Validated flight Length
    formHasNoError = false;
    $('#heartbeat-timeout').parent().addClass('has-error');
  }
  return formHasNoError;
}

function setupConfigurationFormSubmit() {
  $('#configuration-form').on('submit' , function handleConfigurationFormSubmission(e) {
    e.preventDefault();
    if (validConfigFormValues())
    {
      $.ajax({
      type: "POST",
      beforeSend: function(xhr, settings) {
        if (!/^(GET|HEAD|OPTIONS|TRACE)$/i.test(settings.type) && !this.crossDomain) {
          xhr.setRequestHeader("X-CSRFToken", "{{ form.csrf_token._value() }}")
        }
      },
      url: '/submit_configuration',
      data: $('#configuration-form').serialize(),
      success: function handleSucceessFormSubmission(data) {
        showConfigurationUpdateStatus('top','right', 'Configuration Sent To POD', 'Success');
        console.log('Submission, Success')
      },
      error: function handleErrorFormSubmission(data) {
        showConfigurationUpdateStatus('top','right', 'Failed to Connect to Pod', 'Danger');
      }
    });
    }
  });
}

function setupConfigurationForm()
{
  $('#pod-driver').bootstrapToggle({
    on: 'Motor',
    off: 'Simulation'
  });

  $('.js-config-form-input').on('focusin',function handleFormFocus()
  {
    $(this).parent().removeClass('has-error');
  });
}

$(document).ready(function() {
  setupConfigurationForm();
  setupConfigurationFormSubmit();
});