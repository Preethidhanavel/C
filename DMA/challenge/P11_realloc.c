/*When you use realloc, how does it work? 
What happens if there isn’t enough space to grow the block where it is?*/




#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *arr=malloc(3*sizeof(int));
    if(arr==NULL)
    {
    printf("Initial allocation failed\n");
    return 1;
    }
    for(int i=0;i<3;i++)
    {
    arr[i]=i*10;
    }
    int *temp=realloc(arr,6*sizeof(int));
    if(temp==NULL)
    {
    printf("Reallocation failed\n");
    free(arr);
    return 1;
    }
    arr=temp;
    for(int i=3;i<6;i++)
    {
    arr[i]=i*10;
    }
    for(int i=0;i<6;i++)
    {
    printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
}
