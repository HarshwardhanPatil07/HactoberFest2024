#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *right_child;
    struct node *left_child;
};

struct node *tree,*root,*newnode,*nodeptr,*parentptr;

void create(struct node *tree)
{
    tree = NULL;
}

struct node *insert(struct node *newnode,int x)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = x;
    newnode -> left_child = NULL;
    newnode -> right_child = NULL;
    
    if(tree == NULL)
    {
        tree = newnode;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while(nodeptr != NULL)
        {
            parentptr = nodeptr;
            if(x < nodeptr->data)
            {
                nodeptr = nodeptr -> left_child;
            }
            else
            {
                nodeptr = nodeptr -> right_child;
            }
        }
        if(x < parentptr->data)
        {
            parentptr -> left_child = newnode;
        }
        else
        {
            parentptr -> right_child = newnode;
        }
    }
    return tree;
}

void preorder(struct node *tree)
{
    if(tree != NULL)
    {
        printf(" %d \t",tree -> data);
        preorder(tree -> left_child);
        preorder(tree -> right_child);
    }
}

void inorder(struct node *tree)
{
    if(tree != NULL)
    {
        inorder(tree -> left_child);
        printf(" %d \t",tree -> data);
        inorder(tree -> right_child);
    }
}

void postorder(struct node *tree)
{
    if(tree != NULL)
    {
        postorder(tree -> left_child);
        postorder(tree -> right_child);
        printf(" %d \t",tree -> data);
    }
}

int main()
{
    int choice = 1,val;
    create(tree);
    while(choice != 0)
    {
        printf("\n Enter the value of a newnode: ");
        scanf("%d",&val);
        tree = insert(tree,val);
        printf("\n Press 1 to continue: ");
        scanf("%d",&choice);
    }
    printf("\n ===========Pre-Order Traversal=========== \n");
    preorder(tree);
    printf("\n ===========In-Order Traversal=========== \n");
    inorder(tree);
    printf("\n ===========Post-Order Traversal=========== \n");
    postorder(tree);
    return 0;
}
