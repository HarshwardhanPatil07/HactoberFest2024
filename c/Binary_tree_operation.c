#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int n = 1;
struct node *tree;
void create_tree(struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *mirrorImage(struct node *);
int totalNodes(struct node *);
int Height(struct node *);
void displayLeafNodes(struct node *tree);
struct node *deleteTree(struct node *);
void search(struct node *root1, struct node *root, int a);
int main()
{
    int a, flag;
    int choice, val;
    struct node *ptr;
    printf("\n *****MAIN MENU****** \n");
    printf("\n 1. Insert Element");
    printf("\n 2. Preorder Traversal");
    printf("\n 3. Inorder Traversal");
    printf("\n 4. Postorder Traversal");
    printf("\n 5. Count the total number of nodes");
    printf("\n 6. Determine the height of the tree");
    printf("\n 7. Find the mirror image of the tree");
    printf("\n 8. Display leaf nodes");
    printf("\n 9. Delete the tree");
    printf("\n 10. Exit");
    printf("\n 11. search element");
    create_tree(tree);
    do
    {
        printf("\n\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the value of the new node : ");
            scanf("%d", &val);
            tree = insertElement(tree, val);
            break;
        case 2:
            printf("\n The elements of the tree are(preorder) : \n");
            preorderTraversal(tree);
            break;
        case 3:
            printf("\n The elements of the tree are(inorder): \n");
            inorderTraversal(tree);
            break;
        case 4:
            printf("\n The elements of the tree are(postorder) : \n");
            postorderTraversal(tree);
            break;
        case 5:
            printf("\n Total no. of nodes = %d", totalNodes(tree));
            break;
        case 6:
            printf("\n The height of the tree = %d", Height(tree));
            break;
        case 7:
            tree = mirrorImage(tree);
            break;
        case 8:
            printf("\n Leaf nodes of the tree are: \n");
            displayLeafNodes(tree);
            break;
        case 9:
            tree = deleteTree(tree);
            break;
        case 11:
            printf("enter the element you want to search = ");
            scanf("%d", &a);
            search(tree, tree, a);
            break;
        }

    } while (choice != 10);
    return 0;
}
void create_tree(struct node *tree)
{
    tree = NULL;
}
struct node *insertElement(struct node *tree, int val)
{
    struct node *ptr, *nodeptr, *parentptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;
    if (tree == NULL)
    {
        tree = ptr;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->data)
                nodeptr = nodeptr->left;
            else
                nodeptr = nodeptr->right;
        }
        if (val < parentptr->data)
            parentptr->left = ptr;
        else
            parentptr->right = ptr;
    }
    return tree;
}
void preorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        printf("%d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}
void inorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        inorderTraversal(tree->left);
        printf("%d\t", tree->data);
        inorderTraversal(tree->right);
    }
}
void postorderTraversal(struct node *tree)
{
    if (tree != NULL)
    {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d\t", tree->data);
    }
}
int totalNodes(struct node *tree)
{
    if (tree == NULL)
        return 0;
    else
        return (totalNodes(tree->left) + totalNodes(tree->right) + 1);
}
int Height(struct node *tree)
{
    int leftheight, rightheight;
    if (tree == NULL)
        return 0;
    else
    {
        leftheight = Height(tree->left);
        rightheight = Height(tree->right);
        if (leftheight > rightheight)
            return (leftheight + 1);
        else
            return (rightheight + 1);
    }
}
struct node *mirrorImage(struct node *tree)
{
    struct node *ptr;
    if (tree != NULL)
    {
        mirrorImage(tree->left);
        mirrorImage(tree->right);
        ptr = tree->left;
        ptr->left = ptr->right;
        tree->right = ptr;
    }
}
struct node *deleteTree(struct node *tree)
{
    if (tree != NULL)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}
void displayLeafNodes(struct node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    if (tree->left == NULL && tree->right == NULL)
    {
        printf("%d\t", tree->data);
    }
    displayLeafNodes(tree->left);
    displayLeafNodes(tree->right);
}
void search(struct node *root1, struct node *root, int a)
{
    if (a == root->data)
    {
        printf("element FOUND");
    }
    if (a > root->data && n != totalNodes(root1))
    {
        root = root->right;
        search(root1, root, a);
        n++;
    }
    if (a < root->data && n != totalNodes(root1))
    {
        root = root->left;
        search(root1, root, a);
        n++;
    }
    if (n == totalNodes(root1))
        printf("element NOT FOUND");
}