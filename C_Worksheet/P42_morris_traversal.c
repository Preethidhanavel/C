/*Q42. Morris In-Order Traversal (No Stack/Recursion)--------------------------------------------------
Problem Statement:
 Traverse in-order by threading temporary right links to predecessor nodes.*/

#include <stdio.h>
#include <stdlib.h>

// Binary tree node structure
typedef struct N {
    int v;          // Node value
    struct N *l, *r; // Left and right child pointers
} N;

// Create a new node with value v
N* nn(int v) 
{
    N* n = malloc(sizeof(*n));
    n->v = v;
    n->l = n->r = NULL;
    return n;
}

// Morris In-order traversal without recursion or stack
void morris(N* cur) 
{
    while (cur) 
    {
        if (!cur->l) 
        {
            // No left child: visit current node and go right
            printf("%d ", cur->v);
            cur = cur->r;
        } 
        else 
        {
            // Find the inorder predecessor of current node
            N* pre = cur->l;
            while (pre->r && pre->r != cur)
                pre = pre->r;

            if (!pre->r) 
            {
                // Make current the right child of its inorder predecessor
                pre->r = cur;
                cur = cur->l;
            } 
            else 
            {
                // Revert the changes (thread removal), visit current node, go right
                pre->r = NULL;
                printf("%d ", cur->v);
                cur = cur->r;
            }
        }
    }
}

int main() 
{
    
    N* r = nn(2);
    r->l = nn(1);
    r->r = nn(3);

    morris(r);   // Output: 1 2 3
    puts("");
    return 0;
}
