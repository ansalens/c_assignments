#include <stdio.h>

int main(void) {
    int seconds, minutes, hours, r_seconds = 0;
    int input;

    printf("Enter number of seconds: ");
    scanf("%d", &input);

    seconds = input;    /* copy input to another variable */

    /* calculate and update input variable accordingly */
    hours = input / 3600;
    input -= hours * 3600;
    minutes = input / 60;
    input -= minutes * 60;
    r_seconds = input;

    printf("%d seconds is:\n\t\t%d hours\n\t\t\t%d minutes\n\t\t\t\t%d seconds\n", seconds, hours, minutes, r_seconds);

    return 0;
}
