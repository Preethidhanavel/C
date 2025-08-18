/*14.Program: Replace first occurrence of a character with another in a string
         Input: "google", replace 'o' with 'a'

         Output: "gagole"*/


#include<stdio.h>
void replace_first_occurance(char *a,char c,char c1)
{
        int i;
        for(i=0;a[i];i++)
        {
            if(a[i]==c)
            { 
                a[i]=c1;
                break;
            }
        }
}
int main()
{
        char a[100],c,c1;
        printf("Enter the string\n");
        scanf(" %[^\n]",a);
        printf("Enter the character that you want to replace with new character\n");
        scanf(" %c %c",&c,&c1);
        replace_first_occurance(a,c,c1);   
        printf("After replacing %s\n",a);
}