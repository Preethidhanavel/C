/*8.Write a C program to count the number of bits set to 1 in an integer. Also compare different methods. Additionally, 
check if the 20th bit of a 32-bit integer is set.*/
#include<stdio.h>
void check_setbit(int n)
{
    int i,c=0;
    for(i=0;i<32;i++)
    {
        if((n>>i)&1)
            c++;
    }
    printf("number of bits set is %d\n",c);
    if((n>>20)&1)
        printf("The 20th bit of integer is set\n");
    else
        printf("The 20th bit is not set\n");
}
int main()
{
    int n;
    printf("Enter the integer value\n");
    scanf("%d",&n);
    check_setbit(n);
}