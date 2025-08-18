/*3.Pointer to Pointer (Double Pointer)
Goal: Understand how to use double pointers for indirect referencing and dynamic memory management.
Activity:
Declare a double pointer and use it to dynamically allocate memory for a single variable or an array.
Access and modify the allocated memory via the double pointer.
Pass double pointers to functions to dynamically allocate or modify memory inside the function.*/
#include<stdio.h>
void func(int **q)
{
            q=(int **)malloc(sizeof(int *));
            *q=(int *)malloc(sizeof(int));
            **q=87;

}
int main()
{
            int **p=(int **)malloc(sizeof(int *));
            *p=(int *)malloc(sizeof(int));
            **p=45;
            printf("%d\n",**p);
            func(p);
            printf("%d\n",**p);
}
