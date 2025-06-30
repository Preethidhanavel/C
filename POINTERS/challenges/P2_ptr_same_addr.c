/*2.Design a function that determines if two pointers point to the same array.*/
#include <stdio.h>

int pointToSameArray(int* p1, int* p2, int* a, size_t n) 
{
    return (p1 >= a && p1 < a + n) &&(p2 >= a && p2 < a + n);
}

int main() 
{
    int arr1[10];
    int arr2[10];

    int* ptr1 = &arr1[2];
    int* ptr2 = &arr1[5];
    int* ptr3 = &arr2[2];


    if (pointToSameArray(ptr1, ptr2, arr1, 10)) 
    {
        printf("ptr1 and ptr2 point to the same array.\n");
    } 
    else 
    {
        printf("ptr1 and ptr2 do NOT point to the same array.\n");
    }

    if (pointToSameArray(ptr1, ptr3, arr1, 10)) 
    {
        printf("ptr1 and ptr3 point to the same array.\n");
    } 
    else 
    {
        printf("ptr1 and ptr3 do NOT point to the same array.\n");
    }

    return 0;
}
