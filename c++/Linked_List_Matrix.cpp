#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node *right, *down, *left, *up;
    
    // Constructor to create a new node
    Node(int val) {
        data = val;
        right = down = left = up = nullptr;
    }
};

// Function to create the linked list matrix from a 2D array
Node* constructLinkedListMatrix(int mat[][3], int rows, int cols) {
    // Array to store pointers to the first nodes of each row
    Node* rowStart[rows];
    
    // Create the first node (top-left corner)
    Node* head = new Node(mat[0][0]);
    rowStart[0] = head;
    
    // Create the rest of the first row
    Node* prev = head;
    for (int j = 1; j < cols; j++) {
        Node* temp = new Node(mat[0][j]);
        prev->right = temp;
        temp->left = prev;
        prev = temp;
    }
    
    // Now create the rest of the matrix row by row
    for (int i = 1; i < rows; i++) {
        // Create the first node of the i-th row
        Node* rowHead = new Node(mat[i][0]);
        rowStart[i] = rowHead;
        
        // Link the first column of the current row with the previous row
        rowStart[i-1]->down = rowHead;
        rowHead->up = rowStart[i-1];
        
        // Now create and link the rest of the nodes in this row
        prev = rowHead;
        for (int j = 1; j < cols; j++) {
            Node* temp = new Node(mat[i][j]);
            prev->right = temp;
            temp->left = prev;
            prev = temp;
            
            // Link the current node with the node above it
            rowStart[i-1]->right->down = temp;
            temp->up = rowStart[i-1]->right;
            rowStart[i-1] = rowStart[i-1]->right;
        }
    }
    
    return head;  // Return the head of the linked list matrix
}

// Function to print the linked list matrix by rows
void printLinkedListMatrix(Node* head, int rows, int cols) {
    Node* rowPointer = head;
    
    // Traverse each row
    while (rowPointer != nullptr) {
        Node* colPointer = rowPointer;
        
        // Traverse each column
        while (colPointer != nullptr) {
            cout << colPointer->data << " ";
            colPointer = colPointer->right;
        }
        cout << endl;
        
        rowPointer = rowPointer->down;  // Move to the next row
    }
}

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // Construct the linked list matrix
    Node* head = constructLinkedListMatrix(mat, 3, 3);
    
    // Print the linked list matrix
    printLinkedListMatrix(head, 3, 3);
    
    return 0;
}
