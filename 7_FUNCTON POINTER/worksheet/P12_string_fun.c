/*12.Function Pointer Array for String Operations
Implement several string manipulation functions (reverseString, toUpperCase, countVowels), each accepting a string argument.
Store these functions in an array of function pointers.
Prompt the user to choose an operation and apply it to their input string using the selected function pointer.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverseString(char *str);
void toUpperCase(char *str);
void countVowels(char *str);

typedef void (*StringFunction)(char *);

void reverseString(char *str) 
{
    int j = strlen(str)-1;
    for (int i = 0; i < j ; i++,j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    printf("Reversed String: %s\n", str);
}

void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    printf("Uppercase String: %s\n", str);
}

void countVowels(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    printf("Number of vowels: %d\n", count);
}

int main() {
    StringFunction operations[] = { reverseString, toUpperCase, countVowels };
    int choice;
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    printf("\nChoose an operation:\n");
    printf("0. Reverse String\n");
    printf("1. Convert to Uppercase\n");
    printf("2. Count Vowels\n");
    printf("Enter your choice (0-2): ");
    scanf("%d", &choice);
    getchar();

    if (choice >= 0 && choice < 3) {
        operations[choice](input);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
