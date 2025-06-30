/*What happens if you write outside the bounds of a dynamically allocated array? Why is this dangerous?*/


#include <stdio.h>
#include <stdlib.h>
int main(){
    int *arr=malloc(5*sizeof(int));
    if(arr==NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    for(int i=0;i<5;i++)
    {
        arr[i]=i*10;
    }
    arr[5]=50;
    printf("Value at arr[5]: %d\n",arr[5]);
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
}
