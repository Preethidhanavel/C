//25.Give an example where using a structure in C might result in undefined behavior, such as accessing freed or uninitialized members.

#include <stdio.h>
#include <stdlib.h>

struct Dangling 
{ 
    int *ptr;
};

int main() 
{
    struct Dangling d;
    d.ptr = (int*)malloc(sizeof(int));   
    *d.ptr = 42;                  

    free(d.ptr);                   

    printf("%d", *(d.ptr));       
    return 0;
}
