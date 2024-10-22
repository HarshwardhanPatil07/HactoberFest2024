#include<iostream>
using namespace std;

struct node {
    public:
    int data;
    node* next;
    
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTheStart(node* &head, int data) {
    node* newnode = new node(data);
    newnode->next = head;
    head = newnode;
}

void deleteAtTheEnd(node* &head) {
    if (head == NULL) {  // List is empty
        cout << "The list is already empty. No node to delete." << endl;
        return;
    }
    if (head->next == NULL) {  // List has only one node
        delete head;
        head = NULL;
        cout<<"List is already empty"<<endl;
        return;
    }
    
    // Traverse to the second last node
    node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Delete the last node
    delete temp->next;
    temp->next = NULL;
}

// Function to print the list
void print(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* head = new node(12);

    // Adding more nodes at the start
    insertAtTheStart(head, 22);
    insertAtTheStart(head, 25);
    insertAtTheStart(head, 26);
    insertAtTheStart(head, 27);

    cout << "Original list: ";
    print(head);

    // Deleting the last node
    deleteAtTheEnd(head);

    cout << "List after deleting the last element: ";
    print(head);

    return 0;
}
