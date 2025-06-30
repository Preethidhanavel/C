//18.You have a multi-dimensional array like int arr[3][4]. How can you access arr[2][3] using only a single pointer variable?
#include<stdio.h>
int main()
{
    int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int* p = (int*)a;
    printf("p[2][3] = %d\n",*(*(p+2)+3));
}