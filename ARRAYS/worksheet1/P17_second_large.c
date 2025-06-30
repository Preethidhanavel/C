/*17.Question: Find second largest element
Question description: Write a C program to find the second largest number in the array.
Sample data:
Input: 10 20 50 40
Expected output:
Second largest: 40
*/

#include<stdio.h>
int main()
{
    int i,j,a[5],big1,big2;
    printf("Enter the elements:\n");
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);

    if(a[0]>a[1])
    {
        big1=a[0];
        big2=a[1];
    }
    else{
        big1=a[1];
        big2=a[0];
    }

    for(i=0;i<5;i++)
    {
        if(a[i]>big1)
        {
            big2=big1;
            big1=a[i];
        }
        else if((a[i]>big2) && (a[i]!=big1))
        {
            big2 = a[i];
        }
    }

    printf("Second Largest: %d\n",big2);
}