#include <iostream>
using namespace std;

class Stack {
    int arr[5];
    int top;
public:
    Stack() : top(-1) {}

    void push(int value) {
        if (top == 4)
            cout << "Stack overflow" << endl;
        else
            arr[++top] = value;
    }

    void pop() {
        if (top == -1)
            cout << "Stack underflow" << endl;
        else
            top--;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
        } else {
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Stack elements: ";
    stack.display();

    stack.pop();
    cout << "Stack after pop: ";
    stack.display();
    
    return 0;
}
