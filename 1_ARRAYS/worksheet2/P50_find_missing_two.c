/*50.Finding the missing two numbers in an array
Question description: 
Write a C program to find two missing numbers from an array containing numbers from 1 to n+2
Sample data:
Input: 1 2 4 6
Expected Output:
Missing numbers:3 5*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
 int ele;
    printf("Enter the number of elemets:\n");
    scanf("%d",&ele);
    int a[ele];
    int i,j=0,k=0;

    printf("Enter the array elements\n");
        for(i=0;i<ele;i++)
        scanf("%d",&a[i]);
        int n=ele+2;
     int*mark=(int *)calloc(n,sizeof(int)); 
    
    for (int i = 0; i < n-2; i++)
        mark[a[i]] =1;

    for (int i = 1; i <= n; i++)
       if (! mark[i])
           printf("%d " ,i );

    

}