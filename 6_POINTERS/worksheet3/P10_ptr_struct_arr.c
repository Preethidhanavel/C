/*10.Pointer Arithmetic on Struct Arrays
Goal: Access and modify an array of peripheral register structs using pointer arithmetic.
Activity:

Define a struct representing peripheral registers:
struct Peripheral {
  uint8_t status;
  uint8_t control;
  uint16_t data;
};
Declare an array of 5 such structs.
Use a pointer to traverse and modify the array elements using pointer arithmetic.*/
#include <stdio.h>

struct Peripheral {
    int status;
    int control;
    int data;
};

int main() 
{
    struct Peripheral devices[5];
    struct Peripheral* ptr = devices;

    for (int i = 0; i < 5; i++) {
        (ptr + i)->status = i;
        (ptr + i)->control = i + 10;
        (ptr + i)->data = (i + 1) * 100;
    }

    for (int i = 0; i < 5; i++) {
        printf("Device %d - Status: %d, Control: %d, Data: %d\n",i, devices[i].status, devices[i].control, devices[i].data);
    }

    return 0;
}
