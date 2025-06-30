/*Write code that handles the case where malloc or calloc returns NULL because there is not enough memory. 
What should your program do?*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t count = 1000000000;
    int *arr = (int *)calloc(count, sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    arr[0] = 42;
    printf("arr[0] = %d\n", arr[0]);
    int *arr1=(int *)malloc(count*sizeof(int));
    if(arr1==NULL){
        fprintf(stderr,"Error:Memory allocation failed.\n");
        return EXIT_FAILURE;
    }
    arr1[0]=27;
    printf("arr1[0] = %d\n", arr1[0]);
    free(arr);
    free(arr1);
    return EXIT_SUCCESS;
}
