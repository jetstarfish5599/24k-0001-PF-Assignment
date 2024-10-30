// Roll#24k-0001 Name:Masoom Khan Assignment:2 Q6
#include <stdio.h>
//function for first to win
int firstMoveToWin(int N) {
    // Check for each possible first move from 1 to 4
    for (int x = 1; x <= 4; x++) {
        if ((N - x) % 5 == 0) {
            return x; // A can guarantee a win by picking x matchsticks
        }
    }
    return -1; // No winning move for A on the first turn
}
//start main
int main() {
    int N;
    printf("Enter the number of matchsticks: ");
    scanf("%d", &N);

    int result = firstMoveToWin(N);
    if (result == -1) {
        printf("It is impossible for A to guarantee a win.\n");
    } else {
        printf("A should pick %d matchstick(s) on the first turn to guarantee a win.\n", result);
    }

    return 0;
}
//end main
