/* Q12. itoa Without Standard Library---------------------------------
Problem Statement:
 Convert an integer into its string representation in a given base (2–16) without using sprintf*/

#include <stdio.h>

// Convert integer 'num' into string 'str' in given 'base'
void my_itoa(int num, char* str, int base) 
{
    int i = 0, neg = 0;

    // Case: num = 0
    if (num == 0) 
    { 
        str[i++] = '0';  // store '0'
        str[i] = 0;      // null-terminate
        return;
    }

    // Handle negative numbers only for base 10
    if (num < 0 && base == 10) 
    { 
        neg = 1;       // remember it's negative
        num = -num;    // work with positive value
    }

    // Process digits
    while (num) 
    {
        int rem = num % base;  // remainder
        // Convert remainder to char ('0'..'9' or 'A'..'F')
        str[i++] = (rem > 9) ? (rem - 10 + 'A') : (rem + '0');
        num /= base;           // reduce number
    }

    // Add minus sign if needed
    if (neg) 
        str[i++] = '-';

    str[i] = 0;  // null-terminate string

    // Reverse string (since digits were stored backwards)
    for (int j = 0; j < i/2; j++) 
    {
        char t = str[j];
        str[j] = str[i-1-j];
        str[i-1-j] = t;
    }
}

int main() 
{
    char buf[20];

    // Decimal positive
    my_itoa(1234, buf, 10);
    printf("1234 -> %s\n", buf);

    // Decimal negative
    my_itoa(-255, buf, 10);
    printf("-255 -> %s\n", buf);

    // Hexadecimal (base 16)
    my_itoa(255, buf, 16);
    printf("255 -> %s\n", buf);

    return 0;
}
