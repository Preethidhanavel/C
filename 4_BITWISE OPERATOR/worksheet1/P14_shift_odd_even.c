/*14.Write a program to reverse:
Bits at odd positions
Bits at even positions*/

#include<stdio.h>
void binary(int n)
{
     int i;
        for(i=31;i>=0;i--)
            printf("%d",(n>>i)&1);
        printf("\n");
}
void shift(int n,int i,int j)
{
    int x,y;
    for(;i<j;){

        x=(n>>i)&1;
        y=(n>>j)&1;
        if(x!=y)
        {
            n=n^(1<<i);
            n=n^(1<<j);
        }
        i=i+2;
        j=j-2;
    }
 binary(n);
}
int main()
{
    int n;
    printf("Enter the numbers\n");
    scanf("%d",&n);
    binary(n);
    printf("Shift bits at odd position\n");
    shift(n,1,31);
    printf("\n");
    printf("Shift bits at even position\n");
    shift(n,0,30);
    printf("\n");
    
}