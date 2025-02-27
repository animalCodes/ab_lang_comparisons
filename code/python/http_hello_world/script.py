import sys, http.server as http

# Python http_hello_world

# Lack of '\n's at line ends are deliberate; actual newlines are included in
# multiline strings.
get_response = b"""HTTP/1.0 200 OK\r
Content-Type: text/html\r
Content-Length: 48\r\n\r
<html><body><h1>Hello, World!</h1></body></html>
"""

simple_response = b"<html><body><h1>Hello, World!</h1></body></html>\n"

other_response = b"""HTTP/1.0 501 Not Implemented\r
Allow: GET\r
Content-Type: text/html\r
Content-Length: 74\r\n\r
<html><body><h1>This server only supports GET requests.</h1></body></html>
"""

class Handler(http.BaseHTTPRequestHandler):
    def do_GET(self):
        self.close_connection = True
        if self.request_version == "HTTP/0.9":
            self.wfile.write(simple_response)
        else:
            self.wfile.write(get_response)

    def do_other(self):
        self.close_connection = True
        self.wfile.write(other_response)

    def do_HEAD(self):
        self.do_other()

    def do_POST(self):
        self.do_other()

    def do_PUT(self):
        self.do_other()

    def do_DELETE(self):
        self.do_other()

    def do_CONNECT(self):
        self.do_other()

    def do_OPTIONS(self):
        self.do_other()

    def do_TRACE(self):
        self.do_other()

    def do_PATCH(self):
        self.do_other()


try:
    with http.HTTPServer(("127.0.0.1", 8080), Handler) as server:
        server.serve_forever()
except KeyboardInterrupt:
    sys.exit(0)
