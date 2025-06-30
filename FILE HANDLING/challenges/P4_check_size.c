/*4.Describe how you would implement a log file that never grows beyond a certain size (for example, 1 MB). 
What would you do when the file exceeds the limit?*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LOG_SIZE (1024 * 1024) 

void write_log(const char *message) 
{
    FILE *fp = fopen("log.txt", "a+");
    if (!fp) return;

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    if (size >= MAX_LOG_SIZE) 
    {
        fclose(fp);
        fp = fopen("log.txt", "w"); 
    }

    fprintf(fp, "%s\n", message);
    fclose(fp);
}
