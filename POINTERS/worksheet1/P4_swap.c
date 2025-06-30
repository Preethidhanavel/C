/*4.Swapping Two Numbers Using Pointers
Goal: Understand how to pass variables by reference to functions using pointers.
Activity:
Write a swap function: void swap(int *a, int *b)
In main(), declare two integers and call swap(&x, &y);
Print values before and after swapping.*/

#include<stdio.h>
void swap(int * x,int *y)
{
    int c;
    c=*x;
    *x=*y;
    *y=c;
}
int main()
{
    int a,b;
    printf("Enter the two integer values\n");
    scanf("%d%d",&a,&b);
    printf("Before swapping: a=%d  b=%d\n",a,b);
    swap(&a,&b);
    printf("After swapping: a=%d  b=%d\n",a,b);
}