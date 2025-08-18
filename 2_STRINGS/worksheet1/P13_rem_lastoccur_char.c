/*13.Program: Remove last occurrence of a character from string
          Input: "mississippi", remove 's'

          Output: "missipippi"*/
#include<stdio.h>
#include<string.h>
void remove_lastoccurance(char *s,char c)
{               
                int i,j;
                for(i=(strlen(s)-1);i>=0;i--)
                {
                   if(s[i]==c)
                    {
                            for(j=i;s[j];j++)
                                s[j]=s[j+1];
                            return;
                    }

            }
}
int main()
{
                char a[100],c;
                printf("Enter the string\n");
                scanf(" %[^\n]",a);
                printf("Enter the character\n");
                scanf(" %c",&c);
                remove_lastoccurance(a,c);
                printf("After removing the character:%c from string %s\n",c,a);

}