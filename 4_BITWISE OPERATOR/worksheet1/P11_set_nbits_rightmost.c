/*11.Implement the function setbits(x, p, n, y) that sets n bits in x starting at position p with the rightmost n bits of y.*/

#include<stdio.h>
void binary(int n)
{
     int i;
        for(i=31;i>=0;i--)
            printf("%d",(n>>i)&1);
        printf("\n");
}
void setbits(int x,int p,int n,int y)
{
    binary(x);
    binary(y);
    int len,i,j,a,b;
    if(p+n>32)
        len=32;
    else
        len=p+n;
    
        for(j=0,i=p;(j<n)&&(i<len);j++,i++)
        {
            a=(x>>i)&1;
            b=(y>>j)&1;
            if(a!=b)
            {
                x^=1<<i;
            }
        
        }
    binary(x);
    binary(y);
}
int main()
{
    int x,y;
    printf("Enter the integer number\n");
    scanf("%d%d",&x,&y);
    int n,p;
    printf("Enter the number of bits and position\n");
    scanf("%d%d",&n,&p);
    setbits(x,p,n,y);
}