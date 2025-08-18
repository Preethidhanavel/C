/*23.Question: Count duplicate elements
Question description: Write a C program to count how many duplicate values are in the array.
Sample data:
Input: 1 2 3 1 4 2
Expected output:
Total duplicate elements: 2
*/

#include<stdio.h>
int main()
{
    int a[5],i,j,c=0,q=0;
    printf("Enter the elements:\n");
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);

    for(i=0;i<5;i++)
    {
        for(j=0;j<i;j++)
        if(a[i]==a[j])
        break;

        if(i==j)
        {
            for(j=i+1;j<5;j++)
                if(a[i]==a[j])
                c++;

            if(c>1)
            q++;                
        }    
    }
    printf("Total duplicate elements: %d\n",q);
}