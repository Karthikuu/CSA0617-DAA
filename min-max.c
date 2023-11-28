#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int n) {
    int i, j, minIndex;

    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}
void findMthMaxAndNthMin(int arr[], int n, int m, int nth, int *mthMax, int *nthMin) {
    selectionSort(arr, n);
 *mthMax = arr[n - m];
*nthMin = arr[nth - 1];
}

int main() {
    int n, m, nth;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
     printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the values of m and nth: ");
    scanf("%d %d", &m, &nth);
    int mthMax, nthMin;
    findMthMaxAndNthMin(arr, n, m, nth, &mthMax, &nthMin);
     int sum = mthMax + nthMin;
    int diff = mthMax - nthMin;
    printf("mth maximum: %d\n", mthMax);
    printf("nth minimum: %d\n", nthMin);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    return 0;
}
