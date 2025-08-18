/*1.How would you safely read a large file line-by-line in C, ensuring you never overflow your buffer, 
even if a line is extremely long? Describe your approach and key functions you’d use.*/
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp = fopen("largefile.txt", "r");
    if (!fp) 
    {
        perror("File opening failed");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    size_t read;

    while ((read = getline(&line, &len, fp)) != -1) 
    {   
        printf("Read %zd characters: %s", read, line);
    }

    free(line);
    fclose(fp);
    return 0;
}
