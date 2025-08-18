/*2.Program: Remove all repeated characters from a given string
         Input: "programming"

        Output: "progamin"*/
#include<stdio.h>
#include<string.h>
void remove_repeated(char *s)
{
                int i,j,k;
            int n=strlen(s);
            for(i=0;i<n;i++)
            {
                for(j=i+1;j<n;)
                {
                    if(s[i]==s[j])
                    {
                        for(k=j;k<n;k++)
                            s[k]=s[k+1];
                        n--;
                    }
                    else
                        j++;
                }

            }

}
void remove_repeat(char *s)
{
                int i,j=0;
                int b[140]={0};
                for(i=0;s[i];i++)
                {
                    char c=s[i];
                    if(!b[c])
                    {
                        s[j++]=s[i];
                        b[c]=1;
                    }

                }
                s[j]='\0';

}

int main()
{
                char s[100];
                printf("Enter the string\n");
                scanf("%[^\n]",s);
                remove_repeat(s);
                printf("After removing repeated elements %s\n",s);
}