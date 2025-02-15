#include <arpa/inet.h>
#include <errno.h>
#include <poll.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>

// C http_hello_world

/* Close `s` and exit. */
void cleanup();

/* Setup a TCP socket listening on 127.0.0.1:8080.
    Should an error occur, -1 will be returned and errno will be set.
    Otherwise, returns the socket file descriptor. */
int setup_socket();

/* Attempt to `recv()` `n` bytes from socket `fd` into `buffer`.
    If necessary, will wait for up to 100ms.
    If no data is read, returns -1. Otherwise returns number of bytes written.*/
int recv_next(int fd, char *buffer, int n);

/* Choose which hardcoded response to use. */
char *choose_response(int fd);

char *get_response =
"HTTP/1.0 200 OK\r\n"
"Content-Type: text/html\r\n"
"Content-Length: 48\r\n\r\n"
"<html><body><h1>Hello, World!</h1></body></html>\n";

char *simple_response =
"<html><body><h1>Hello, World!</h1></body></html>\n";

char *other_response =
"HTTP/1.0 501 Not Implemented\r\n"
"Allow: GET\r\n"
"Content-Type: text/html\r\n"
"Content-Length: 74\r\n\r\n"
"<html><body><h1>This server only supports GET requests.</h1></body></html>\n";

int socket_fd;

int main()
{
    signal(SIGINT, cleanup);

    socket_fd = setup_socket();
    if (socket_fd == -1) {
        fprintf(stderr, "Unable to setup socket, exiting.\n");
        cleanup();
    }

    int request_fd;

    while (1) {
        request_fd = accept(socket_fd, NULL, NULL);

        char *response = choose_response(request_fd);

        send(request_fd, response, strlen(response), 0);

        shutdown(socket_fd, SHUT_WR);
    }
}

char *choose_response(int fd)
{
    char buffer[80];
    int message_len;
    if ((message_len = recv_next(fd, buffer, sizeof buffer)) == -1) {
        fprintf(stderr, "Failed to receive request, exiting.");
        cleanup();
    }

    if (strncasecmp(buffer, "GET", 3) == 0) {
        bool space = false;
        // HTTP/0.9 doesn't show its version, and fields are separated by
        // spaces. So if there is two or more spaces this cannot be HTTP/0.9
        do {
            for (int i = 0; i < message_len; i++) {
                if (buffer[i] == ' ' && space) {
                    return get_response;
                }
                if (buffer[i] == ' ')
                    space = true;
            }
            // Fiddly, but statusline might be longer than 80 chars.
        } while ((message_len = recv_next(fd, buffer, sizeof buffer)) > 0);
        return simple_response;
    } else {
        return other_response;
    }
}

int setup_socket()
{
    struct sockaddr_in address;
    address.sin_family = AF_INET; // Always AF_INET.
    address.sin_port = htons(8080);
    inet_aton("127.0.0.1", &address.sin_addr);

    errno = 0;

    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1)
        return -1;

    if (bind(s, (struct sockaddr *) &address, sizeof (address)) == -1)
        return -1;

    if (listen(s, 0) == -1)
        return -1;

    return s;
}

int recv_next(int fd, char *buffer, int n)
{
    struct pollfd pollfd[1];
    pollfd[0].fd = fd;
    pollfd[0].events = POLLRDNORM;
    if (poll(pollfd, 1, 100) > 0) {
        return recv(fd, buffer, n, 0);
    }
    return -1;
}

void cleanup()
{
    close(socket_fd);
    exit(0);
}
