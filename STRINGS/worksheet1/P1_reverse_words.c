/*1.Program: Reverse order of words in a given string
          Input: "hello world from C"

         Output: "C from world hello"*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse_words_str(char *s)
{
            //printf("\nstart.%s\n",s);
            int count=0,n=strlen(s);
            char *a[100];
            char *token=strtok(s," ");
            while(token!=NULL)
            {
                a[count++]=token;
                token=strtok(NULL," ");
            }
            int i;
            char temp[100];
            for(i=count-1;i>=0;i--)
            {
                strcat(temp,a[i]);
                strcat(temp," ");
                //printf("\n%d.%s\n",i,temp);
                //printf("%s ",a[i]);
            }
            strcpy(s,temp);
}
int main()
{
          int n;
          //printf("Enter the maximum sizeof string you want to enter\n");
          //  scanf("%d",&n);
          //char *s=(char *)malloc(n*sizeof(char));
          char s[100];
          printf("Enter the string to reverse the words\n");
          scanf(" %[^\n]",s);
          reverse_words_str(s);
          printf("\nin main:%s\n",s);
}