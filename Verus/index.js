// Don't need this since I'm using firebase
console.log("server is starting");
var express = require('express');
const http = require('http');
const app = express(); // Init for express
const port = process.env.PORT || 3000
const server = http.createServer(app); // Creation of an HTTP server
server.listen(port, () => console.log(`Server started on port ${port}...`))
app.use(express.static('Project')); //host static files like img