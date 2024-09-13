#include <stdio.h>

int main(int argc, char **argv){
    int array[10] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 4};

    /* the reason why we get a pointer instead of a value is because
     * name of the array is the same as a pointer to the first element */
    printf("%d\n", array);
    printf("%d\n", &array[0]);

    return 0;
}
