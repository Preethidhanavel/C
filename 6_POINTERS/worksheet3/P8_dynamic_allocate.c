/*8. Dynamic Allocation of 2D Register Block
Goal: Dynamically allocate and manage a two-dimensional register map for peripheral configuration.
Activity: 
Allocate memory for a 4x4 matrix of 32-bit registers using double pointers:
1.uint32_t **reg_block;
2.reg_block = malloc(rows * sizeof(uint32_t *));
3.for (int i = 0; i < rows; i++)
4.  reg_block[i] = malloc(cols * sizeof(uint32_t));
Initialize the matrix elements with example register values.
Print the matrix values via pointer dereferencing.
Free all allocated memory properly after use.*/


#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

int main()
{
    int rows=4;
    int cols=4;
    uint32_t **reg_block;

    reg_block=(uint32_t **)malloc(rows*sizeof(uint32_t *));
    if(reg_block==NULL){
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i=0;i<rows;i++){
        reg_block[i]=(uint32_t *)malloc(cols*sizeof(uint32_t));
        if(reg_block[i]==NULL){
            printf("Memory allocation failed\n");
            return 1;
        }
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            reg_block[i][j]=(i+1)*0x10+j;
        }
    }

    printf("Register Block Values:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("0x%x ",reg_block[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<rows;i++){
        free(reg_block[i]);
    }
    free(reg_block);
}
