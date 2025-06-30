/*17.Write a program to convert a Little Endian integer to its Big Endian equivalent.*/
#include<stdio.h>
void binary(int n)
{
     int i;
        for(i=31;i>=0;i--)
        printf("%d",(n>>i)&1);
        printf("\n");
}
int little_to_big(int n)
{

      return ((n >> 24) & 0x000000FF) |   ((n >> 8)  & 0x0000FF00) | ((n << 8)  & 0x00FF0000)  |((n << 24) & 0xFF000000);  
    
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    binary(n);
    n=little_to_big(n);
    binary(n);
}