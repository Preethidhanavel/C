/*9.Write a program that reverses the content of a large file in place (without using extra files or enough RAM to 
load the whole file). 
Hint: Consider using file seek operations.*/
#include <stdio.h>

void reverse_file(const char *filename) 
{
    FILE *fp = fopen(filename, "rb+");
    if (!fp) 
    {
        printf("Failed to open file.\n");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long end = ftell(fp);
    long left = 0;
    long right = end - 1;
    char c1, c2;

    while (left < right) 
    {
        fseek(fp, left, SEEK_SET);
        fread(&c1, 1, 1, fp);

        fseek(fp, right, SEEK_SET);
        fread(&c2, 1, 1, fp);

        fseek(fp, left, SEEK_SET);
        fwrite(&c2, 1, 1, fp);

        fseek(fp, right, SEEK_SET);
        fwrite(&c1, 1, 1, fp);

        left++;
        right--;
    }

    fclose(fp);
    printf("File reversed in place.\n");
}

int main() 
{
    char filename[100];
    printf("Enter filename to reverse: ");
    scanf("%s", filename);

    reverse_file(filename);
    return 0;
}
