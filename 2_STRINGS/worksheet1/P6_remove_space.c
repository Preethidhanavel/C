/*6.Program: Remove all extra blank spaces from a given string
         Input: " This is ChatGPT "

         Output: "This is ChatGPT"*/
#include<stdio.h>
#include<string.h>
void remove_space(char *a)
{
        int i,k;
        for(i=0;a[i];i++)
        {
                if((a[i]==' ')&&(a[i+1]==' '))
                {
                        for(k=i;a[k];k++)
                                a[k]=a[k+1];
                        i--;
                }
                if((i==0)||(i==strlen(a)-1))
                {
                        if(a[i]==' ')
                                for(k=i;a[k];k++)
                                        a[k]=a[k+1];
                }
        }

}
int main()
{
        char a[100];
        printf("Enter the string\n");
        scanf("%[^\n]",a);
        printf("Before removing space:\"%s\"\n",a);
        remove_space(a);
        printf("After removing space:\"%s\"\n",a);

}
