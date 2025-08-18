//12.Find the first non-repeating character in a string and print it.
//Input:swiss
//Output:w

#include<stdio.h>
#include<string.h>

void first_non_repeat(char *s)
{
    int i,j,c=0,freq[256]={0};
    for(i=0;s[i];i++)
        freq[s[i]]++;
    for(i=0;s[i];i++)
    {
        if(freq[s[i]]==1)
        {
            printf("First occurance is %c \n",s[i]);
            break;    
        }
    }
}
int main()
{
    char s[100];
    printf("Enter the string:\n");
    scanf("%s",s);
    first_non_repeat(s);
}