/*2.Explain the difference between text mode and binary mode while opening a file in C. 
Provide scenarios where each is preferable and the possible issues if the wrong mode is chosen.*/
#include <stdio.h>

void text_mode(const char *filename) 
{
    FILE *fp = fopen(filename, "r");
    if (!fp) 
    {
        perror("file not opened:");
        return;
    }

    printf("\nReading in text mode:\n");
    int ch;
    while ((ch = fgetc(fp)) != EOF) 
    {
       putchar(ch);
    }
    fclose(fp);
}

void binary_mode(const char *filename) 
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("file not opened");
        return;
    }

    printf("\nReading in binary mode (hex values):\n");
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%02X ", ch);
    }
    fclose(fp);
    printf("\n");
}

int main() {
    char filename[256];
    printf("Enter the file name: ");
    scanf("%s", filename);

    text_mode(filename);
    binary_mode(filename);

    return 0;
}
