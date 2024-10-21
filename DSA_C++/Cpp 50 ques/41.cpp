#include <iostream>
using namespace std;

class SwapNumbers {
public:
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

int main() {
    SwapNumbers sn;
    int num1, num2;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << endl;
    sn.swap(&num1, &num2);
    cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}
