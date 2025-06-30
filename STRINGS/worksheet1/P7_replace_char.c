/*7.Program: Replace all occurrences of a character with another in a string
         Input: "banana", replace 'a' with 'o'

         Output: "bonono"*/
#include<stdio.h>
void replace_char(char *a,char c,char c1)
{
        int i;
        for(i=0;a[i];i++)
        {
            if(a[i]==c)
                a[i]=c1;    
        }
}
int main()
{
        char a[100],c,c1;
        printf("Enter the string\n");
        scanf("%[^\n]",a);
        printf("Enter which character you want to replace with new character\n");
        scanf(" %c %c",&c,&c1);
        replace_char(a,c,c1);
        printf("After replacing char %c with %c is:%s\n",c,c1,a);

}