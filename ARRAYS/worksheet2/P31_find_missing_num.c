/*31.Find missing number in array
Question description:
Write a C program to find the missing number in an array of size n containing numbers from 1 to n+1.
Sample data:
Input: 1 2 4 5 6
Expected output:
Missing number is: 3*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,j,s;
    printf("Enter the array elements\n");
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);

    for(i=0;i<n;i++){
        if((i+1)!=a[i]){
    printf("The missing element is %d\n",i+1);
    break;
    }
    }
}