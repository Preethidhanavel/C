/* Q18. Set, Clear, Toggle a Specific Bit-------------------------------------
Problem Statement:
 Return values after setting, clearing, and toggling bit k of an integer n*/

#include <stdio.h>

// Set bit at position k (make it 1)
int set_bit(int x, int k) 
{ 
    return x | (1 << k); 
}

// Clear bit at position k (make it 0)
int clr_bit(int x, int k) 
{ 
    return x & ~(1 << k); 
}

// Toggle bit at position k (flip 0->1 or 1->0)
int tog_bit(int x, int k)
{ 
    return x ^ (1 << k); 
}

int main() 
{
    int v = 0b1010;   // binary: 1010 (decimal 10)

    printf("set bit 1 : %d\n", set_bit(v,1));
    printf("clear bit 3: %d\n", clr_bit(v,3));
    printf("toggle bit 0: %d\n", tog_bit(v,0));

    return 0;
}
