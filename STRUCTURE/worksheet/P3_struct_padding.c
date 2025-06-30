/*3.Structure Padding, Alignment, and Packing
Goal
Understand how padding affects structure size and how to control layout using packing directives.

Activity
Log Session a structure with mixed data types (char, int, short).
Check the size and member offsets using sizeof() and pointer arithmetic.
Reorder members to reduce padding and observe the change in size.
Use #pragma pack(1) and compare memory layout.
Simulate a communication packet where field alignment matters.
Tip: Use offsetof() macro to determine the byte offset of each field.*/
#include<stdio.h>
#include<stddef.h>
#pragma pack(1)
struct st{
//double d;
char ch;
int x;

double d;

};
struct communication{

 unsigned char id;
 unsigned char bytes;
 unsigned int data;
 unsigned int crc;
 unsigned int endfield;
}packet;
int main()
{
struct st v;
printf("size %ld \n%ld\n%ld\n%ld\n",sizeof(v),sizeof(v.d),sizeof(v.ch),sizeof(v.x));


printf("%ld  %ld  %ld \n",offsetof(struct st,ch),offsetof(struct st,x),offsetof(struct st,d));

printf("sizeof(communication)%ld\n",sizeof(packet));
printf("%ld  %ld  %ld  %ld %ld\n",offsetof(struct communication,id),offsetof(struct communication,bytes),
offsetof(struct communication,data),offsetof(struct communication,crc),offsetof(struct communication,endfield));

}
