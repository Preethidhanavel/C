/*5. Variadic Character Count Challenge

Description
Write a C program to count the number of characters in a variable number of strings passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to access each string and strlen() to count their lengths.

Sample Input & Output
Function call:
count_characters(3, "BitLearn", ".", "Bitsilica")
Output:
The total number of characters is 17

Explanation
The first argument is the count of strings, followed by the strings. Their lengths are summed*/



#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void count_characters(int count, ...) 
{
    int total = 0;
    va_list args;

    va_start(args, count);

    for (int i = 0; i < count; i++) 
    {
        const char *str = va_arg(args, const char*);
        total += strlen(str);
    }

    va_end(args);

    printf("The total number of characters is %d\n", total);
}

int main() 
{
    count_characters(3, "BitLearn", ".", "Bitsilica");
    return 0;
}
