/*23.How can you dynamically allocate an array of structures, each containing its own dynamic array?
struct Block {
    int n;
    int *values;
};
struct Block *blocks = malloc(10 * sizeof(struct Block));*/


#include<stdio.h>
#include<stdlib.h>

struct block
{
    int n;
    int *values;
};

int main(){
    struct block *blocks=malloc(3*sizeof(struct block));
    for(int i=0;i<3;i++)
    {
        blocks[i].n=2;
        blocks[i].values=malloc(2*sizeof(int));
        for(int j=0;j<2;j++)
            blocks[i].values[j]=i*10+j;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
            printf("%d ",blocks[i].values[j]);
        printf("\n");
    }
    for(int i=0;i<3;i++)
        free(blocks[i].values);
    free(blocks);
}
