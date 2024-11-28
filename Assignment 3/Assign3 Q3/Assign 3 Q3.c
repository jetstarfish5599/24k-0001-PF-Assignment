// Roll#24k-0001 Name:Masoom Khan Assignment:3 Q3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate the email address
int validateEmail(char* email) {
    // Check if the email is non-empty
    if (email == NULL || strlen(email) == 0) {
        return 0;
    }

    int atCount = 0;  // Counter for '@' symbols
    int dotAfterAt = 0;  // Flag for '.' after '@'
    char *atPosition = NULL;

    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            atCount++;
            atPosition = &email[i];
        }
    }

    // Ensure one '@' symbol
    if (atCount != 1) {
        return 0;
    }

    // Check for at least one '.' after the '@'
    if (atPosition != NULL) {
        for (char *p = atPosition + 1; *p != '\0'; p++) {
            if (*p == '.') {
                dotAfterAt = 1;
                break;
            }
        }
    }

    // Email is valid if it has exactly there one '@' and at least one '.' after '@'
    return dotAfterAt;
}
//start main
int main() {
    char *email;
    int size;

    printf("Enter the size of the email address: ");
    scanf("%d", &size);

    // Allocate memory for the email dynamically
    email = (char *)malloc((size + 1) * sizeof(char));
    if (email == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input the email address
    printf("Enter the email address: ");
    scanf("%s", email);

    // Validate the email
    if (validateEmail(email)) {
        printf("Valid Email\n");
    } else {
        printf("Invalid Email\n");
    }

    // Free the allocated memory
    free(email);

    return 0;
}
//end main