#include <stdio.h>

#define GAMES 4
#define PLAYERS 5

int main(void) {
    int scores_per_game[GAMES][PLAYERS] = {0};
    double averages[PLAYERS] = {0};
    double max_average = 0;
    int best_player = -1;

    for (int i = 0; i < GAMES; i++) {
        printf("Game #%d\n", i+1);
        for (int j = 0; j < PLAYERS; j++) {
            printf("Enter score for player #%d: ", j+1);
            scanf("%d", &scores_per_game[i][j]);
            averages[j] += scores_per_game[i][j];
        }
    }
    /*
     * For debugging
    for (int i = 0; i < GAMES; i++) {
        printf("Game #%d\n", i+1);
        for (int j = 0; j < PLAYERS; j++) {
            printf("Score for player #%d is %d \n", j+1, scores_per_game[i][j]);
        }
    }
    */
    for (int i = 0; i < PLAYERS; i++) {
        averages[i] /= GAMES;
        //printf("Average for #%d is %lf\n", i+1, averages[i]);
    }

    max_average = averages[0];

    for (int i = 1; i < PLAYERS; i++) {
        if (averages[i] > max_average) {
            max_average = averages[i];
            best_player = i+1;
        }
    }

    printf("Best player is player #%d with highest scoring average of %.2lf\n", best_player, max_average);
    return 0;
}
