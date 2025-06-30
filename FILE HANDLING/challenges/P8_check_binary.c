/*8.How would you detect if a file is a text file or a binary file in C? Write a function for this and discuss its limitations.*/
#include <stdio.h>
#include <ctype.h>

int is_text_file(const char *filename) 
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) return -1;

    int ch, count = 0, nontext = 0;
    while ((ch = fgetc(fp)) != EOF && count < 1000) 
    {
        if ((ch != 9) && (ch != 10) && (ch != 13) && !isprint(ch))
            nontext++;
        count++;
    }
    fclose(fp);

    if (nontext > 5)
        return 0; 
    else
        return 1; 
}

int main() 
{
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    int result = is_text_file(filename);

    if (result == 1)
        printf("It is a text file.\n");
    else if (result == 0)
        printf("It is a binary file.\n");
    else
        printf("Error opening the file.\n");

    return 0;
}
