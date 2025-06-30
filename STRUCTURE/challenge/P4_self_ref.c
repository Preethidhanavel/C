/*4.How would you design a structure suitable for a linked list or tree? What is special about the definition*/
struct Node {
    int data;
    struct Node *next;
};
/* In this the next structure pointer is a self referential structure pointer. 
this is used to link the node to another node and with head pointer.*/