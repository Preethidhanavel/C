//27.Count the number of words in a string separated by space
//Input:"Hello World"
//Output:2

#include <stdio.h>

int main() {
    char s[100];
    int i = 0, count = 0;

    printf("Enter the stirng\n");
    scanf("%[^\n]",s);
    while (s[i]) {
        if ((s[i] != ' ' && s[i] != '\n') && 
            (s[i + 1] == ' ' || s[i + 1] == '\n' || s[i + 1] == '\0')) {
            count++;
        }
        i++;
    }

    printf("Output: %d\n", count);
    return 0;
}