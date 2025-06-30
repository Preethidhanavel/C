//20.Print all possible interleavings of two strings, preserving the relative order of characters in each string.
//Input: str1 = "AB", str2 = "CD"
//Output: "ABCD", "ACBD", "ACDB", "CABD", "CADB", "CDAB"

#include<stdio.h>
#include<string.h>

void interleave_str(char *res,char* s,char* p,int i,int j,int k)
{

       if (s[i] == '\0' && p[j] == '\0') {
        res[k] = '\0'; 
        printf("%s\n", res);
        return;
    }

    
    if (s[i] != '\0') {
        res[k] = s[i];
        interleave_str(res, s, p, i + 1, j, k + 1);
    }
    if (p[j] != '\0') {
        res[k] = p[j];
        interleave_str(res, s, p, i, j + 1, k + 1);
    }

}


int main()
{
    char s[100],p[100];

    printf("Enter the string 1\n");
    scanf("%[^\n]",s);
    printf("Enter the string 2\n");
    scanf(" %[^\n]",p);
    int len=strlen(s)+strlen(p);
    char res[len+1];
    interleave_str(res,s,p,0,0,0);
}