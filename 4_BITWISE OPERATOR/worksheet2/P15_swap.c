/*15.Swap two numbers using bitwise operator
Question: Write a C program to swap two numbers using bitwise XOR operator without using a temporary variable.
Sample data: Input: a=5, b=9
Expected output: After swapping: a=9, b=5*/

#include<stdio.h>
void swap(int n,int m)
{
     printf("Befor swapping n= %d m= %d\n",n,m);

    n^=m;
    m^=n;
    n^=m;
    printf("After swapping n= %d m= %d\n",n,m);

}
int main()
{
    int n,m;
    printf("Enter the two integer values\n");
    scanf("%d%d",&n,&m);
    swap(n,m);
}