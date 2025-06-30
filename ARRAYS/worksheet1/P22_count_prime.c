/*22.Question: Count prime numbers
Question description: Write a C program to count and display all prime numbers in an array.
Sample data:
Input: 2 4 5 6 7 8
Expected output:
Primes: 2 5 7
Count: 3*/


#include<stdio.h>

int main()
{
    int a[5];
    int i,c,ele,j,count;
    ele=sizeof(a)/sizeof(a[0]);
    printf("input:");
    for(i=0;i<ele;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("output:\nprimes");
    for(i=0,count=0;i<ele;i++)
    {
        for(j=1,c=0;j<a[i];j++)
        {
            if((a[i]%j)==0)
            {
                c++;
            }
            
        }
         if(c==1)
            {
                printf("%d ",a[i]);
                count++;
            }
    }
    printf("\ncount=%d",count);
}