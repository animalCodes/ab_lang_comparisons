const {createServer} = require("http")

// Node.js http_hello_world

const simpleResponse = "<html><body><h1>Hello, World!</h1></body></html>\n"

const getResponse = `HTTP/1.0 200 OK\r
Content-Type: text/html\r
Content-Length: 48\r\n\r
<html><body><h1>Hello, World!</h1></body></html>\n`

const otherResponse = `HTTP/1.0 501 Not Implemented\r
Allow: GET\r
Content-Type: text/html\r
Content-Length: 74\r\n\r
<html><body><h1>This server only supports GET requests.</h1></body></html>\n`

const server = createServer({requireHostHeader: false}, (req, res) => {
    console.log(req.httpVersion)
    if (req.method == "GET") {
        if (req.httpVersion == "0.9") {
            res.socket.end(simpleResponse)
        } else {
            res.socket.end(getResponse)
        }
    } else {
        res.socket.end(otherResponse)
    }
})

server.listen(8080)
