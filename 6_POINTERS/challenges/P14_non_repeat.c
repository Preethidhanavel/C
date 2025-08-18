//14.Implement a program that finds the first non-repeated character in a string using pointers.
#include <stdio.h>

char firstNonRepeatedChar(char *str) {
    char *ptr1, *ptr2;
    int count;

    for (ptr1 = str; *ptr1 != '\0'; ptr1++) {
        count = 0;
        for (ptr2 = str; *ptr2 != '\0'; ptr2++) {
            if (*ptr2 == *ptr1) {
                count++;
            }
        }
        if (count == 1) {
            return *ptr1;
        }
    }
    return '\0';
}

int main() {
    char str[] = "swiss";

    char result = firstNonRepeatedChar(str);

    if (result != '\0') {
        printf("First non-repeated character: %c\n", result);
    } 
    else {
        printf("No non-repeated character found.\n");
    }

    return 0;
}
