/*16.Log Session a program that checks if a string is a palindrome using pointers.*/

#include<stdio.h>
#include<string.h>

int palindrome(char *start,char *end){
    while(start<end){
        if(*start!=*end)
            return 0;
        start++;
        end--;
    }
    return 1;
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);

    int len=strlen(str)-1;

    if(palindrome(str,str+len))
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}
