/*6.Given an array where every element appears twice except two elements appearing once, 
find those two unique elements using XOR operations.*/

#include<stdio.h>
void find_unique(int *arr,int n)
{
       int xorAll = 0;

    for (int i = 0; i < n; i++) {
        xorAll ^= arr[i];
    }

    int setBit = xorAll & (~(xorAll - 1));
    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] & setBit)
            num1 ^= arr[i];  
        else
            num2 ^= arr[i];  
    }
    printf("%d %d\n",num1,num2);
}


int main()
{
     int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,j;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    find_unique(a,n);
}