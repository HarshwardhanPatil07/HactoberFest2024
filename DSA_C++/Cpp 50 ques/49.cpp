#include <iostream>
using namespace std;

class AddNumbers {
private:
    int num1, num2;

public:
    void setNumbers(int a, int b) {
        num1 = a;
        num2 = b;
    }

    int getSum() {
        return num1 + num2;
    }
};

int main() {
    AddNumbers addition;
    addition.setNumbers(10, 20);
    cout << "Sum: " << addition.getSum() << endl;

    return 0;
}
