/*1.Pointer Increment and Access
Task: Log Session an integer array with 5 elements. 
Use a pointer to access and print the third element by incrementing the pointer appropriately.
Sample data:
int arr[] = {5, 10, 15, 20, 25};
Expected output:
Third element is 15*/

#include<stdio.h>
int main()
{
        int arr[] = {5, 10, 15, 20, 25};
        int *p=arr;
        
        while(p!=arr+5){
            if(p==arr+2){
                printf("The third element is %d \n",*p);
                break;}
                p++;

        }

    }