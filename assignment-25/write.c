#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd;
    int ret;

    /* Store file descriptor for error checking */
    fd = open("test.txt", O_WRONLY | O_CREAT, S_IRWXU);

    if (fd == -1) {
        fprintf(stderr, "Error while creating a file.\n");
        return 1;
    }

    /* Store return value from write for error checking */
    ret = write(fd, "This is cool!\n", 14);

    if (ret != 14) {
        fprintf(stderr, "Error while writing to a file.\n");
        return 1;
    }

    if (close(fd) == -1) {
        fprintf(stderr, "Error while closing a file.\n");
        return 1;
    }

    printf("Successfully created and wrote to a file.\n");
    return 0;
}
