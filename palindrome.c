#include <stdio.h>
#include <string.h>
#include <ctype.h>
int isNumberPalindrome(int num) {
    int reversed = 0, original = num;
    while (num > 0) {
        int remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
	    if (original == reversed) {
        return 1;
    } else {
        return 0;
    }
}
int isStringPalindrome(char str[]) {
    int length = strlen(str);
    int i, j;
    i = 0;
    j = length - 1;
    while (i < j) {
        while (!isalnum(str[i]) && i < j) {
            i++;
        }
        while (!isalnum(str[j]) && i < j) {
            j--;
        }

        if (tolower(str[i]) != tolower(str[j])) {
            return 0; 
        }

        i++;
        j--;
    }

    return 1; 
}

int main() {
    int choice, num;
    char str[100];

    printf("Enter 1 to check palindrome for a number, or 2 for a string: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &num);
            if (isNumberPalindrome(num)) {
                printf("%d is a palindrome.\n", num);
            } else {
                printf("%d is not a palindrome.\n", num);
            }
            break;
        case 2:
            printf("Enter a string: ");
            scanf("%s", str);
            if (isStringPalindrome(str)) {
                printf("%s is a palindrome.\n", str);
            } else {
                printf("%s is not a palindrome.\n", str);
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}