/*19.Implement a function that finds the common elements in three sorted arrays using pointers.*/
#include <stdio.h>
#include <stdlib.h>
void sort(int *a,int ele)
{
    int i,j,temp;
    for(i=0;i<ele;i++)
    {
        for(j=0;j<ele-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void findCommonElements(int* arr1, int m,int* arr2, int n,int* arr3, int k) {
    int *p1 = arr1, *p2 = arr2, *p3 = arr3;
    int *end1 = arr1 + m;
    int *end2 = arr2 + n;
    int *end3 = arr3 + k;

    printf("Common elements: ");
    int found = 0;

    while (p1 < end1 && p2 < end2 && p3 < end3) 
    {
        if (*p1 == *p2 && *p2 == *p3) {
            printf("%d ", *p1);
            found = 1;
            p1++;
            p2++;
            p3++;
        } 
        else 
        {
            if (*p1 < *p2) 
            {
                p1++;
            } 
            else if (*p2 < *p3) 
            {
                p2++;
            } else 
            {
                p3++;
            }
        }
    }
    if (!found) {
        printf("No common elements");
    }
    printf("\n");
}

int main() 
{
    int m,n,k;
    printf("Enter the number of elements of array 1,array2 and array2\n");
    scanf("%d%d%d",&m,&n,&k);
    int arr1[m],arr2[n],arr3[k];
    int i;
    printf("start to enter element of array1\n");
    for(i=0;i<m;i++)
    scanf("%d",&arr1[i]);
     printf("start to enter element of array2\n");
     for(i=0;i<n;i++)
    scanf("%d",&arr2[i]);
     printf("start to enter element of array3\n");
     for(i=0;i<k;i++)
    scanf("%d",&arr3[i]);
    sort(arr1,m);
    sort(arr2,n);
    sort(arr3,k);
    findCommonElements(arr1,m,arr2,n,arr3,k);

    return 0;
}
