/*10. Program: Remove all occurrence of a word in given string
           Input: "hello world hello universe", remove: "hello"
          Output: "world universe"*/
#include<stdio.h>
#include<string.h>
void remove_word(char *a,char *b)
{
        int n=strlen(b),i,j=0;
        char *s=strstr(a,b);
        if(s==NULL)
            return;
            while(j<n)
            {
                for(i=s-a;a[i];i++)
                {
                    a[i]=a[i+1];
                }
                j++;
            }
        remove_word(a,b);
}
int main()
{
        char a[100],b[50];
        printf("Enter the string\n");
        scanf("%[^\n]",a);
        printf("Enter the substring\n");
        scanf(" %[^\n]",b);
        remove_word(a,b);
        printf("After removing the word %s from string:%s\n",b,a);
}