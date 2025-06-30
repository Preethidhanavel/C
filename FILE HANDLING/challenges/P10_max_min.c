/*10.A file contains integers separated by commas. How would you efficiently find the maximum and minimum numbers without 
loading the file fully into memory, even if the file is several gigabytes in size?*/
#include <stdio.h>
#include <limits.h>
#include <ctype.h>

int main() 
{
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    int num = 0, sign = 1;
    int has_number = 0;
    int min = INT_MAX, max = INT_MIN;
    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '-') {
            sign = -1;
        } else if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            has_number = 1;
        } else if (ch == ',' || ch == '\n') {
            if (has_number) {
                num *= sign;
                if (num > max) max = num;
                if (num < min) min = num;
                num = 0;
                sign = 1;
                has_number = 0;
            }
        }
    }
    if (has_number) {
        num *= sign;
        if (num > max) max = num;
        if (num < min) min = num;
    }

    fclose(fp);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    return 0;
}
