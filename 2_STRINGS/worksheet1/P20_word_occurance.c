/*20. Program: Find all occurrences of a word in given string
        Input: "the sky is the limit in the sky", search "the"

       Output: Found at positions: 0, 15, 30*/
#include<stdio.h>
#include<string.h>
void word_occurance(char *a,char *b)
{
        char *t=strtok(a," ");
        while(t!=NULL)
        {
            if(strcmp(t,b)==0)
                    printf(" %d\n",t-a);
            t=strtok(NULL," ");
        }

}
int main()
{
        char a[100],b[50];
        printf("Enter the string\n");
        scanf(" %[^\n]",a);
        printf("Enter the word\n");
        scanf("%s",b);
        word_occurance(a,b);

}