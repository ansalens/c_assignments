#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int flips = 0, heads = 0, tails = 0;
    srand(time(NULL));

    printf("Enter a number of coin flips: ");
    scanf("%d", &flips);

    for (int i = 0; i < flips; i++) {
        /* limit rand() to only output 1 or 0 */
        rand() % (1 - 0 + 1) + 0 ? heads++ : tails++;
    }

    printf("Number of heads: %d\nNumber of tails: %d\n", heads, tails);

    return 0;
}
