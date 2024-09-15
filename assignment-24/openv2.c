#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s file_to_be_created\n", argv[0]);
        return 1;
    }

    int fd;
    int retval;
    fd = open(argv[1], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if (fd == -1) {
        fprintf(stderr, "File creation failed.\n");
        return -1;
    }

    retval = write(fd, "Some stupid crap.\n", 18);
    if (retval != 18) {
        fprintf(stderr, "File write failed.\n");
        return -1;
    }

    printf("File was created successfully.\n");
    return 0;
}
