/*4.You’re given a double pointer char **ptr. 
How would you perform pointer arithmetic to access individual characters of a string list and reverse each string in-place?*/
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void reverseString(char *str) 
{
    if (!str)
        return;

    char *start = str;
    char *end = str + strlen(str) - 1;

    while (start < end) 
    {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

void reverseStringList(char **ptr, int count) 
{
    for (int i = 0; i < count; i++) 
    {
        reverseString(*(ptr + i));
    }
}

int main() 
{
    int n;
    printf("Enter the number of strings:\n");
    scanf("%d", &n);

    char **strings=malloc(n*sizeof(char *));
     printf("Enter strings:\n");
    for (int i = 0; i < n; i++) 
    {
        strings[i]=malloc(50);
        scanf("%s", strings[i]);
    }

    reverseStringList(strings, n);

    for (int i = 0; i < n; i++) 
    {
        printf("%s ", strings[i]);
    }

}

