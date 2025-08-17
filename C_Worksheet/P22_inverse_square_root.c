/* Q22. Fast Inverse Square Root----------------------------
Problem Statement:
 Approximate 1/sqrt(x) using the Quake-III method with a magic constant 
 and one Newton-Raphson iteration*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Function to compute fast inverse square root (1/sqrt(x))
float inv_sqrt(float x) 
{
    float xhalf = 0.5f * x;    // store half of x
    uint32_t i;

    // Reinterpret float bits as integer
    memcpy(&i, &x, 4);
    i = 0x5f3759df - (i >> 1);

    // Convert bits back to float
    memcpy(&x, &i, 4);
    x = x * (1.5f - xhalf * x * x);

    return x;  // approximate 1/sqrt(x)
}

int main(void) 
{
    float n = 9.0f;

    // Print the approximation of 1/sqrt(n)
    printf("1/sqrt(%g) : %g\n", n, inv_sqrt(n));

    return 0;
}
