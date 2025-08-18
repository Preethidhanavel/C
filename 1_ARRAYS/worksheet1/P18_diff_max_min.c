/*18.Question: Difference between max and min
Question description: Write a C program to find the difference between largest and smallest elements in an array.
Sample data:
Input: 5 1 9 3 6
Expected output:
Difference: 8*/

#include<stdio.h>

void main()
{
    int a[5], i, ele, min, max;

    ele = sizeof(a) / sizeof(a[0]);

    printf("Input: ");
    for(i = 0; i < ele; i++)
    {
        scanf("%d", &a[i]);
    }

    min = max = a[0];  

    for(i = 0; i < ele; i++)
    {
        if(a[i] < min)
            min = a[i];
        if(a[i] > max)
            max = a[i];
    }

    printf("Difference: %d", max - min);
}
