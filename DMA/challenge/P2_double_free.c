/*What happens if you call free on the same pointer twice?
 How can you avoid this problem in your code?*/


#include<stdio.h>
#include<stdlib.h>

int main(){
int *ptr=malloc(sizeof(int));
if(ptr==NULL)return 1;
*ptr=42;
printf("Value:%d\n",*ptr);
free(ptr);
free(ptr);
}
