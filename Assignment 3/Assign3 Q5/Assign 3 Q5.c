// Roll#24k-0001 Name:Masoom Khan Assignment:3 Q5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char*** initializeInventory(int numSpecies);
void addSupplies(char*** inventory, int numSpecies, int* numSuppliesPerSpecies);
void updateSupply(char*** inventory, int speciesIndex, int supplyIndex, int* numSuppliesPerSpecies);
void removeSpecies(char*** inventory, int* numSpecies, int speciesIndex, int* numSuppliesPerSpecies);
void displayInventory(char*** inventory, int numSpecies, int* numSuppliesPerSpecies);
void freeInventory(char*** inventory, int numSpecies, int* numSuppliesPerSpecies);

int main() {
    int numSpecies;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    // Initialize inventory
    char*** inventory = initializeInventory(numSpecies);
    int* numSuppliesPerSpecies = (int*)calloc(numSpecies, sizeof(int)); // Tracks the number of supplies per species

    int choice;
    do {
        printf("\n--- Pets in Heart Inventory Menu ---\n");
        printf("1. Add Supplies\n");
        printf("2. Update Supply\n");
        printf("3. Remove Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSupplies(inventory, numSpecies, numSuppliesPerSpecies);
                break;
            case 2: {
                int speciesIndex, supplyIndex;
                printf("Enter species index to update (0-%d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                printf("Enter supply index to update (0-%d): ", numSuppliesPerSpecies[speciesIndex] - 1);
                scanf("%d", &supplyIndex);
                updateSupply(inventory, speciesIndex, supplyIndex, numSuppliesPerSpecies);
                break;
            }
            case 3: {
                int speciesIndex;
                printf("Enter species index to remove (0-%d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                removeSpecies(inventory, &numSpecies, speciesIndex, numSuppliesPerSpecies);
                break;
            }
            case 4:
                displayInventory(inventory, numSpecies, numSuppliesPerSpecies);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory
    freeInventory(inventory, numSpecies, numSuppliesPerSpecies);
    free(numSuppliesPerSpecies);

    return 0;
}

// Function Definitions

// Initialize the inventory
char*** initializeInventory(int numSpecies) {
    char*** inventory = (char*)malloc(numSpecies * sizeof(char**));
    for (int i = 0; i < numSpecies; i++) {
        inventory[i] = NULL; // Start with no supplies for each species
    }
    return inventory;
}

// Add supplies for each species
void addSupplies(char*** inventory, int numSpecies, int* numSuppliesPerSpecies) {
    int speciesIndex, numSupplies;
    printf("Enter species index to add supplies (0-%d): ", numSpecies - 1);
    scanf("%d", &speciesIndex);
    if (speciesIndex < 0 || speciesIndex >= numSpecies) {
        printf("Invalid species index.\n");
        return;
    }

    printf("Enter the number of supplies to add: ");
    scanf("%d", &numSupplies);

    inventory[speciesIndex] = (char*)realloc(inventory[speciesIndex], (numSuppliesPerSpecies[speciesIndex] + numSupplies) * sizeof(char));

    for (int i = 0; i < numSupplies; i++) {
        printf("Enter supply name %d: ", numSuppliesPerSpecies[speciesIndex] + i + 1);
        char buffer[100];
        scanf(" %[^\n]", buffer);

        inventory[speciesIndex][numSuppliesPerSpecies[speciesIndex] + i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(inventory[speciesIndex][numSuppliesPerSpecies[speciesIndex] + i], buffer);
    }

    numSuppliesPerSpecies[speciesIndex] += numSupplies;
}

// Update a specific supply
void updateSupply(char*** inventory, int speciesIndex, int supplyIndex, int* numSuppliesPerSpecies) {
    if (speciesIndex < 0 || supplyIndex < 0 || supplyIndex >= numSuppliesPerSpecies[speciesIndex]) {
        printf("Invalid species or supply index.\n");
        return;
    }

    printf("Enter the new name for supply %d: ", supplyIndex + 1);
    char buffer[100];
    scanf(" %[^\n]", buffer);

    free(inventory[speciesIndex][supplyIndex]); // Free old supply name
    inventory[speciesIndex][supplyIndex] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(inventory[speciesIndex][supplyIndex], buffer);
}

// Remove a species and free its memory
void removeSpecies(char*** inventory, int* numSpecies, int speciesIndex, int* numSuppliesPerSpecies) {
    if (speciesIndex < 0 || speciesIndex >= *numSpecies) {
        printf("Invalid species index.\n");
        return;
    }

    // Free memory for supplies of the species
    for (int i = 0; i < numSuppliesPerSpecies[speciesIndex]; i++) {
        free(inventory[speciesIndex][i]);
    }
    free(inventory[speciesIndex]);

    // Shift remaining species
    for (int i = speciesIndex; i < *numSpecies - 1; i++) {
        inventory[i] = inventory[i + 1];
        numSuppliesPerSpecies[i] = numSuppliesPerSpecies[i + 1];
    }

    (*numSpecies)--; // Decrease the number of species
    printf("Species %d removed successfully.\n", speciesIndex);
}

// Display the inventory
void displayInventory(char*** inventory, int numSpecies, int* numSuppliesPerSpecies) {
    printf("\n--- Current Inventory ---\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d:\n", i + 1);
        for (int j = 0; j < numSuppliesPerSpecies[i]; j++) {
            printf("  Supply %d: %s\n", j + 1, inventory[i][j]);
        }
    }
}

// Free the inventory
void freeInventory(char*** inventory, int numSpecies, int* numSuppliesPerSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < numSuppliesPerSpecies[i]; j++) {
            free(inventory[i][j]);
        }
        free(inventory[i]);
    }
    free(inventory);
}