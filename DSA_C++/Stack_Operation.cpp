#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int stack_arr[MAX];
    int top;

public:
    // Constructor using initializer list to initialize top to -1
    Stack() : top(-1) {}

    void push(int data) {
        if (top == MAX - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top += 1;
        stack_arr[top] = data;  // Increment top first, then assign data
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }
        cout << "Popped element: " << stack_arr[top--] << endl; // Print data, then decrement top
    }

    bool isEmpty() const {
        return top == -1;
    }

    void printTop() const {             //peek
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element: " << stack_arr[top] << endl;
        }
    }

    void printAllElements() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << stack_arr[i] << " ";
            }
            cout << endl;
        }
    }

    void quit() const {
        cout << "Quitting program..." << endl;
        exit(0);
    }
};

int main() {
    Stack s;
    int choice, data;

    while (true) {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Is Empty\n";
        cout << "4. Print Top Element\n";
        cout << "5. Print All Elements\n";
        cout << "6. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to push: ";
                cin >> data;
                s.push(data);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << (s.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;
                break;
            case 4:
                s.printTop();
                break;
            case 5:
                s.printAllElements();
                break;
            case 6:
                s.quit();
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}


