//3.Check if two strings are anagrams without using built-in sort
//Determine if two strings contain the exact same characters in any order, without sorting them.

//Example: Input: "listen", "silent"
//Output: true




#include<stdio.h>
#include<string.h>

void anagram(char *s,char* p)
{
    if(strlen(s)!=strlen(p))
    {
        printf("false\n");
        return;
    }

    int a[256]={0};
    int b[256]={0};
    int i;
    for(i=0;s[i];i++)
    {
        a[(unsigned char)s[i]]++;
        b[(unsigned char)p[i]]++;
    }
    for(i=0;i<256;i++)
    {
        if(a[i]!=b[i])
        {
            printf("false\n");
            return;
        }
    }
    printf("true\n");
        
}
void sort(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}
int main()
{
    char s[100],p[100];
    printf("Enter the string 1 and string 2\n");
    scanf("%[^\n]",s);
    scanf(" %[^\n]",p);
    sort(s);
    sort(p);
    anagram(s,p);
}