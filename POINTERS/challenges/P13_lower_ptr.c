/*13.Write a function that converts a string to lowercase using pointers.*/
#include<stdio.h>
void lower_case(char *s)
{
    while(*s)
    {
        if((*s>='A')&&(*s<='Z'))
         *s^=32;
         s++;
    }
}

int main()
{
    char s[100];
    printf("Enter the string\n");
    scanf(" %[^\n]",s);
    lower_case(s);
    printf("The string after converting to lower case %s\n",s);
}