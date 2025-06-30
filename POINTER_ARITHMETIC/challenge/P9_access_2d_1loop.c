/*9.You’re given a dynamically allocated 2D matrix (as int **). 
How can you access and manipulate its elements using only a single loop and pointer arithmetic?*/
#include <stdio.h>
#include <stdlib.h>
int main() 
{
            int rows , cols;
            printf("Enter the number of rows and columns\n");
            scanf("%d%d",&rows,&cols);
            int **matrix = malloc(rows * sizeof(int *));
            for (int r = 0; r < rows; r++) 
            {
                matrix[r] = malloc(cols * sizeof(int));
            }
            int count = 1;
            for (int i = 0; i < rows*cols; i++) 
            {
                int r=i/cols;
                int c=i%cols;
                    *(*(matrix + r) + c) = count++; 
            }
    

    printf("Non-Contiguous Memory Matrix:\n");

            for (int i = 0; i < rows*cols; i++) 
            {
                int r=i/cols;
                int c=i%cols;
                printf("%3d ", *(*(matrix + r) + c));
                if(c==cols-1)
                    printf("\n");
            }

            for (int r = 0; r < rows; ++r) 
            {
                free(matrix[r]);
            }
            free(matrix);

    return 0;
}
