/*17.Program: Find last occurrence of a character in a string
        Input: "ababcabc", find 'b'

        Output: Position: 6*/
#include<stdio.h>
#include<string.h>
void find_last_occur(char *s,char c)
{
            int i;
        for(i=strlen(s)-1;i>=0;i--)
        {
            if(s[i]==c)
            {
                printf("The character is found at %d\n",i);
                break;
            }
        }

}
int main()
{
        char a[100],c;
        printf("Enter the string\n");
        scanf("%s",a);
        printf("Enter the character \n");
        scanf(" %c",&c);
        find_last_occur(a,c);

}