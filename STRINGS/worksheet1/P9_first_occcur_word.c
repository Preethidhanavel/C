/*9. Program: Find first occurrence of a word in a given string
         Input: "this is a test string", word: "test"
         Output: Found at position 11*/
#include<stdio.h>
#include<string.h>

int main()
{
    char a[100],b[50];
    printf("Enter the string\n");
    scanf("%[^\n]",a);
    printf("Enter the word you want to find \n");
    scanf("%s",b);
    char *s=strstr(a,b);
    printf("The string %s is found at %d\n",b,s-a+1);
}