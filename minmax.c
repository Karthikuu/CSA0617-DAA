#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

struct Result {
    int min;
    int max;
    int comparisons;
};

struct Result findMinMax(int arr[], int low, int high) {
    struct Result result, left, right;
    int mid;

    result.comparisons = 0;

    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    if (high == low + 1) {
        result.min = (arr[low] < arr[high]) ? arr[low] : arr[high];
        result.max = (arr[low] > arr[high]) ? arr[low] : arr[high];
        result.comparisons++;
        return result;
    }

    mid = (low + high) / 2;
    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    result.comparisons += left.comparisons + right.comparisons;

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
}

int main() {
    int n, i;
    struct Result result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 1; 
    }

    int arr[n];

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Illegal input\n");
            return 1; 
        }
    }

    result = findMinMax(arr, 0, n - 1);

    printf("Min: %d\n", result.min);
    printf("Max: %d\n", result.max);
    printf("Number of comparisons: %d\n", result.comparisons);

    return 0;
}