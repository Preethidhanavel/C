/*7.Given two integers, 
calculate how many bits differ between them (i.e., bits that need flipping to convert one number into the other).*/
#include<stdio.h>
int main()
{
    int a,b,x,y,c=0,i;
    printf("Enter the two integers\n");
    scanf("%d%d",&a,&b);
    for(i=0;i<32;i++)
    {
        x=(a>>i)&1;
        y=(b>>i)&1;
        if(x!=y)
            c++;
    }
    printf("The number of bits need to be flipped %d\n",c);
    
}