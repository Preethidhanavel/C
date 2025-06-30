/*9.Question: Insert element at position
Question description: Write a C program to insert a number at a given position in an array.
Sample data:
Array: 10 20 30 40
Insert: 25 at position 2
Expected output:
Array after insertion: 10 20 25 30 40*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n+1];
    int i,j;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int c,x;
    printf("Enter element and index position for inserting\n");
    scanf("%d%d",&c,&x);
    for(i=n-1;i>=x;i--){
        a[i+1]=a[i];

    }
    a[x]=c;
    for(i=0;i<n+1;i++)
       printf("%d ",a[i]);

}