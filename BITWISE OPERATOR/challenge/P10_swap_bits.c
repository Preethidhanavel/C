/*10.Given a number and two bit positions, swap the bits at those positions using bitwise operations.*/

#include<stdio.h>
void binary(int n)
{ 
        int i;
        for(i=31;i>=0;i--)
            printf("%d",(n>>i)&1);
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    int i,j;
    binary(n);
    printf("\nEnter the bit position for swapping\n");
    scanf("%d%d",&i,&j);
    int x=(n>>i)&1;
    int y=(n>>j)&1;
    if(x!=y){
         n^=1<<i;
         n^=1<<j;
    }
    binary(n);
}