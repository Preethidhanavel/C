/*5.For a number that has exactly one set bit (i.e., is a power of two), find the position/index of that set bit.*/
#include<stdio.h>
void find_index(int n)
{
    int i,c=0;
    for(i=0;i<32;i++)
    {
        if((n>>i)&1)
            c=i;
    }
    
        printf("The position is %d\n",c);
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    find_index(n);
}