/*3.Using * (Dereference) Operator
Goal: Learn how to access or modify a variable's value using a pointer.

Activity:

Declare int a = 10;
Log Session int *p = &a;
Change the value at the pointer: *p = 20;
Print a and *p to verify both are 20.*/
#include<stdio.h>
int main()
{
    int a=10;
    int *p=&a;
    printf("Before modifying: %d  %d\n",a,*p);
    *p=20;
    printf("After modifying: %d  %d\n",a,*p);
}