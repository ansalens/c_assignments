#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fileDescriptor;

    fileDescriptor = open("test.txt", O_WRONLY | O_CREAT, S_IRWXU);

    if (fileDescriptor == -1) {
        printf("Error occured while creating a new file.\n");
        return 1;
    }
    
    printf("File created successfully.\n");
    return 0;
}
