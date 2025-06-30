/*32.Find the majority element
Question description:
Write a C program to find the majority element in an array (element appearing more than n/2 times).
Sample data:
Input: 2 2 1 2 3 2 2
Expected output:
Majority element: 2*/

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
  int c,s=0,ele;
  for(i=0;i<n;i++)
        {
                for(j=0;j<i;j++) {
                 if(a[i]==a[j])
                 break;
                }
                if(j==i)
                {
                        for(j=i+1,c=1;j<n;j++)
                        if(a[i] == a[j])
                        c++;

                        if(c>=n/2)
                        {
                             ele=a[i];
                            //s=c;
                        }
                }
        }

printf("The majority element is %d\n",ele);
}