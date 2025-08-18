/*14.Given a number, find the next smallest number larger than it that has the same count of set bits.*/


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
int next_smallest(int x)
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
    printf("smallest next num:%d\n", next_smallest(x));
}