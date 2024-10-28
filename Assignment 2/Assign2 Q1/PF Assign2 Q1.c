// Roll#24k-0001 Name:Masoom Khan Assignment:2 Q1
#include <stdio.h>
//libraby for all limit of various variable types
#include <limits.h>
//start main
int main() {
    int arr[5];
    int i, smallest, smallest2;
	//inputting values of element in array
    printf("Input 5 elements in the array (value must be <9999):\n");
    for (i = 0; i < 5; i++) {
        printf("element - %d: ", i);
        scanf("%d", &arr[i]);
        //checking condition
        if (arr[i] >= 9999) {
            printf("Value must be less than 9999. Exiting.\n");
            return 1;
        }
    }

    // Initialize smallest and 2nd_smallest to maximum integer value
    smallest = INT_MAX;
    smallest2 = INT_MAX;

    // Find the smallest and second smallest elements
    for (i = 0; i < 5; i++) {
        if (arr[i] < smallest) {
            smallest2 = smallest;
            smallest = arr[i];
        } else if (arr[i] < smallest2 && arr[i] != smallest) {
            smallest2 = arr[i];
        }//end else if
    }//end for
      //for all element having same value 
    if (smallest2 == INT_MAX) {
        printf("There is no second smallest element in the array.\n");
    } else {
        printf("The Second smallest element in the array is: %d\n", smallest2);
    }//end else if

    return 0;
}
//end main
