#include <stdio.h>

#define GAMES 4
#define PLAYERS 5

int main(void) {
    int player_scores[3][4] = {0};
    float player_averages[4] = {0};
    float highest_average = 0;
    int best_player = -1;

    /* get player scores for each game */
    for (int game = 0; game < GAMES; game++) {
        printf("Game #%d\n", game+1);
        for (int player = 0; player < PLAYERS; player++) {
            printf("Enter score for player #%d: ", player+1);
            scanf("%d", &player_scores[game][player]);
        }
    }

    /* sum all scores for each player */
    for (int player = 0; player < PLAYERS; player++) {
        for (int game = 0; game < GAMES; game++) {
            player_averages[player] += player_scores[game][player];
        }
        printf("Player #%d has total score of: %f\n", player+1, player_averages[player]);
    }

    /* calculate the average for all players */
    for (int player = 0; player < PLAYERS; player++) {
        player_averages[player] /= GAMES;
        // printf("Average for player #%d is %f\n", player, player_averages[player]);
    }

    highest_average = player_averages[0];

    /* pick best player and display him */
    for (int player = 1; player < PLAYERS; player++) {
        if (highest_average < player_averages[player]) {
            highest_average = player_averages[player];
            best_player = player;
        }
    }

    printf("Player #%d has the best average score of: %f\n", best_player, highest_average);

    return 0;
}
