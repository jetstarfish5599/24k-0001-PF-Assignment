// Roll#24k-0001 Name:Masoom Khan Assignment:2 Q2
#include <stdio.h>
#include <string.h>
// Define maximum possible characters
#define MAX_CHAR 256 

// Function to calculate characters
void charFrequency(const char *slogan) {
    // Array to store each character
    int freq[MAX_CHAR] = {0}; 

    // Calculate number of each character in the slogan from 0 to 255
    for (int i = 0; slogan[i] != '\0'; i++) {
       //unsigned char is for all ASCll characters
        freq[(unsigned char)slogan[i]]++;
    }

    // Print the character number
    printf("Character frequencies for \"%s\": {", slogan);
    int first = 1; // To control comma placement
    for (int i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > 0) {
            if (!first) {
                printf(", ");
            }
            printf("'%c': %d", i, freq[i]);
            first = 0;
        }
    }
    printf("}\n");
}
//start main
int main() {
    // List of slogans
    const char *slogans[] = {"buy now", "save big", "limited offer"};
    int sloganCount = sizeof(slogans) / sizeof(slogans[0]);

    // check  each slogan
    for (int i = 0; i < sloganCount; i++) {
        charFrequency(slogans[i]);
    }

    return 0;
}
//end main
