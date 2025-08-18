//2. Using the same array, print the last element by adding an integer to the pointer.
#include<stdio.h>
int main()
{
    int a[]={5,10,15,20,25};
    int* p=a;
    printf("%d",*(p+4));
}