#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* leftchild;
    Node* rightchild;
};


Node* newnode(int data){
    Node* node = new Node();
    node->data = data;
    node->leftchild = nullptr;
    node->rightchild = nullptr;
    return node;
}

void Inorder(Node* node){
    if(node == nullptr) return;

    Inorder(node->leftchild);
    cout<<node->data<<" ";
    Inorder(node->rightchild);
}
void Preorder(Node* node){
    if(node == nullptr) return;

    cout<<node->data<<" ";
    Preorder(node->leftchild);
    Preorder(node->rightchild);
}


void Postorder(Node* node){
    if(node == nullptr) return;
    
    Postorder(node->leftchild);
    Postorder(node->rightchild);
    cout<<node->data<<" ";
}


int main (){
    Node* root = newnode(1);
    root->leftchild = newnode(9);
    root->rightchild = newnode(12);
    root->leftchild->leftchild = newnode(4);
    root->leftchild->rightchild = newnode(7);
    root->leftchild = newnode(10);
    root->rightchild->rightchild = newnode(18);

    cout << "Preorder traversal: ";
    Preorder(root);
    cout << endl;

    // Inorder traversal
    cout << "Inorder traversal: ";
    Inorder(root);
    cout << endl;

    // Postorder traversal
    cout << "Postorder traversal: ";
    Postorder(root);
    cout << endl;

    return 0;
}