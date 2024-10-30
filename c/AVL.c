#include <stdio.h>
#include <stdlib.h>
struct Node
{
struct Node *left, *right;
int data;
int height;
};
struct Node *root = NULL;
int Max(int n1, int n2)
{

return n1 > n2 ? n1 : n2;
}
struct Node *getNewNode(int data)
{
struct Node *newNode;
newNode = (struct Node *)malloc(sizeof(struct Node));
newNode->data = data;
newNode->left = NULL;
newNode->right = NULL;
newNode->height = 1;
return newNode;
}
int FindHeight(struct Node *root)
{

if (root == NULL)
{
return 0;
}
return root->height;
}
int getBalanceFactor(struct Node *root)
{

if (root == NULL)
{
return 0;
}
return (FindHeight(root->left) - FindHeight(root->right));
}

struct Node *rightRotate(struct Node *root)
{

struct Node *leftChild = root->left;
struct Node *leftRightChild = leftChild->right;
leftChild->right = root;
root->left = leftRightChild;
root->height = Max(FindHeight(root->left), FindHeight(root->right)) + 1;
leftChild->height = Max(FindHeight(leftChild->left), FindHeight(leftChild->right)) + 1;
return leftChild;
}
struct Node *leftRotate(struct Node *root)
{

struct Node *rightChild = root->right;
struct Node *rightLeftChild = rightChild->left;
rightChild->left = root;
root->right = rightLeftChild;
root->height = Max(FindHeight(root->left), FindHeight(root->right)) + 1;
rightChild->height = Max(FindHeight(rightChild->left), FindHeight(rightChild->right)) + 1;
return rightChild;
}
struct Node *insert(struct Node *root, int data)
{

if (root == NULL)
{
root = getNewNode(data);
return root;
}
if (data < root->data)
{
root->left = insert(root->left, data);
}
else if (data > root->data)
{
root->right = insert(root->right, data);
}
else
{
return root;
}
root->height = Max(FindHeight(root->left), FindHeight(root->right)) + 1;
int balanceFactor = getBalanceFactor(root);
if (balanceFactor > 1 && data < root->left->data) 
{
return rightRotate(root);
}
if (balanceFactor < -1 && data > root->right->data) 
{
return leftRotate(root);
}
if (balanceFactor > 1 && data > root->left->data) 
{
root->left = leftRotate(root->left);
return rightRotate(root);
}
if (balanceFactor < -1 && data < root->right->data) 
{
root->right = rightRotate(root->right);
return leftRotate(root);
}
return root;
}
void display(struct Node *root, int space)
{

if (root == NULL)
{
return;
}
space += 20;
display(root->right, space);
printf("\n");
for (int i = 10; i < space; i++)
{
printf(" ");
}
printf("%d\n", root->data);
display(root->left, space);
}
int main()
{
struct Node *temp;
int data, choice, val, i;
printf("AVL tree Implementation :\n");
printf("1.Insert\n");
printf("2.Display\n");
printf("3.EXIT\n");
while (1)
{
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
printf("Enter the data to be inserted: ");
scanf("%d", &data);
root = insert(root, data);
break;
case 2:
display(root, 0);
break;
case 3:
exit(0);
default:
printf("Wrong choice\n");
};
}
return 0;
}
