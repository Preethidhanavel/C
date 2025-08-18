/*5.Program: Reverse a string without using library functions
         Input: "OpenAI"
         Output: "IAnepO"*/
#include<stdio.h>
#include<string.h>
void reverse(char *a)
{
        char *q=a+(strlen(a)-1);
        while(a<q)
        {
                char c=*a;
                *a=*q;
                *q=c;
                a++;
                q--;
        }
}
int main()
{

        char a[100];
        printf("Enter the string\n");
        scanf("%[^\n]",a);
        reverse(a);
        printf("After reversing %s\n",a);
}