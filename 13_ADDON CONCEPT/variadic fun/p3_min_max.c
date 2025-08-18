/*Description
Write a C program to find the maximum and minimum values of a variable number of integers passed as arguments to a function using variadic functions.

Key Concept: Use stdarg.h to process each integer, compare and update max and min values.

Sample Input & Output
Function calls:
find_max_min(5, 3, 5, 9, 0, 7)
Output:
Maximum value: 9
Minimum value: 0

Explanation
The first argument is the count of integers, followed by the values. The function finds both maximum and minimum among them.*/

#include<stdio.h>
#include<stdarg.h>

void min_max(int count,...)
{
    

    va_list args;

    va_start(args,count);

    int num,max,min;
     min=va_arg(args,int);
    max=min;

    for(int i=0;i<count;i++)
    {
        num=va_arg(args,int);
        if(num>max)
         max=num;

        if(num<min)
         min=num;
    }

  printf("max value=%d\n",max);
    printf("min value=%d\n",min);

}


int main()
{

    min_max(5,3,5,9,0,7);

}