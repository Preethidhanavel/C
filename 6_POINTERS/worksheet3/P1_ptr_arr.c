/*1.Pointer and Array Behavior
Goal: Analyze how pointers and arrays differ in memory referencing and sizeof operations in embedded systems.
Activity:

Declare an integer array with predefined elements:
1.int arr[5] = {10, 20, 30, 40, 50};
Declare an integer pointer and assign it to the array's base address:
1.int *ptr = arr;
Print the values of the array name, the pointer, and the address of the array.
Use sizeof() on the array and pointer and observe differences.
Access the elements via both array indexing and pointer arithmetic, and print them.*/

#include<stdio.h>
int main()
{
    int a[5]={10,20,30,40,50};
    int *ptr=a;
    int i,n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++)
        printf("a[%d]=%d  ptr+%d=%d\n",i,a[i],i,*ptr++);
    ptr=a;
    for(i=0;i<n;i++)
        printf("&a[%d]=%p  ptr+%d=%p\n",i,&a[i],i,(ptr+i));

}