#include <iostream>
using namespace std;

class Unary {
    int value;
public:
    Unary(int v) : value(v) {}

    void operator++() { // Overloading ++ operator
        value++;
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Unary u(10);
    cout << "Before increment: ";
    u.display();

    ++u;  // Calling overloaded ++ operator
    cout << "After increment: ";
    u.display();

    return 0;
}
