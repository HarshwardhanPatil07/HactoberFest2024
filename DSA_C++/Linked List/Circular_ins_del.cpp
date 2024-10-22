#include <iostream>
using namespace std;

class CircularLinkedList {
public:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };

    Node* head = nullptr;

    // Method to insert a node at the start
    void insertAtStart(int data) {
        Node* newNode = new Node(data);
        
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    // Method to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Method to delete a node at the start
    void deleteAtStart() {
        if (head == nullptr) {
            cout << "The list is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;

        // If there's only one node in the list
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            // Traverse to the last node
            while (temp->next != head) {
                temp = temp->next;
            }

            Node* toDelete = head;
            temp->next = head->next;
            head = head->next;
            delete toDelete;
        }
    }

    // Method to delete a node at the end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "The list is empty. Nothing to delete." << endl;
            return;
        }

        Node* temp = head;

        // If there's only one node in the list
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* prev = nullptr;

            // Traverse to the last node
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }

            prev->next = head;
            delete temp;
        }
    }

    // Method to display the list
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        while(temp != head){
            cout<<temp -> data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtStart(10);
    cll.insertAtStart(20);
    cll.insertAtEnd(30);
    cll.display();

    cll.deleteAtStart();
    cll.display();

    cll.deleteAtEnd();
    cll.display();

    return 0;
}
