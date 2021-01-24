var socket = new io.connect();
socket.on('connect', function(){
	document.getElementById("status").innerHTML="Connected";
});

socket.on('DDS', function(data){
	var textarea = document.getElementById("logDDS");
	
	textarea.value += data;
	if(textarea.selectionStart == textarea.selectionEnd)
		textarea.scrollTop = textarea.scrollHeight;
});

socket.on('control', function(data){
	var textarea = document.getElementById("logControl");

	textarea.value += data;
	if(textarea.selectionStart == textarea.selectionEnd)
		textarea.scrollTop = textarea.scrollHeight;
});

socket.on('comm', function(data){
   	var textarea = document.getElementById("logCommunicator");

	textarea.value += data;
	if(textarea.selectionStart == textarea.selectionEnd)
		textarea.scrollTop = textarea.scrollHeight;
});


