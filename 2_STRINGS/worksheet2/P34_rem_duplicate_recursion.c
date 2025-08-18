//34.Recursively remove all adjacent duplicate characters from a string until no duplicates remain.
//Input: "azxxzy"
//Output: "ay"

#include<stdio.h>
void remove_duplicate(char *s)
{

            int i,j,k=0;
            for(i=0;s[i];i++){
                if(s[i]==s[i+1])
                {  
                    while(k<2)
                    {
                        for(j=i;s[j];j++)
                            s[j]=s[j+1];
                         k++;
                    } 
                 break;
                }
            }
                    if(k==0)
                     return;
        remove_duplicate(s);
}
int main()
{
    char s[100];
    printf("Enter the string:");
    scanf("%s",s);
    remove_duplicate(s);
    printf("After removing duplicate %s\n",s);
}