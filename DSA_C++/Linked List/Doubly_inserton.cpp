/*
#include <iostream>
using namespace std;

class DoublyLinkedList {
public:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        // Constructor for Node
        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    Node* head;

   
    DoublyLinkedList() {
        head = NULL; // Initialize head to NULL
    }

    // Function to insert a node at the start
    void insertAtStart(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) { // If the list is empty
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Insert nodes at the start
    dll.insertAtStart(10);
    dll.insertAtStart(20);
    dll.insertAtStart(30);
    dll.insertAtStart(40);

    cout << "Doubly Linked List: ";
    dll.display();

    return 0;
}*/
                                              
/**********************************start and nth position */


#include <iostream>
using namespace std;

class DoublyLinkedList {
public:
    struct Node {
        int data;
        Node* prev;
        Node* next;

        // Constructor for Node
        Node(int data) {
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    Node* head;

    DoublyLinkedList() {
        head = NULL; // Initialize head to NULL
    }

    // Function to insert a node at the start
    void insertAtStart(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) { // If the list is empty
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at nth position
    void insertAtNthPosition(int data, int position) {
        Node* newNode = new Node(data);

        if (position == 0) { // Insert at the start
            insertAtStart(data);
            return;
        }

        Node* temp = head;
        int count = 0;

        // Traverse to the node just before the nth position
        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) { // If position is out of bounds
            cout << "Position out of range" << endl;
            delete newNode; // Free the allocated memory
        } else {
            newNode->next = temp->next;
            newNode->prev = temp;

            if (temp->next != NULL) { // If not inserting at the end
                temp->next->prev = newNode;
            }

            temp->next = newNode;
        }
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Insert nodes at the start
    dll.insertAtStart(10);
    dll.insertAtStart(20);
    dll.insertAtStart(30);
    dll.insertAtStart(40);

    cout << "Doubly Linked List before insertion at nth position: ";
    dll.display();

    // Insert node at the 3rd index (0-based index)
    dll.insertAtNthPosition(25, 3);

    cout << "Doubly Linked List after insertion at 3rd index: ";
    dll.display();

    return 0;
}
