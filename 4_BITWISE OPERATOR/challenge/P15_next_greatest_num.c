/*15.Given a number, find the immediate next greater number that has the same number of 1s in its binary representation.*/
#include<stdio.h>
int count(unsigned int n) 
{
    int c=0;
    for(int i=0;i<=31;i++) 
    {
        if((n>>i)&1)
            c++;
    }
   return c;
}
int next_greatest(int x)
{
    int t = count(x);
    unsigned int y = x+1;
    while(count(y) != t) {
        y++;
    }
    return y;
}


int main()
{ 
    int x;
    printf("enter num: ");
    scanf("%d", &x);
    printf("greatest next num:%d\n", next_greatest(x));
}