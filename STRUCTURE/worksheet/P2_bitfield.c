/*2.Bit-fields in Structures
Goal
Learn to define and use bit-fields to manage individual bits for hardware register simulation.

Activity
Log Session a structure using bit-fields to represent an 8-bit status register.
Assign values to specific flags.
Log Session a mock register with error, ready, and mode bits.
Write code to toggle specific flags without using bitwise operators.
Reflect on how compilers handle ordering and alignment of bit-fields.
Tip: Bit-fields may behave differently on different compilers—don't assume portability.*/
#include<stdio.h>
struct sr{
unsigned int error:1;
unsigned int ready:1;
unsigned int mode:1;
};
int main()
{
struct sr v;
v.error=0;
v.ready=1;
v.mode=1;
printf("sizeof(v):%ld\n",sizeof(v));
printf("error :%d\n",v.error);
printf("ready :%d\n",v.ready);
printf("mode :%d\n",v.mode);

v.error=!v.error;
v.ready=!v.ready;
printf("error :%d\n",v.error);
printf("ready :%d\n",v.ready);
}
