/*18. Program: Trim both leading and trailing white space characters from given string
        Input: " Hello World "

        Output: "Hello World"*/
#include<stdio.h>
#include<string.h>
void remove_lead_trailing_space(char *a)
{
        int i,k,l=strlen(a);
        for(i=0;i<l;i++)
        {
                if((i==0)||(i==l-1))
                {
                        if(a[i]==' ')
                        {
                                for(k=i;a[k];k++)
                                        a[k]=a[k+1];
                        --i;
                        --l;
                        }
                }
        }

}
int main()
{
        char a[100];
        printf("Enter the string\n");
        scanf("%[^\n]",a);
        printf("Before removing space:\"%s\"\n",a);
        remove_lead_trailing_space(a);
        printf("After removing space:\"%s\"\n",a);

}
