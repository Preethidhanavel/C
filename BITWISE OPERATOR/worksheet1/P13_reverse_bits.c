/*13.Write a program to reverse all bits in an integer.*/

#include<stdio.h>
void binary(int n)
{
     int i;
        for(i=31;i>=0;i--)
            printf("%d",(n>>i)&1);
        printf("\n");
}
int main()
{
    int n;
    printf("Enter the integer value\n");
    scanf("%d",&n);
    int i,j,x,y;
    binary(n);
    for(i=0,j=31;i<j;i++,j--)
    {
        x=(n>>i)&1;
        y=(n>>j)&1;
        if(x!=y){
            n=n^(1<<i);
            n=n^(1<<j);
        }
    }
    binary(n);
}