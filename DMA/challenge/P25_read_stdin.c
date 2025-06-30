/* Write a function that reads a line of any length from stdin, 
allocating more memory as needed. Make sure to handle errors if memory allocation fails.*/

#include <stdio.h>
#include <stdlib.h>

char* read_line() {
    size_t size = 16;
    size_t len = 0;
    char *buffer = malloc(size);

    if (buffer == NULL) {
        return NULL;
    }

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (len + 1 >= size) {
            size *= 2;
            char *new_buffer = realloc(buffer, size);
            if (new_buffer == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
        buffer[len++] = (char)ch;
    }

    buffer[len] = '\0';
    return buffer;
}

int main() 
{
    printf("Enter a line: ");
    char *line = read_line();

    if (line == NULL) {
        printf("Failed to read line (out of memory).\n");
        return 1;
    }

    printf("You entered: %s\n", line);
    free(line);
    return 0;
}
