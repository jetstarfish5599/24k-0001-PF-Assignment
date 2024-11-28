// Roll#24k-0001 Name:Masoom Khan Assignment:3 Q2
#include <stdio.h>
#include <string.h>

#define BALLS 12

// Structure to store Player details
typedef struct {
    int ballScores[BALLS];
    char playerName[50];
    int totalScore;
} Player;

// Function to validate the score (must be between 0 and 6)
int validateScore(int score) {
    return (score >= 0 && score <= 6);
}

// Function  to play the game
void playGame(Player *player) {
    printf("\n%s's turn:\n", player->playerName);
    player->totalScore = 0;

    for (int i = 0; i < BALLS; i++) {
        int score;
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &score);

        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            printf("Invalid score. Score disregarded.\n");
            player->ballScores[i] = 0; // invalid score
        }
    }
}

// Function tfor winner
void findWinner(Player player1, Player player2) {
    printf("\nMatch Result:\n");
    if (player1.totalScore > player2.totalScore) {
        printf("Winner: %s with a total score of %d!\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("Winner: %s with a total score of %d!\n", player2.playerName, player2.totalScore);
    } else {
        printf("It's a tie! Both players scored %d.\n", player1.totalScore);
    }
}

// Function for match scoreboard
void displayMatchScoreboard(Player player1, Player player2) {
    printf("\nMatch Scoreboard:\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < 2; i++) {
        Player currentPlayer = (i == 0) ? player1 : player2;

        printf("Player: %s\n", currentPlayer.playerName);
        printf("Scores: ");
        for (int j = 0; j < BALLS; j++) {
            printf("%d ", currentPlayer.ballScores[j]);
        }

        double averageScore = (double)currentPlayer.totalScore / BALLS;
        printf("\nTotal Score: %d\n", currentPlayer.totalScore);
        printf("Average Score: %.2f\n", averageScore);
        printf("------------------------------------------------\n");
    }
}
//start main
int main() {
    // Create two Player structures
    Player player1, player2;

    // Input player names
    printf("Enter Player 1's name: ");
    fgets(player1.playerName, 50, stdin);
    player1.playerName[strcspn(player1.playerName, "\n")] = 0; // Remove newline

    printf("Enter Player 2's name: ");
    fgets(player2.playerName, 50, stdin);
    player2.playerName[strcspn(player2.playerName, "\n")] = 0; // Remove newline

    // Players play the game
    playGame(&player1);
    playGame(&player2);

    // Display match scoreboard
    displayMatchScoreboard(player1, player2);

    // Determine and display the winner
    findWinner(player1, player2);

    return 0;
}
//end main