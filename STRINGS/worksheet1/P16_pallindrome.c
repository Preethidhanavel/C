/*16.Program: Check whether a string is palindrome or not
        Input: "madam"

       Output: "Palindrome"*/
#include<stdio.h>
void pallindrome(char *a)
{
            int i,j;
            for(i=0,j=strlen(a)-1;i<j;i++,j--)
                if(a[i]!=a[j])
                        break;
            if(i<j)
                 printf("The string is not a pallindrome\n");
            else 
                printf("the string is a pallindrome\n");
}
int main()
{
        char a[100];
        printf("Enter the string\n");
        scanf("%s",a);
        pallindrome(a);

}