#include <stdio.h>

struct player {
    int total_points;
    int total_games;
} players[5];

int main(void) {
    float averages[5];

    for (int i = 0; i < 5; i++) {
        printf("Enter Player #%d total points: ", i+1);
        scanf("%d", &players[i].total_points);
        printf("Enter Player #%d total games: ", i+1);
        scanf("%d", &players[i].total_games);
        averages[i] = (float) players[i].total_points / players[i].total_games;
    }

    for (int i = 0; i < 5; i++)
        printf("Player #%d scoring average is: %.2f\n", i+1, averages[i]);

    return 0;
}
