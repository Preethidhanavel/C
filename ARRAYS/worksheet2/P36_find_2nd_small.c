/*36.Find second smallest element
Question description:
Write a C program to find the second smallest element in the array.
Sample data:
Input: 12 13 1 10 34 1
Expected output:
Second smallest element is 10*/
#include<stdio.h>
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
int s1,s2;
            if(a[0]>a[1])
        s1 = a[1],s2 = a[0];
        else
        s1 = a[0],s2 = a[1];
     for(i=2;i<n;i++)
        {
                if(a[i] < s1)
                {
                        s2 = s1;
                        s1 = a[i];
                }
                else if( (a[i] < s2)&&(a[i]!=s1) )
                s2 = a[i];
        }

        printf("2nd smallest element = %d\n",s2);


}