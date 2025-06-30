/*2.Using & (Address-of) Operator
Goal: Learn how to find and print the memory address of variables.
Activity:
Declare variables of different types: int x;, float y;, char z;
Print their memory addresses using &x, &y, and &z.*/
#include<stdio.h>
int main()
{
    int x;
    float y;
    char z;
    printf("%p  %p  %p\n",&x,&y,&z);
}