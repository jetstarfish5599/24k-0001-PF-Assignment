// Roll#24k-0001 Name:Masoom Khan Assignment:2 Q7
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROWS 6
#define COLS 5

// Function to populate the 2D array with random characters
void populateArray(char array[ROWS][COLS]) {
    for (int i = 0; i < ROWS - 1; i++) {
        for (int j = 0; j < COLS; j++) {
            array[i][j] = 'A' + rand() % 26; // Random letter from A to Z
        }
    }
    // Set the last row to "0001"
    array[ROWS - 1][0] = '0';
    array[ROWS - 1][1] = '0';
    array[ROWS - 1][2] = '0';
    array[ROWS - 1][3] = '1';
    array[ROWS - 1][4] = 'Q';
}

// Function to print the 2D array
void printArray(char array[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", array[i][j]);
        }
        printf("\n");
    }
}

// Function to search for a string in the array
int searchString(char array[ROWS][COLS], const char *str) {
    int len = strlen(str);

    // Search left-to-right
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - len; j++) {
            int match = 1;
            for (int k = 0; k < len; k++) {
                if (array[i][j + k] != str[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) return 1;
        }
    }

    // Search top-to-bottom
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i <= ROWS - len; i++) {
            int match = 1;
            for (int k = 0; k < len; k++) {
                if (array[i + k][j] != str[k]) {
                    match = 0;
                    break;
                }
            }
            if (match) return 1;
        }
    }

    return 0;
}

int main() {
    char array[ROWS][COLS];
    char input[100];
    int score = 0;

    srand(time(0)); // Seed for random number generation

    while (1) {
        populateArray(array);
        printArray(array);

        while (1) {
            printf("Search Str= ");
            scanf("%s", input);

            if (strcmp(input, "END") == 0) break;

            if (searchString(array, input)) {
                score++;
                printf("%s is present Score %d\n", input, score);
            } else {
                score--;
                printf("%s is not present Score %d\n", input, score);
            }
        }

        printf("Repopulating array with new random characters...\n");
    }

    return 0;
}
//end main
