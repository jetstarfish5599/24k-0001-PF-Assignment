// Roll#24k-0001 Name:Masoom Khan Assignment:3 Q7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Content Metadata
typedef struct {
    char title[100];
    double rating;
    int runtime;    // in minutes
    char encoding[20];
} ContentMetadata;

// Function prototypes
double** allocateEngagementMatrix(int numUsers, int numCategories);
double*** allocateDeviceMatrix(int numUsers, int numDevices, int numSettings);
ContentMetadata*** allocateContentMatrix(int numCategories, int numContentPerCategory);
void freeEngagementMatrix(double** matrix, int numUsers);
void freeDeviceMatrix(double*** matrix, int numUsers, int numDevices);
void freeContentMatrix(ContentMetadata*** matrix, int numCategories, int numContentPerCategory);
void displayEngagementMatrix(double** matrix, int numUsers, int numCategories);
void displayContentMatrix(ContentMetadata*** matrix, int numCategories, int numContentPerCategory);

int main() {
    int numUsers = 2;
    int numCategories = 3;    // Action, Drama, Comedy
    int numDevices = 2;       // Smart TV, Smartphone
    int numSettings = 3;      // Resolution, Bandwidth, Playback Position
    int numContentPerCategory = 2;

    // Allocate the engagement matrix
    double** engagementMatrix = allocateEngagementMatrix(numUsers, numCategories);

    // Allocate the device matrix
    double*** deviceMatrix = allocateDeviceMatrix(numUsers, numDevices, numSettings);

    // Allocate the content metadata matrix
    ContentMetadata*** contentMatrix = allocateContentMatrix(numCategories, numContentPerCategory);

    // Initialize engagement matrix
    printf("Initializing Engagement Matrix...\n");
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numCategories; j++) {
            engagementMatrix[i][j] = 0.0;  // Initial engagement score
        }
    }

    // Add content metadata
    printf("Adding Content Metadata...\n");
    strcpy(contentMatrix[0][0]->title, "Action Movie 1");
    contentMatrix[0][0]->rating = 8.5;
    contentMatrix[0][0]->runtime = 120;
    strcpy(contentMatrix[0][0]->encoding, "HD");

    strcpy(contentMatrix[0][1]->title, "Action Movie 2");
    contentMatrix[0][1]->rating = 7.8;
    contentMatrix[0][1]->runtime = 150;
    strcpy(contentMatrix[0][1]->encoding, "4K");

    // Update engagement score
    printf("Updating Engagement Score...\n");
    engagementMatrix[0][1] += 5.5;  // User 0, Category 1 (Drama)

    // Display engagement matrix
    printf("\nEngagement Matrix:\n");
    displayEngagementMatrix(engagementMatrix, numUsers, numCategories);

    // Display content metadata
    printf("\nContent Metadata:\n");
    displayContentMatrix(contentMatrix, numCategories, numContentPerCategory);

    // Free all dynamically allocated memory
    freeEngagementMatrix(engagementMatrix, numUsers);
    freeDeviceMatrix(deviceMatrix, numUsers, numDevices);
    freeContentMatrix(contentMatrix, numCategories, numContentPerCategory);

    return 0;
}

// Function to allocate engagement matrix
double** allocateEngagementMatrix(int numUsers, int numCategories) {
    double** matrix = (double*)malloc(numUsers * sizeof(double));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (double*)malloc(numCategories * sizeof(double));
    }
    return matrix;
}

// Function to allocate device matrix
double*** allocateDeviceMatrix(int numUsers, int numDevices, int numSettings) {
    double*** matrix = (double*)malloc(numUsers * sizeof(double**));
    for (int i = 0; i < numUsers; i++) {
        matrix[i] = (double*)malloc(numDevices * sizeof(double));
        for (int j = 0; j < numDevices; j++) {
            matrix[i][j] = (double*)malloc(numSettings * sizeof(double));
        }
    }
    return matrix;
}

// Function to allocate content matrix
ContentMetadata*** allocateContentMatrix(int numCategories, int numContentPerCategory) {
    ContentMetadata*** matrix = (ContentMetadata*)malloc(numCategories * sizeof(ContentMetadata**));
    for (int i = 0; i < numCategories; i++) {
        matrix[i] = (ContentMetadata*)malloc(numContentPerCategory * sizeof(ContentMetadata));
        for (int j = 0; j < numContentPerCategory; j++) {
            matrix[i][j] = (ContentMetadata*)malloc(sizeof(ContentMetadata));
        }
    }
    return matrix;
}

// Function to free engagement matrix
void freeEngagementMatrix(double** matrix, int numUsers) {
    for (int i = 0; i < numUsers; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to free device matrix
void freeDeviceMatrix(double*** matrix, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

// Function to free content matrix
void freeContentMatrix(ContentMetadata*** matrix, int numCategories, int numContentPerCategory) {
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContentPerCategory; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

// Function to display engagement matrix
void displayEngagementMatrix(double** matrix, int numUsers, int numCategories) {
    for (int i = 0; i < numUsers; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < numCategories; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to display content metadata
void displayContentMatrix(ContentMetadata*** matrix, int numCategories, int numContentPerCategory) {
    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContentPerCategory; j++) {
            printf("Category %d, Content %d: %s, Rating: %.1f, Runtime: %d mins, Encoding: %s\n",
                   i + 1, j + 1, matrix[i][j]->title, matrix[i][j]->rating,
                   matrix[i][j]->runtime, matrix[i][j]->encoding);
        }
    }
}