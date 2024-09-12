#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAP 3

int main(void) {
    char answer = 'y';
    double sum, average = 0;
    double *scores = malloc(sizeof(double) * INITIAL_CAP);
    int num_scores = 0;
    int capacity = INITIAL_CAP;

    if (!scores) {
        fprintf(stderr, "Couldn't allocate enough space for the buffer.\n");
        exit(1);
    }

    for (; answer == 'y' || answer == 'Y'; num_scores++) {
        if (num_scores == capacity) {
            printf("Dynamically increasing...");
            capacity = capacity * 2;
            scores = realloc(scores, capacity * sizeof(double));
        }
        if (!scores) {
            fprintf(stderr, "Couldn't reallocate memory.\n");
            exit(2);
        }

        printf("Enter a test score: ");
        scanf("%lf", &scores[num_scores]);
        sum += scores[num_scores];

        printf("Continue (Y/N): ");
        scanf(" %c", &answer);
    }

    average = sum / num_scores;
    printf("Average is %.2f\n", average);

    free(scores);

    return 0;
}
