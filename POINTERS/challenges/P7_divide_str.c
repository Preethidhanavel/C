/*7.Implement a function that splits a string into two halves and returns pointers to the beginning of each half.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void splitString(const char* input, char** firstHalf, char** secondHalf) 
{
    size_t len = strlen(input);
    size_t mid = len / 2;

    *firstHalf = (char*)malloc(mid + 1);
    *secondHalf = (char*)malloc(len - mid + 1);

    if (!*firstHalf || !*secondHalf) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    strncpy(*firstHalf, input, mid);
    (*firstHalf)[mid] = '\0';

    strcpy(*secondHalf, input + mid);
}

int main() 
{
    const char* original = "HelloWorld!";
    char* left = NULL;
    char* right = NULL;

    splitString(original, &left, &right);

    printf("Original String: %s\n", original);
    printf("First Half: %s\n", left);
    printf("Second Half: %s\n", right);

    free(left);
    free(right);

    return 0;
}
