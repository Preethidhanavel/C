/*Q44. First Non-Repeated Character (O(N))---------------------------------------
Problem Statement:
 Return the first character in a string that appears exactly once; return '\0' if none.*/

#include <stdio.h>

// Return the first unique character in the string 's'
// If no unique character exists, return '\0'
char first_unique(const char* s) 
{
    int c[256] = {0};   // Frequency array for all possible byte values

    // Count occurrences of each character
    for (int i = 0; s[i]; i++)
        c[(unsigned char)s[i]]++;

    // Find the first character with count 1
    for (int i = 0; s[i]; i++)
        if (c[(unsigned char)s[i]] == 1)
            return s[i];

    return '\0';        // No unique character found
}

int main(void) 
{
    printf("%c\n", first_unique("swiss"));  // Output: 'w'
    return 0;
}
