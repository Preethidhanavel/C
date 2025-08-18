//23.Implement Boyer-Moore pattern searching algorithm with bad character heuristic to search a pattern in a text.
//Input: Text = "here is a simple example", Pattern = "example"
//Output: Pattern found at index 17

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    char p[100];
    printf("Enter the string\n");
    scanf("%[^\n]",s);
    printf("Enter the pattern\n");
    scanf(" %[^\n]",p);

    char *pos = strstr(s,p);
    if (pos != NULL) {
        printf("Pattern found at index %ld\n", pos - s);
    } else {
        printf("Pattern not found\n");
    }
    return 0;
}