// Roll#24k-0001 Name:Masoom Khan Assignment:2 Q5
#include <stdio.h>

// Function to print a horizontal histogram
void printHorizontalHistogram(int values[], int count) {
    printf("Horizontal Histogram:\n");
    for (int i = 0; i < count; i++) {
        printf("Value %d: ", i + 1);
        for (int j = 0; j < values[i]; j++) {
            printf("*");
        }//end for
        printf("\n");
    }//end for
}

// Function to print a vertical histogram
void printVerticalHistogram(int values[], int count) {
    int max = values[0];

    // Find the maximum value for histogram height
    for (int i = 1; i < count; i++) {
        if (values[i] > max) {
            max = values[i];
        }//end if 
    }//end for

    printf("Vertical Histogram:\n");
    for (int i = max; i > 0; i--) {
        for (int j = 0; j < count; j++) {
            if (values[j] >= i) {
                printf("* ");
            } else {
                printf("  ");
            }//end else if
        }//end for
        printf("\n");
    }//end for

    // Print base labels for each value
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }//end forr
    printf("\n");
}
//start main
int main() {
    int values[] = {3, 5, 1, 4};
    int count = sizeof(values) / sizeof(values[0]);

    // Print histograms
    printHorizontalHistogram(values, count);
    printVerticalHistogram(values, count);

    return 0;
}
//end main
