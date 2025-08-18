//2.Sort an array of strings in alphabetical order. The sorted array should list strings from A to Z.
//input: {"John", "Alice", "Bob"}
//Output: {"Alice", "Bob", "John"}
#include<stdio.h>
#include<string.h>
void sort_str(char (*s)[50],int n)
{
 int i,j;
 char temp[50];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(strcmp(s[i],s[j])>0)
            {
                strcpy(temp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],temp);
            }
        }
    }
    printf("After Sorting:\n");
    for(i=0;i<n;i++)
    printf("%s ",s[i]);
}
int main()
{
    int n;
    printf("Enter the number of string\n");
    scanf("%d",&n);
    int i;
    char s[n][50];
    printf("Start to enter the string\n");
    for(i=0;i<n;i++)
    scanf("%s",s[i]);
    sort_str(s,n);
}
   