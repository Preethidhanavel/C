/*15.Write a program to multiply a number by 9 using bitwise shift operations.*/
#include<stdio.h>
void multi_9(int n)
{
    printf("%d\n",(n<<3)+n);
}
int main()
{
    int n;
    printf("Enter the integer\n");
    scanf("%d",&n);
    multi_9(n);
}