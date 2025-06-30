/*13.Given a list of strings and a word, print the strings containing all characters of that word.
Input: Word = "act", List = ["cat", "tac", "act", "dog"]
Output: "cat", "tac", "act"*/
#include<stdio.h>

int check(char *a,char* b)
{
    int i,j,q;
    for(i=0;b[i];i++)
    {
        q=0;
        for(j=0;a[j];j++)
        {
            if(a[j] == b[i])
            {
                q=1;
                break;
            }
        }
        if(!q)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    printf("Enter the number of string\n");
    scanf("%d",&n);
    char s[n][100];
    char w[100];
    printf("Enter word:\n");
    scanf("%s",w);
    int i;
    printf("start to enter the string\n");
    for(i=0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
   for(i=0;i<n;i++)
   {
        if(check(s[i],w))
            printf("%s ",s[i]);
   }
   printf("\n");
}