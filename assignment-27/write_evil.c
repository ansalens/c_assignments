#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>


// new function call that also matches original write's signature
static ssize_t (*original_write)(int fildes, const void *buf, size_t nbyte);

// declare our write the way it was defined in header files
ssize_t write(int fildes, const void *buf, size_t nbyte) {
    // return value of bytes written to fd
    ssize_t bytes;
    // initialize the function pointer to original write
    if (original_write == NULL)
        original_write = dlsym(RTLD_NEXT, "write");

    // compare if string argument to write is one string
    if (strcmp(buf, "Hello, World!") == 0) {
        // then replace it with another string and call write
        bytes = write(fildes, "Godbye, cruel world!", 20);
        // return number of bytes it wrote to the screen
        return bytes;
    }

    // or else just call regular write
    return original_write(fildes, buf, nbyte);
}
