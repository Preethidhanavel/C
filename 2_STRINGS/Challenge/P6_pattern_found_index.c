//6.Implement pattern matching using the KMP algorithm
//Explain and implement the Knuth-Morris-Pratt algorithm for substring search, focusing on preprocessing the pattern to
// avoid redundant comparisons.
//Example: Pattern: "abc"
//Text: "ababcabcab"
//Output: Pattern found at indices 2, 5

#include <stdio.h>
#include <string.h>

int main() 
{
    char s[100];
    char p[100];
    printf("Enter the string\n");
    scanf("%[^\n]",s);
    printf("Enter the pattern\n");
    scanf(" %[^\n]",p);

    char *pos = strstr(s,p);
    if (pos != NULL) {
        printf("Pattern found at index %ld  %ld\n", pos - s,pos-s+strlen(p));
    } else {
        printf("Pattern not found\n");
    }
    return 0;
}