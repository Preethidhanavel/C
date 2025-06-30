//Give an example of a bug that happens when you use memory after you have freed it. How can you prevent such bugs?
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));
    *ptr = 100;

    free(ptr);
    ptr = NULL;    

    if (ptr != NULL) {
        *ptr = 200; 
    }

    return 0;
}
