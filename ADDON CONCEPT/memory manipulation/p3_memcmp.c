/*Write a code snippet to check if two character arrays are equal using memcmp.
*/

#include <stdio.h>
#include <string.h>

int main() 
{
    char str1[] = "hello";
    char str2[] = "hello";

    if (memcmp(str1, str2, strlen(str1) + 1) == 0) 
    {
        printf("The strings are equal.\n");
    } 
    else 
    {
        printf("The strings are not equal.\n");
    }

    return 0;
}
