var http = require('http');
http.createServer(function(req,res)
{
  res.write('Hello world, This is my Node.js server !');
  res.end();
}).listen(10000);
