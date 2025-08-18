/*12.Design a program that checks if a string is a prefix of another string using pointers.*/
#include <stdio.h>

int isPrefix(const char* prefix, const char* str) 
{
    while (*prefix) {
        if (*prefix != *str) {
            return 0;
        }
        prefix++;
        str++;
    }
    return 1;
}

int main() 
{
    const char* fullString = "OpenAI_GPT";
    const char* testPrefix1 = "Open";
    const char* testPrefix2 = "GPT";

    if (isPrefix(testPrefix1, fullString)) 
    {
        printf("\"%s\" is a prefix of \"%s\"\n", testPrefix1, fullString);
    } 
    else 
    {
        printf("\"%s\" is NOT a prefix of \"%s\"\n", testPrefix1, fullString);
    }

    if (isPrefix(testPrefix2, fullString)) 
    {
        printf("\"%s\" is a prefix of \"%s\"\n", testPrefix2, fullString);
    } 
    else 
    {
        printf("\"%s\" is NOT a prefix of \"%s\"\n", testPrefix2, fullString);
    }

    return 0;
}
