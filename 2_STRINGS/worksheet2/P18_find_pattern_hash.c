//18.Implement Rabin-Karp algorithm using hashing to find patterns in a text efficiently.
//Input:text="abcxabcdabcdabcy" Pattern="abcdabcy"
//Output:Pattern found at index 8
#include<stdio.h>
#include<string.h>



int main()
{
    char a[100];
    printf("Enter the string\n");
    scanf("%[^\n]",a);
    char b[50];
    printf("Enter the pattern\n");
    scanf("%s",b);
    char *s=strstr(a,b);
    printf("The index is :%d\n",s-a);
}