/*14.Question: Frequency of each element
Question description: Write a C program to count the frequency of each element in an array.
Sample data:
Input: 1 2 2 3 3 3
Expected output:
1 occurs 1 time
2 occurs 2 times
3 occurs 3 times*/

#include <stdio.h>

int main() 
{
    int  ele, i, j, count;
    printf("enter the number of elements\n");
    scanf("%d",&ele);
    int arr[ele];
    printf("Enter the array elements\n");
    for(i = 0; i < ele; i++) {
        scanf("%d", &arr[i]);
    }

    printf("output:\n");

    for(i = 0; i < ele; i++) 
    {
        int isVisited = 0;
        for(j = 0; j < i; j++)
         {
            if(arr[i] == arr[j])
             {
                isVisited = 1;
                break;
             }
        }

        if(!isVisited)
         {
            count = 1;
            for(j = i + 1; j < ele; j++)
            {
                if(arr[i] == arr[j])
                {
                    count++;
                }
            }
            printf("%d occurs %d time\n", arr[i], count);
        }
    }

    return 0;
}
