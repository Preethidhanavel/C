/*Look at this code:
What will be the output? Is there anything risky about using unions this way?*/
#include<stdio.h>
union Data {
    int i;
    float f;
    char str[4];
};
int main()
{
union Data d;
d.i = 0x41424344;
printf("%s\n", d.str);
}