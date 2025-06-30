/*8.Implement your own version of strlen() using only pointer arithmetic and no index or library functions.*/


#include<stdio.h>

int my_strlen(char *str) 
{
    char *p = str;
    while (*p) 
    {
        p++;
    }
    return p - str;
}

int main()
{
    char str[50];
    printf("enter string:");
    scanf("%s",str);
    printf("length: %d\n", my_strlen(str)); 
    return 0;

}
