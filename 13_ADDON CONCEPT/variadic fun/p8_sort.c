/*Description
Write a C program to sort a variable number of integers passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to gather all integers, copy them to an array, sort, and print.

Sample Input & Output
Function calls:
sort_numbers(5, 9, 5, 7, 1, 3) → Output: 1 3 5 7 9
sort_numbers(3, 1, -2, 0) → Output: -2 0 1

Explanation
The first argument is the count of integers, followed by their values. The function sorts and prints them.

*/



#include <stdio.h>
#include <stdarg.h>

void sort_numbers(int count, ...) 
{
    int arr[100];
    va_list args;

    va_start(args, count);

    int i,j,trmp;
    for (i = 0; i < count; i++) 
    {
        arr[i] = va_arg(args, int);
    }
    va_end(args);

    for (i = 0; i < count - 1; i++) 
    {
        for (j = 0; j < count - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    for (i = 0; i < count; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{
    sort_numbers(5, 9, 5, 7, 1, 3);
    sort_numbers(3, 1, -2, 0);

}
