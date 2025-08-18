//17.What effect does using a packing pragma have on a structure's layout and why might it be required?

#include<stdio.h>
#pragma pack(1)
typedef struct Packed 
{
    char a; 
    int b;  
}st;

int main()
{
    st v;
    printf("%ld\n",sizeof(v));  
}
