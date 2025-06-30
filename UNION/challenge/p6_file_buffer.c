/*Suppose you have a structure that can either store a pointer to a file or a pointer to a memory buffer, 
but not both at the same time. How would you use a union for this? What do you need to watch out for when 
working with the union members?

struct FileOrBuffer {
    int mode; // 0: file, 1: buffer
    union {
        FILE *fp;
        char *buffer;
    } handle;
};*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FileOrBuffer 
{
    int mode;
    union 
    {
        FILE *fp;
        char *buffer;
    } handle;
};

int main() 
{
    struct FileOrBuffer resource;

    resource.mode = 0;
    resource.handle.fp = fopen("test.txt", "r");
    if (resource.handle.fp != NULL) 
    {
        printf("file opened\n");
        fclose(resource.handle.fp);
    }

    resource.mode = 1;
    resource.handle.buffer = malloc(100);
    if (resource.handle.buffer != NULL) 
    {
        strcpy(resource.handle.buffer, "hello buffer");
        printf("%s\n", resource.handle.buffer);
        free(resource.handle.buffer);
    }


}
