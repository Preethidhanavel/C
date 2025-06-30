//17.Implement naive pattern searching to find all occurrences of a pattern in a text.
//Input:text="hello world"pattern="lo"
//Output:pattern found at index 3

#include<stdio.h>
#include<string.h>

void pattern(char *a,char *b)
{
    int x=strlen(a),y=strlen(b),i,j;

    for(i=0;i<=x-y;i++)
    {
        for(j=0;j<y;j++)
        {
            if(a[i+j]!=b[j])
            break;
        }
        if(j==y)
        {
            printf("Pattern found at index %d\n",i);
            return;
        }
    }
    printf("Pattern not found\n");
}

int main()
{
    char s[100], p[50];
    printf("Enter the string\n");
    scanf("%[^\n]",s);
    printf("Enter the pattern\n");
    scanf("%s",p);
    
    pattern(s,p);
}