//8.Check if one string is a rotation of another, i.e., one string can be shifted to get the other.
//Input: "abcd", "cdab"
//Output: Yes
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int check(const char *s1, const char *s2) 
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    char *c= (char *)malloc(2 * len1 + 1);
    if (!c) 
        return 0;

    strcpy(c, s1);
    strcat(c, s1);

    int x = strstr(c, s2) != NULL;

    free(c); 
    return x;
}

int main()
{
char a[100],b[100];
printf("Enter the string  1 and 2\n");
scanf("%s%s",a,b);
    if(strlen(a)==strlen(b))
    {
        int n=check(a,b);
            if(n==1)
            {
                printf("the string 1 is rotation of other string2\n");
            }
            else
                printf("The string is not a rotation of other\n");
    }
    else
        printf("the string length doesn't match\n");
}
