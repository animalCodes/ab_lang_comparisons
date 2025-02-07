# HTTP Hello World

A minimal HTTP/1.0-compliant web server demonstrating how to listen for and respond to HTTP requests.

Only accepts GET requests, any other request methods receive a `501 Not Implemented` response.

On receiving a GET request, sends back a static response containing the text "Hello, World!" within HTML.

## Invocation

`http_hello_world`

### Examples

| Request          | Response Status          | Response Headers                                                  | Response Body                                                                |
| ---------------- | ------------------------ | ----------------------------------------------------------------- | ---------------------------------------------------------------------------- |
| `GET /any/url`   | `200 OK`                 | `Content-Type: text/html`<br>`Content-Length: 48`                 | `<html><body><h1>Hello, World!</h1></body></html>`                           |
| `POST /`         | `501 Not Implemented`    | `Allow: GET`<br>`Content-Type: text/html`<br>`Content-Length: 74` | `<html><body><h1>This server only supports GET requests.</h1></body></html>` |

## Implementation

Many modern programming languages feature builtin HTTP libraries. For these most of the below details are irrelevant.
For those that don't, this specification includes details of setting up and using a TCP socket.

### Functions

Based on the [Berkeley sockets](https://en.wikipedia.org/wiki/Berkeley_sockets) API.

Each socket function may fail. If one does, it will return -1.

- `socket()` - Create a TCP socket.

- `bind(socket, address, port)` - Bind `socket` to `address:port`.

- `listen(socket)` - Put `socket` into listening state.

- `accept(socket)` - Wait for and return details of a connection to `socket`.

- `recv(socket)` - Extract message from connection `socket`. As a string.

- `send(socket, message)` - Send a message from `socket` to it's currently-connected pair.

- `shutdown(socket)` - Terminate currently-active connection on `socket`.

<br>

- `method(message)` - HTTP method of `message`, as a string.

- `version(message)` - HTTP version of `message`, any version later than `1.0` is treated as `1.0`, otherwise `0.9`.

- `handle_interrupt()` - Called on program receiving SIGINT, definition given below.

### Code

> Below are the three responses the server can use. Corresponding to a valid
> request, an HTTP/0.9 request, and a request using a method other than GET,
> respectively.

```
get_response = "
HTTP/1.0 200 OK\r\n
Content-Type: text/html\r\n
Content-Length: 48\r\n\r\n
<html><body><h1>Hello, World!</h1></body></html>\n"

simple_response = "<html><body><h1>Hello, World!</h1></body></html>\n"

other_response = "
HTTP/1.0 501 Not Implemented\r\n
Allow: GET\r\n
Content-Type: text/html\r\n
Content-Length: 74\r\n\r\n
<html><body><h1>This server only supports GET requests.</h1></body></html>\n"
```

> In reality, each socket function may fail and should be checked, for brevity
> this is skipped.

```
server = socket()

bind(server, 127.0.0.1, 8080)

if (listen(server) == -1) {
    println("Unable to setup socket, exiting.")
    exit(1)
{

while (true) {
    request = recv(accept(server))

    if (request == -1) {
        println("Failed to receive request, exiting.")
        exit(1)
    }

    if (method(request) == "GET") {
        if (version(request) == "1.0")
            send(server, get_response)
        else
            send(server, simple_response)
    } else {
        send(server, other_response)
    }

    shutdown(server)
}

void handle_interrupt() {
    exit(0)
}
```

**Implemented in**: C.

**To be implemented in**: C++ C#, DenoJS, Go, Java, Kotlin, Node.js, Python, Ruby, Rust.
