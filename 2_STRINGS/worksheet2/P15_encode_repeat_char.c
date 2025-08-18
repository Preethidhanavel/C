//15.Compress a string using run-length encoding by replacing repeated characters with the character and count.
//Input:"aaabbcc"
//Output: "a3b2c2"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
void runLengthEncode(char *str) 
{
    int i, count;
    int len = strlen(str);

    for (i = 0; i < len; ) {
        char current = str[i];
        count = 1;
        while (i + count < len && str[i + count] == current) {
            count++;
        }
        printf("%c%d", current, count);
        i += count;
    }
}

int main() 
{
    char *str=malloc(1000);
    if(!str)
        return 0;
    printf("Enter the string\n");
    scanf(" %[^\n]",str);
    printf("Compressed string: ");
    runLengthEncode(str);
    return 0;
}
