/*25.Question: Segregate even and odd
Question description: Write a C program to arrange all even numbers first and then all odd numbers.
Sample data:
Input: 1 2 3 4 5 6
Expected output:
Even numbers: 2 4 6
Odd numbers: 1 3 5
*/

#include<stdio.h>
int main()
{
    int a[5],b[5],c[5],i,j=0,k=0;
    printf("Enter the elements:\n");
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);

    for(i=0;i<5;i++)
    {
        if(a[i]%2==0)
        b[j++]=a[i];
        else
        c[k++]=a[i];
    }

    printf("Even Numbers: \n");
    for(i=0;i<j;i++)
    printf("%d ",b[i]);
    printf("\n");
    
    printf("Odd Numbers: \n");
    for(i=0;i<k;i++)
    printf("%d ",c[i]);
    printf("\n");

}