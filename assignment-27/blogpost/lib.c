#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>

int puts(const char *msg) {
    int (*new_puts)(const char *msg);
    int result;
    new_puts = dlsym(RTLD_NEXT, "puts");
    if (strcmp(msg, "Hello World") == 0)
        result = new_puts("Godbye World");
    else
        result = new_puts(msg);

    return result;
}
