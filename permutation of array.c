#include <stdio.h>

// Function to swap the values of two variables
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate all permutations
void generatePermutations(int arr[], int start, int end) {
    if (start == end) {
        // Print the current permutation
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        // Generate permutations with each element at the start position
        for (int i = start; i <= end; i++) {
            // Swap the current element with the element at the start position
            swap(&arr[start], &arr[i]);

            // Recursively generate permutations for the remaining elements
            generatePermutations(arr, start + 1, end);

            // Backtrack by swapping back to the original arrangement
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nAll permutations of the array:\n");
    generatePermutations(arr, 0, n - 1);

    return 0;
}