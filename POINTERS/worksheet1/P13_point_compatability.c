/*13. Pointer Type Compatibility
Goal: Understand the importance of matching pointer types.

Activity:

Declare int *ip; and float *fp;
Try assigning fp = ip; and observe compiler warning.
Correct the mismatch using proper types or casting.*/

#include<stdio.h>

int main()
{
    int a=10;
    int *ip=&a;
    float *fp;
    //fp=ip;assignment from incompatible pointer type
    fp=(float *)ip;
    printf("ip=%d fp=%f",*ip,*fp);
}
