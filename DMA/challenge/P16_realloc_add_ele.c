/*Write a C function that adds an element to a dynamic array using realloc. Make sure your code is safe, even if realloc fails.*/
#include <stdio.h>
#include <stdlib.h>

int add_element(int **array, size_t *size, int element) {
    int *temp = realloc(*array, (*size + 1) * sizeof(int));
    if (temp == NULL) {
        return -1;
    }
    temp[*size] = element;
    *array = temp;
    (*size)++;
    return 0;
}

int main() 
{
    int *my_array = NULL;
    size_t size = 0;

    if (add_element(&my_array, &size, 10) != 0) {
        fprintf(stderr, "Failed to add element\n");
        return 0;
    }

    if (add_element(&my_array, &size, 20) != 0) {
        fprintf(stderr, "Failed to add element\n");
        free(my_array);
        return 0;
    }

    if (add_element(&my_array, &size, 30) != 0) {
        fprintf(stderr, "Failed to add element\n");
        free(my_array);
        return 0;
    }

    for (size_t i = 0; i < size; i++) {
        printf("%d\n", my_array[i]);
    }

    free(my_array);
    return 0;
}
