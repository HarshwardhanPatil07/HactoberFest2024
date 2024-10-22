#include <iostream>
#define MAXSIZE 100 // Define the maximum size of the queue

using namespace std;

class Queue {
private:
    int front;
    int rear;
    int queue[MAXSIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return rear == MAXSIZE - 1;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front < 0 || front > rear;
    }

    // Function to insert an element into the queue
    void enqueue(int newElement) {
        if (isFull()) {
            cout << "Overflow\n";
            return;
        }
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear = rear + 1;
        }
        queue[rear] = newElement;
    }

    // Function to remove an element from the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return -1;
        }
        int value = queue[front];
        front = front + 1;

        // Reset the queue if it becomes empty after this operation
        if (front > rear) {
            front = rear = -1;
        }

        return value;
    }

    // Function to peek at the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return -1;
        }
        return queue[front];
    }

    // Function to get the size of the queue
    int size() {
        return isEmpty() ? 0 : rear - front + 1;
    }

    // Function to display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << "\n"; // Should print 10

    cout << "Dequeued element: " << q.dequeue() << "\n"; // Should print 10

    cout << "Front element after dequeue: " << q.peek() << "\n"; // Should print 20

    cout << "Queue size: " << q.size() << "\n"; // Should print 2

    if (q.isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue is not empty\n";
    }

    // Display all elements in the queue
    q.display(); // Should print 20 30

    return 0;
}
