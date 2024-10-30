// Roll#24k-0001 Name:Masoom Khan Assignment:2 Q8
#include <stdio.h>

#define SIZE 5

// Function prototypes
void displayGrid(char grid[SIZE][SIZE]);
void movePlayer(char grid[SIZE][SIZE], int *playerRow, int *playerCol, char move, int *itemsCollected);

int main() {
    // Initialize the grid
    char grid[SIZE][SIZE] = {
        {'I', ' ', 'I', 'X', ' '},
        {' ', 'P', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', 'I', ' ', ' '}
    };
    // Starting position of 'P' at row 1, column 1
    int playerRow = 1, playerCol = 1;  
    int itemsCollected = 0;
    char move;

    printf("Welcome to the Grid Adventure Game!\n");
    
    // Game loop
    while (1) {
        displayGrid(grid);
        printf("Items collected: %d\n", itemsCollected);
        printf("Move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        // Check if player wants to quit
        if (move == 'Q' || move == 'q') {
            printf("Game over. You collected %d items.\n", itemsCollected);
            break;
        }
        
        // Update player position based on the move
        movePlayer(grid, &playerRow, &playerCol, move, &itemsCollected);
    }

    return 0;
}

// Function to display the current grid
void displayGrid(char grid[SIZE][SIZE]) {
    printf("\nGrid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move the player
void movePlayer(char grid[SIZE][SIZE], int *playerRow, int *playerCol, char move, int *itemsCollected) {
    int newRow = *playerRow;
    int newCol = *playerCol;

    // Determine new position based on input
    if (move == 'W' || move == 'w') {
        newRow -= 1;
    } else if (move == 'S' || move == 's') {
        newRow += 1;
    } else if (move == 'A' || move == 'a') {
        newCol -= 1;
    } else if (move == 'D' || move == 'd') {
        newCol += 1;
    } else {
        printf("Invalid input. Please use W, A, S, D to move or Q to quit.\n");
        return;
    }

    // Check if the new position is within bounds
    if (newRow < 0 || newRow >= SIZE || newCol < 0 || newCol >= SIZE) {
        printf("Cannot move outside the grid!\n");
        return;
    }

    // Check if the new position is an obstacle
    if (grid[newRow][newCol] == 'X') {
        printf("Obstacle encountered! Cannot move there.\n");
        return;
    }

    // Check if the new position has an item
    if (grid[newRow][newCol] == 'I') {
        printf("Item collected!\n");
        (*itemsCollected)++;
    }

    // Update the grid
    // Clear previous player position
    grid[*playerRow][*playerCol] = ' ';  
    // Move player to the new position
    grid[newRow][newCol] = 'P';          
    *playerRow = newRow;
    *playerCol = newCol;
}
