/* Q06. Iterative In-Order Traversal of a Binary Tree------------------------------------------
Problem Statement:
 Traverse a binary tree in-order (Left, Node, Right) without recursion by 
 using an explicit stack.*/

#include <stdio.h>
#include <stdlib.h>

// Define a node of the binary tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node with given data
struct Node* newNode(int data) 
{
    struct Node* n = malloc(sizeof(struct Node)); // allocate memory
    n->data = data;       // store data
    n->left = n->right = NULL; // no children yet
    return n;
}

// Iterative Inorder Traversal using stack
void inorder(struct Node* root) 
{
    struct Node* stack[50];  // array used as stack
    int top = -1;            // stack is empty
    struct Node* curr = root;

    // Run until stack is empty and curr is NULL
    while (curr || top >= 0) {
        // Push left children to stack
        while (curr) {
            stack[++top] = curr; // push current node
            curr = curr->left;   // move left
        }

        // Pop node from stack
        curr = stack[top--];
        printf("%d ", curr->data); // visit node

        // Move to right child
        curr = curr->right;
    }
}

int main()
{
    struct Node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);

    // Print inorder traversal
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}
