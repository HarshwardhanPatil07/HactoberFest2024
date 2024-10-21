#include <iostream>
using namespace std;

class Number {
private:
    int num;

public:
    // Function to set the number
    void setNumber(int n) {
        num = n;
    }

    // Function to check if the number is even or odd
    void checkEvenOdd() {
        if (num % 2 == 0) {
            cout << num << " is Even." << endl;
        } else {
            cout << num << " is Odd." << endl;
        }
    }
};

int main() {
    Number number;
    int input;

    cout << "Enter a number: ";
    cin >> input;

    number.setNumber(input);
    number.checkEvenOdd();

    return 0;
}
