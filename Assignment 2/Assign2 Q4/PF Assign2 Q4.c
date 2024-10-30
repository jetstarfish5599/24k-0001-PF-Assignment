// Roll#24k-0001 Name:Masoom Khan Assignment:2 Q4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define MAX_LENGTH 100

// Function to compare two characters (used in sorting)
int charCompare(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

// Function to sort a string and return the sorted result
void sortString(char *str, char *sortedStr) {
    // Copy original string to preserve it
    strcpy(sortedStr, str); 
    // Sort characters
    qsort(sortedStr, strlen(sortedStr), sizeof(char), charCompare); 
}

// Function to group anagrams
void groupAnagrams(char transactions[][MAX_LENGTH], int size) {
    int i, j;
    char sortedTransactions[MAX_TRANSACTIONS][MAX_LENGTH];
    // check transactions
    int visited[MAX_TRANSACTIONS] = {0}; 

    // Sort each transaction string and store in sortedTransactions
    for (i = 0; i < size; i++) {
        sortString(transactions[i], sortedTransactions[i]);
    }

    // Group anagrams
    printf("Grouped Transactions:\n");
    for (i = 0; i < size; i++) {
       // Skip if already grouped
        if (visited[i]) continue; 
        printf("[");
        printf("%s", transactions[i]);
        visited[i] = 1;

        for (j = i + 1; j < size; j++) {
            if (!visited[j] && strcmp(sortedTransactions[i], sortedTransactions[j]) == 0) {
                printf(", %s", transactions[j]);
                visited[j] = 1;
            }//end if
        }//end for
        printf("]\n");
    }
}//end for
//start main
int main() {
    char transactions[][MAX_LENGTH] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int size = sizeof(transactions) / sizeof(transactions[0]);

    groupAnagrams(transactions, size);

    return 0;
}
//end main
