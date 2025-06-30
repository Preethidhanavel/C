/*7.Question: Find for an element
Question description: Write a C program to search for a number in an array and print its index.
Sample data:
Array: 10 20 30 40 50
Find: 30
Expected output:
Element found at index: 2*/
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of elemets:\n");
    scanf("%d",&n);
    int a[n];
    int i,c;
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter the element \n");
    scanf("%d",&c);
    for(i=0;i<n;i++)
        if(a[i]==c){
            printf("the element is found at %d\n",i);
            break;
        }
}
