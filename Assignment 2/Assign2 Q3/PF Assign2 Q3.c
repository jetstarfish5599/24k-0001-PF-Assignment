// Roll#24k-0001 Name:Masoom Khan Assignment:2 Q3
#include <stdio.h>
#include <string.h>

// Function to compress a word 
void compressWord(const char *word, char *compressed, int *charsRemoved) {
    int length = strlen(word);
    int j = 0;
    *charsRemoved = 0;

    // check through the word and copy only non-duplicate characters
    for (int i = 0; i < length; i++) {
        // If current character is different from the last added to compressed
        if (i == 0 || word[i] != word[i - 1]) {
            compressed[j++] = word[i];
        } else {
            // Count removed characters
            (*charsRemoved)++; 
        }//end if else
    }//end for
     // Null-terminate the compressed word
    compressed[j] = '\0'; 
}
//start main
int main() {
    const char *words[] = {"booooook", "coooool", "heeeey"};
    int wordCount = sizeof(words) / sizeof(words[0]);
    char compressed[100]; // Buffer for the compressed word
    int totalRemoved = 0, charsRemoved;

    printf("Compressed Words:\n");
    //checking word for compression
    for (int i = 0; i < wordCount; i++) {
        compressWord(words[i], compressed, &charsRemoved);
        totalRemoved += charsRemoved;
   //display output
        printf("Original: %s, Compressed: %s, Characters Removed: %d\n", words[i], compressed, charsRemoved);
    }//end for
     //number of char removed
    printf("Total Characters Removed: %d\n", totalRemoved);

    return 0;
}
