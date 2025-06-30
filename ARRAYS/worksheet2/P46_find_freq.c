/*46.Find the frequency of each element
Question description:
Write a C program to find the frequency of each element in the array.
Sample data:
Input: 10 20 10 30 20 20 10 10
Expected output:
10: 4 20: 3 30: 1*/
#include<stdio.h>

int main()
{
int ele;
    printf("Enter the number of elemets:\n");
    scanf("%d",&ele);
    int a[ele];
    int i,j=0,k=0,count;
    printf("Enter the array elements\n");
        for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
int c;
for(i=0;i<ele;i++)
        {
                for(j=0;j<i;j++) {
                        if(a[i]==a[j])
                                break;
                }
                if(j==i)
                {
                        for(j=i+1,c=1;j<ele;j++)
                                if(a[i] == a[j])
                                        c++;
                
                        printf("the element %d occured %d times\n",a[i],c);
                }
        }
}