#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int x) {
        data = x;
        next = this;
        prev = this;
    }
};

class CircularDoublyLinkedList {
public:
    Node* head = nullptr;

    void insertBegin(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertEnd(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    void insertAtPosition(int x, int pos) {
        if (pos < 1) {
            cout << "Invalid position." << endl;
            return;
        }
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            int count = 1;
            while (count < pos - 1) {
                current = current->next;
                count++;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    }

    void deleteBegin() {
        if (head == nullptr) {
            cout << "Empty list" << endl;
        } else {
            Node* temp = head;
            if (head->next == head) {
                head = nullptr;
            } else {
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
            }
            delete temp;
        }
    }

    void deleteEnd() {
        if (head == nullptr) {
            cout << "Empty list" << endl;
        } else {
            Node* temp = head->prev;
            if (head->next == head) {
                head = nullptr;
            } else {
                head->prev = temp->prev;
                temp->prev->next = head;
            }
            delete temp;
        }
    }

    void deleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "Empty list" << endl;
        } else if (pos < 1) {
            cout << "Invalid position." << endl;
        } else {
            Node* current = head;
            int count = 1;
            while (count < pos && current->next != head) {
                current = current->next;
                count++;
            }
            if (count == pos) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            } else {
                cout << "Position not found." << endl;
            }
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "Empty list" << endl;
        } else {
            Node* temp = head;
            do {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            cout << endl;
        }
    }
};

int main() {
    CircularDoublyLinkedList myList;
    int choice, n, pos;
    do {
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Delete from the beginning" << endl;
        cout << "5. Delete from the end" << endl;
        cout << "6. Delete from a specific position" << endl;
        cout << "7. Display the list" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Input Element to insert: ";
                cin >> n;
                myList.insertBegin(n);
                break;
            case 2:
                cout << "Input element to insert: ";
                cin >> n;
                myList.insertEnd(n);
                break;
            case 3:
                cout << "Input element to insert: ";
                cin >> n;
                cout << "Enter position: ";
                cin >> pos;
                myList.insertAtPosition(n, pos);
                break;
            case 4:
                myList.deleteBegin();
                break;
            case 5:
                myList.deleteEnd();
                break;
            case 6:
                cout << "Enter position to be deleted: ";
                cin >> pos;
                myList.deleteAtPosition(pos);
                break;
            case 7:
                myList.display();
                break;
            case 8:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
