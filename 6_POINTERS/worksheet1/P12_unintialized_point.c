/*12. Garbage Pointer
Goal: Understand what happens when a pointer is used without initialization.

Activity:

Declare an uninitialized pointer int *p;
Try printing *p and observe the issue (garbage value or crash).
Then fix by assigning a valid address.*/

#include<stdio.h>

int main()
{
int *p;
//printf("*p=%d\n",*p); 

int a=10;
p=&a;
printf("*p=%d\n",*p);

}
