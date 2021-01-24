var http = require("http");
var socketio = require('socket.io');
var path = require('path');
var fs = require("fs");
const Tail = require('tail').Tail;
var ddsWatcher = new Tail("../logs/DDS.log");
var controlWatcher = new Tail("../logs/control.log");
var communicatorWatcher = new Tail("../logs/communicator.log");
var chartWatcher = new Tail("../logs/dateChart.log");

var app = http.createServer(handler);
var io = socketio(app);
app.listen(8888);

function handler (req, res) {

	var filePath = req.url;
	
	if(filePath == '/')
		filePath = './web/index.html';
	else
		filePath = './web/' + req.url;
	
	var extname = path.extname(filePath);
	var contentType = 'text/html'

	switch (extname) {
		case '.js':
			contentType = 'text/javascript';
			break;
		case '.css':
			contentType = 'text/css';
			break;
	}
	
	fs.exists(filePath, function(exists){
		if (exists){
			fs.readFile(filePath, function(error,content) {
				if(error){
					res.writeHead(500);
					res.end();
				}
				else {
					res.writeHead(200, {'Content-Type': contentType});
					res.end(content,'utf-8');
				}
			});
		}
		else{
			res.writeHead(404);
			res.end();
		}
	});
}

io.on('connection', socket => {
	console.log("New client");

	ddsWatcher.watch()
	controlWatcher.watch()
	communicatorWatcher.watch()
	console.log("LOG WATCHING!");
	
	ddsWatcher.on("line", data => {
		socket.emit('DDS',data + "\n");
	});
	ddsWatcher.on("error", function(error) {
	  console.log('ERROR: ', error);
	});

	controlWatcher.on("line", data => {
		socket.emit('control',data + "\n");
	});
	controlWatcher.on("error", function(error) {
	  console.log('ERROR: ', error);
	});

	communicatorWatcher.on("line", data => {
		socket.emit('comm',data + "\n");
	});
	communicatorWatcher.on("error", function(error) {
	  console.log('ERROR: ', error);
	});

	chartWatcher.on("line", data => {
		var dateSplit = data.split("#");
		socket.emit(dateSplit[0],dateSplit[1]);
	});
	chartWatcher.on("error", function(error) {
	  console.log('ERROR: ', error);
	});
});

