/*14.Suppose you are given a pointer int *ptr = malloc(5 * sizeof(int));. You fill it with values. 
How do you safely iterate in reverse order using only pointer arithmetic?*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("enter no of ele:");
    scanf("%d",&n);
    int *ptr=malloc(n*sizeof(int));
    if(ptr==NULL)
        return 1;

    for(int i=0;i<n;i++)
    {
        *(ptr+i)=i+1;
    }

    int *p=ptr+(n-1);

    while(p>=ptr)
    {
        printf("%d ",*p);
        p--;
    }

    free(ptr);
    p=NULL;
}
