/*Your program keeps using more memory as it runs, even though you use malloc and free. 
How would you find out what is wrong and fix it?*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char *name;
    name = (char *)malloc(20 * sizeof(char));
    if (name == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    name = (char *)malloc(30); 
    strcpy(name, "Memory Management");
    printf("Stored string: %s\n", name);
    free(name);

    return 0;
}
// valgrind --leak-check=full ./check_leak