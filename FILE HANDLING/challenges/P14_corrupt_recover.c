/*14.Given a corrupted file where some data blocks are missing or replaced by zeros, 
how would you recover as much useful data as possible using C?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

bool is_zero_block(unsigned char *block, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (block[i] != 0)
            return false;
    }
    return true;
}

int main(int argc, char *argv[]) 
{
    FILE *in = fopen(argv[1], "rb");
    FILE *out = fopen(argv[2], "wb");
    
    unsigned char buffer[BLOCK_SIZE];
    size_t bytesRead;
    size_t recoveredBlocks = 0, skippedBlocks = 0;

    while ((bytesRead = fread(buffer, 1, BLOCK_SIZE, in)) > 0) {
        if (is_zero_block(buffer, bytesRead)) {
            skippedBlocks++;
            continue;
        }
        fwrite(buffer, 1, bytesRead, out);
        recoveredBlocks++;
    }

    printf("Recovered %zu blocks, skipped %zu zeroed blocks\n", recoveredBlocks, skippedBlocks);

    fclose(in);
    fclose(out);
    return 0;
}
