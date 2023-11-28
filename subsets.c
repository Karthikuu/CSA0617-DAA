#include <stdio.h>
#include <stdbool.h>
#define MAX 100
bool isSubsetSum(int set[], int n, int sum, int currentSum, int index, bool subset[]) {
    if (currentSum == sum) {
        printf("Subset with the sum %d is: { ", sum);
        for (int i = 0; i < n; i++) {
            if (subset[i]) {
                printf("%d ", set[i]);
            }
        }
        printf("}\n");
        return true;
    }
    if (index == n) {
        return false;
    }
    subset[index] = true;
    if (isSubsetSum(set, n, sum, currentSum + set[index], index + 1, subset)) {
        return true;
    }
    subset[index] = false;
    return isSubsetSum(set, n, sum, currentSum, index + 1, subset);
}
int main() {
    int n, set[MAX], sum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &sum);
    bool subset[MAX] = {false};
    if (!isSubsetSum(set, n, sum, 0, 0, subset)) {
        printf("No subset with the sum %d found.\n", sum);
    }
}