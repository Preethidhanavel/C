/*16.Write a program to determine the size (in bits) of an integer using bit shifts.*/
#include<stdio.h>
void size_bits(int n)
{
    int x,c=1;
    while(x!=0)
    {
        x<<=1;
         c++;
    }
    printf("The size of integer in biits %d\n",c);
}
int main()
{
    int n;
    printf("Enter the number\n");
    scanf("%d",&n);
    size_bits(n);
}