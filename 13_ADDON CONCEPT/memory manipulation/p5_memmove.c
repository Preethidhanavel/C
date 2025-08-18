/*Use memmove to shift a portion of an array forward safely*/

#include <stdio.h>
#include <string.h>

int main() 
{
    char arr[] = "abcdef";

    memmove(&arr[3], &arr[2], 3);

    printf("Resulting array: %s\n", arr);

    
}
