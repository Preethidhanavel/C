/*12. Pointer and Recursion
Goal: Use pointers within recursive functions to manipulate data structures or strings.
Activity:
Write a recursive function to reverse a string using pointers.
Implement a recursive traversal of a linked list using pointers.
Use recursion to perform operations such as summing elements of an array via pointer traversal.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reversestring(char *start,char *end){
    if(start>=end) return;
    char temp=*start;
    *start=*end;
    *end=temp;
    reversestring(start+1,end-1);
}

struct node{
    int data;
    struct node*next;
};

void addbegin(struct node**head_ref,int value){
    struct node*new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void printlist(struct node*head){
    if(head==NULL){
        printf("NULL\n");
        return;
    }
    printf("%d->",head->data);
    printlist(head->next);
}

int sumarray(int *arr,int size){
    if(size==0) 
    return 0;
    return *arr+sumarray(arr+1,size-1);
}

int main(){
    char str[100];
    printf("Enter a string to reverse: ");
    scanf(" %[^\n]",str);

    reversestring(str,str+strlen(str)-1);
    printf("Reversed string: %s\n\n",str);

    struct node*head=NULL;
    int n,value;

    printf("Enter number of nodes to add at beginning: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter value for node %d: ",i+1);
        scanf("%d",&value);
        addbegin(&head,value);
    }

    printf("\nLinked List (Printed using recursion):\n");
    printlist(head);

    int size;
    printf("\nEnter size of array: ");
    scanf("%d",&size);

    int arr[size];
    printf("Enter %d elements:\n",size);
    for(int i=0;i<size;i++){
        printf("Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    int total=sumarray(arr,size);
    printf("\nSum of array elements = %d\n",total);

    return 0;
}
