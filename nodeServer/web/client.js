var socket = new io.connect();
socket.on('connect', function(){
	document.getElementById("status").innerHTML="Connected";
});

socket.on('DDS', function(data){
	document.getElementById("logDDS").value += data;
});

socket.on('control', function(data){
   	document.getElementById("logControl").value += data;
});

socket.on('comm', function(data){
   	document.getElementById("logCommunicator").value += data;
});
