/*3.Log Session a function that counts the number of elements in an array using pointer arithmetic, 
without utilizing loop constructs*/


#include<stdio.h>

int count_ele(int *start,int *end)
{
    if(start==end)
        return 0;
    return 1+count_ele(start+1,end);
}

int main()
{
    int arr[]={10,20,30,40,50};
    int size=sizeof(arr)/sizeof(arr[0]);
    int count=count_ele(arr,arr+size);
    printf("Number of elements:%d\n",count);
}
