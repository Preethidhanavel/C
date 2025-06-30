/*15. Program: Count occurrences of a word in a given string
          Input: "hi hello hi hey hi", word: "hi"

         Output: 3*/
#include<stdio.h>
#include<string.h>
void count_word_occurance(char *a,char *b)
{
            int c=0;
        char *t=strtok(a," ");
        while(t!=NULL)
        {
            if(strcmp(t,b)==0)
                c++;
            t=strtok(NULL," ");
        }
        printf("The word occured %d\n",c);
}
int main()
{
        char a[100],b[50];
        printf("Enter the string\n");
        scanf(" %[^\n]",a);
        printf("Enter the word\n");
        scanf("%s",b);
        count_word_occurance(a,b);

}