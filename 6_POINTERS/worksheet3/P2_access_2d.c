/*2.Accessing Multi-Dimensional Arrays with Pointers
Goal: Implement pointer arithmetic to traverse a 2D sensor data array efficiently without nested loops.
Activity:
Define a 3x3 integer matrix representing sensor readings:
int sensors[3][3] = {
  {100, 101, 102},
  {110, 111, 112},
  {120, 121, 122}
};
Assign a pointer to the first element of the matrix:
int *p = &sensors[0][0];
Use a single loop and pointer arithmetic to iterate over the matrix elements.
Print each sensor value accessed via the pointer.*/
#include<stdio.h>
int main()
{
      int sensors[3][3] = {{100, 101, 102},{110, 111, 112},{120, 121, 122}};
      int *p=&sensors[0][0];
      int m=sizeof(sensors)/sizeof(sensors[0]);
      int n=sizeof(sensors[0])/sizeof(sensors[0][0]);
      int i;
      for(i=0;i<m*n;i++){
        printf("%d ",*p++);
          if((i+1)%n==0)
            printf("\n");
      }
  
}