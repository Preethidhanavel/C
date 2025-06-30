/*10. Visualizing Memory Addresses
Goal: Visualize how memory is arranged for variables.

Activity:

Declare three local variables.
Print their addresses using printf.
Observe the increasing/decreasing pattern.*/


#include<stdio.h>

int main()
{
    int a,b,c;
    printf("address of a=%p\n",&a);
    printf("address of b=%p\n",&b);
    printf("address of c=%p\n",&c);

}
