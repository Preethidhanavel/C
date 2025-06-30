/*Why is it safe to use free(NULL) in C?
 Why was it designed this way?*/



#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int *ptr = NULL;

    free(ptr);
}