#include <stdio.h>
#include <stdlib.h>

/* Best practises: https://www.reddit.com/r/C_Programming/comments/uemqc4/comment/i6ovntd/ */

int main(void) {
    char *charp;
    /* make charp point to heap memory allocated by malloc */
    charp = malloc(sizeof(char) * 10);

    /* check if malloc failed and exit if it did fail */
    if (charp == NULL) {
        fprintf(stderr, "Couldn't allocate memory.\n");
        return 1;
    }

    printf("Successfully allocated the memory.\n");
    free(charp);

    return 0;
}
