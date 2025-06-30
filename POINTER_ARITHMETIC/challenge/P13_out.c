#include<stdio.h>
int main()
{
    int arr[]={10,20,30,40,50};
    printf("%d\n", *(arr + *(arr + 2) / 10 - 1));
}
