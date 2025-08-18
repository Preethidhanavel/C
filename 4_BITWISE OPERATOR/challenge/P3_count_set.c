/*3.Calculate the total count of set bits (1s) in the binary representation of all numbers from 1 up to a given number n.*/

#include<stdio.h>
void count(unsigned int n)
{
    int i,c=0;
    for(i=31;i>=0;i--)
    {
        if((n>>i)&1)
            c++;
    }
    printf("The numbe rof set bits in an unsigned integer is %d\n",c);
}
int main()
{
    unsigned int n,m;
    printf("Enter the range value\n");
    scanf("%d%d",&n,&m);
    unsigned int i,c=0;
    for(i=n;i<=m;i++)
        count(i);
    
}