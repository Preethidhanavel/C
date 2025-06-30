/*Use memchr to find the first occurrence of character 'e' in the string "excellent".*/

#include <stdio.h>
#include <string.h>

int main() 
{
    char str[] = "excellent";
    char ch = 'e';

    char *ptr = memchr(str, ch, strlen(str));

    if (ptr != NULL) 
    {
        printf("First occurrence of '%c' found at position: %ld\n", ch, ptr - str);
    } 
    else 
    {
        printf("Character '%c' not found.\n", ch);
    }

    return 0;
}
