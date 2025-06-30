/*Write a function that allocates a 2D array of integers dynamically. 
Also, write a function that frees all of the memory for this array.*/



#include <stdio.h>
#include <stdlib.h>

int** allocate(int rows,int cols)
{
    int **arr=malloc(rows*sizeof(int*));
    if(arr==NULL) return NULL;

    for(int i=0;i<rows;i++)
    {
        arr[i]=malloc(cols*sizeof(int));
        if(arr[i]==NULL)
        {
            for(int j=0;j<i;j++) free(arr[j]);
            free(arr);
            return NULL;
        }
    }
    return arr;
}

void free2dArray(int **arr,int rows)
{
    for(int i=0;i<rows;i++) 
    free(arr[i]);
    free(arr);
}

int main()
{
    int rows=3,cols=4;
    int **myArray=allocate(rows,cols);
    if(myArray==NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            myArray[i][j]=i*10+j;
        }
    }
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",myArray[i][j]);
        }
        printf("\n");
    }
    free2dArray(myArray,rows);
    
}
