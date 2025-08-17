/* Q25. Float  Decimal String (No sprintf)---------------------------------------
Problem Statement:
 Render a float as D.dddd with fixed precision using integer math.*/

#include <stdio.h>
#include <math.h>

// Reverse a string in place
void rev(char* a, int n) 
{
    for (int i = 0; i < n / 2; i++) 
    {
        char t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }
}

// Convert integer to string (base 10)
int itoa10(int x, char* out) 
{
    int i = 0, neg = x < 0;   // check if number is negative
    if (neg) x = -x;          // work with positive number

    if (x == 0) out[i++] = '0';   // handle zero

    // extract digits (in reverse order)
    while (x) 
    {
        out[i++] = '0' + (x % 10);
        x /= 10;
    }

    if (neg) out[i++] = '-';  // add negative sign if needed
    rev(out, i);              // reverse to correct order
    out[i] = '\0';            // null terminate
    return i;                 // return string length
}

// Convert float to string with given precision
void ftoa(float f, char* out, int prec) 
{
    int i = 0;

    // Handle negative numbers
    if (f < 0) 
    {
        out[i++] = '-';
        f = -f;
    }

    // Separate integer and fractional parts
    int whole = (int)f;
    float frac = f - whole;

    // Convert integer part
    i += itoa10(whole, out + i);

    // Add decimal point
    out[i++] = '.';

    // Convert fractional part (prec digits)
    for (int k = 0; k < prec; k++) 
    {
        frac *= 10.0f;              // shift left by one decimal place
        int d = (int)frac;          // extract digit
        out[i++] = '0' + d;         // store digit as char
        frac -= d;                  // remove digit from frac
    }

    out[i] = '\0'; // null terminate
}

int main() 
{
    char b[64];

    // Convert float with 3 decimal precision
    ftoa(-123.4567f, b, 3);

    // Print result
    printf("%s\n", b);

    return 0;
}
