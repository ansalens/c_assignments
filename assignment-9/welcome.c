#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s firstName lastName\n", argv[0]);
        exit(1);
    }
    printf("Welcome back, %s %s!\n", argv[1], argv[2]);

    return 0;
}
