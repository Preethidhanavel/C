/*20.Describe how you would write a crash-resilient file update function that never leaves the file in a partially updated state, 
even if the power fails mid-write.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int update_file_safely(const char *filename, const char *data) {
    char tmpname[512];
    snprintf(tmpname, sizeof(tmpname), "%s.tmp", filename);

    FILE *fp = fopen(tmpname, "w");
    if (!fp) 
    return -1;

    if (fputs(data, fp) == EOF) {
        fclose(fp);
        return -2;
    }

    if (fflush(fp) != 0) {
        fclose(fp);
        return -3;
    }

    int fd = _fileno(fp);
    if (_commit(fd) != 0) {
        fclose(fp);
        return -4;
    }

    fclose(fp);

    if (rename(tmpname, filename) != 0) {
        return -5;
    }

    /*int dir_fd = open(".", O_DIRECTORY| O_RDONLY);
    if (dir_fd >= 0) {
        fsync(dir_fd);
        close(dir_fd);
    }*/

    return 0;
}

int main() 
{
    const char *filename = "safe_output.txt";
    const char *data = "This is crash-resilient data\n";

    printf("Updating file: %s\n", filename);

    int result = update_file_safely(filename, data);

    if (result == 0) {
        printf("File updated safely.\n");
    } 
    else {
        fprintf(stderr, "Failed to update file safely\n");
        return 1;
    }

    return 0;
}