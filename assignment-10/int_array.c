#include <stdio.h>

int main(int argc, char **argv) {
    int int_array[10] = {0};

    /* single integer is 4 bytes, that's why I divide by 4 to get actual number of elements */
    printf("This array has %ld elements\n", sizeof(int_array)/4);

    return 0;
}
