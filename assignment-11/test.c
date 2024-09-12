#include <stdio.h>

int main(int argc, char **argv) {
    int scores[10] = {0};
    int test_score = 0;
    float sum = 0;
    int i = 0;
    float average = 0;
    char choice = 'N';

    do {
        printf("Enter a test score: ");
        scanf("%d", &test_score);
        if (test_score < 0 || test_score > 100) {
            printf("Invalid test score entered\n");
            continue;
        }
        scores[i++] = test_score;
        sum += test_score;
        /* out of array space */
        if (i == 10)
            break;

        printf("Would you like to continue [Y/N]? ");
        scanf(" %c", &choice);
    } while((choice == 'Y' || choice == 'y') && i < 10);

    // printf("Sum is %f and i = %d", sum, i);
    average = sum / i;

    printf("The average is: %.2f\n", average);
    
    return 0;
}
