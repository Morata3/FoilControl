var http = require("http");
var fs = require("fs");

http.createServer(function(request,response){
	console.log("Running!");
	response.writeHead(200,{"Content-type":"text/plain"});
	response.write("Hello world");
	response.end();
}).listen(8888);

const readLine = require("readline");
const fileStream = fs.createReadStream('../DDS.log');
var watcher = fs.watch('../DDS.log');

async function processLineByLine() {
  const rl = readLine.createInterface({
    input: fileStream,
    crlfDelay: Infinity
  });

  for await (const line of rl) {
    console.log(`Line from file: ${line}`);
  }
}
/*fs.watch('../DDS.log', { encoding: 'utf-8' }, (eventType, filename) => {
  if (filename) {
    console.log(filename);
    console.log(eventType)
  }
});*/

const Tail = require('tail').Tail;
var tail = new Tail("../DDS.log");
tail.watch()
console.log("TAIL WATCHING!");
tail.on("line", data => {
  console.log(data);
});



