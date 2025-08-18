/*8.NULL Pointer Safety
Goal: Learn to avoid dereferencing NULL pointers.
Activity:
Declare: int *p = NULL;
Use a condition if (p != NULL) before dereferencing.
Later, assign p = &a; and access safely.*/
#include <stdio.h>

int main() 
{
    int *p = NULL;

    if (p != NULL) {
        printf("Value pointed to by p: %d\n", *p);
    } 
    else {
        printf("Pointer p is NULL, not dereferencing.\n");
    }

    int a = 10;
    p = &a;

    if (p != NULL) {
        printf("Now p points to a valid address: %d\n", *p);
    }

    return 0;
}
