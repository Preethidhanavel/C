/* Q13. Count Trailing Zeros (CTZ)------------------------------
Problem Statement:
 Return the number of consecutive 0-bits starting from the least significant bit*/

 #include <stdio.h>

int ctz(unsigned int n) 
{
    if (n==0) 
        return 32;
    int count=0;
    while ((n & 1)==0) 
    { 
        n >>= 1; 
        count++; 
    }
    return count;
}

int main() 
{
    printf("CTZ(16) = %d\n", ctz(16));
    printf("CTZ(64) = %d\n", ctz(64));
    printf("CTZ(0)  = %d\n", ctz(0));
    return 0;
}
