//6.Design a program to concatenate two strings without using standard library functions, only pointers.
#include<stdio.h>

void concat(char *dest,char *src)
{
    while(*dest)
    {
       dest++;
    }
    while(*src) 
    {
     *dest++ = *src++;
    }
    *dest = '\0';
}

int main(){
    char s1[100],s2[50];
    printf("Enter first string:");
    scanf("%s",s1);
    printf("Enter second string:");
    scanf("%s",s2);
    concat(s1,s2);
    printf("Concatenated string:%s\n",s1);
}
