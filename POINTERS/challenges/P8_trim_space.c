//8.Write a function that trims leading and trailing whitespace from a string using pointers.
#include <stdio.h>

void trim(char *str) 
{
    int start = 0, end = 0, i = 0;

    while (str[start] == ' ') {
        start++;
    }

    if (str[start] == '\0') {
        str[0] = '\0';
        return;
    }

    end = start;
    while (str[end] != '\0') {
        end++;
    }
    end--;

    while (str[end] == ' ' && end > start) {
        end--;
    }

    for (i = 0; start <= end; i++, start++) {
        str[i] = str[start];
    }
    str[i] = '\0';
}

int main() 
{
    char input[] = "      hello world       ";

    printf("Before trim: '%s'\n", input);
    trim(input);
    printf("After trim:  '%s'\n", input);

    return 0;
}
