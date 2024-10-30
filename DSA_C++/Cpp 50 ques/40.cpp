#include <iostream>
using namespace std;

class PointerDemo {
public:
    void pointerExample() {
        int a = 10;
        int* ptr = &a; // Pointer points to the address of 'a'

        cout << "Value of a: " << a << endl;
        cout << "Address of a: " << &a << endl;
        cout << "Pointer points to value: " << *ptr << endl;
        cout << "Pointer's address: " << ptr << endl;
    }
};

int main() {
    PointerDemo pd;
    pd.pointerExample();
    return 0;
}
