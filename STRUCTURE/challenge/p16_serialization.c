/*16.How would you serialize a structure with pointer members so you can save and reload it from a file
struct Buffer {
    int size;
    char *data;
};*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Buffer {
    int size;
    char *data;
};

int main() {
    struct Buffer buf;
    FILE *fp;

    buf.size = 6;
    buf.data = malloc(buf.size);
    memcpy(buf.data, "Hello", buf.size);

    fp = fopen("buffer.c", "w+");
    fwrite(&buf.size, sizeof(int), 1, fp);
    fwrite(buf.data, sizeof(char), buf.size, fp);
    fclose(fp);

    free(buf.data);
}
