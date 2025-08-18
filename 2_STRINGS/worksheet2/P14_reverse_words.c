//14.Reverse the order of words in a sentence without reversing the words themselves
//Input: "Hello world"
//Output: "world Hello"
#include<stdio.h>
#include<string.h>
void reverse_words(char *s)
{
    int count=0;
    char *a[100];
    char *token=strtok(s," ");
    while(token!=NULL)
    {
        a[count++]=token;
        token=strtok(NULL," ");
    }
    int i;
    for(i=count-1;i>=0;i--)
    {
        printf("%s ",a[i]);
    }


}
int main()
{
    char s[100];
    printf("Enter the String:\n");
    scanf("%[^\n]",s);
    
    //printf("%s\n",s);
    reverse_words(s);

}