/* Q01. Position of Rightmost Set Bit (No Loops)----------------------------------
Problem Statement:
 Given a positive integer n, report the 1-based 
 position of the least significant bit that is 1. Avoid loops in the final implementation*/

 #include <stdio.h>

// Function to find rightmost set bit
int rightmost_set_bit(int n) {
    if (n == 0) 
        return 0;          // no set bit
    int pos = __builtin_ctz(n) + 1; // GCC builtin
    return pos;
}

int main() {
    int n;
    scanf("%d",&n);
    printf("Rightmost set bit of %d is at position %d\n", n, rightmost_set_bit(n));
    return 0;
}
