#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Please enter at least two elements.\n");
        return 1;
    }

    int min1 = INT_MAX;  // Initialize to maximum possible integer value
    int min2 = INT_MAX;  // Initialize to maximum possible integer value

    printf("Enter the elements:\n");

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        // Update min1 and min2 based on the current input
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2 && num != min1) {
            min2 = num;
        }
    }

    // Check if two distinct minimum values were found
    if (min1 == INT_MAX || min2 == INT_MAX) {
        printf("Unable to find two distinct minimum values.\n");
    } else {
        printf("First minimum value: %d\n", min1);
        printf("Second minimum value: %d\n", min2);
    }

    return 0;
}