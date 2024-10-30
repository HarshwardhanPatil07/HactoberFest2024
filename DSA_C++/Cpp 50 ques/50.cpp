#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex() : real(0), imag(0) {}
    Complex(int r, int i) : real(r), imag(i) {}

    // Overloading the '+' operator
    Complex operator + (const Complex& obj) {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(5, 6);
    Complex c3 = c1 + c2; // Using overloaded + operator

    cout << "Result of addition: ";
    c3.display();

    return 0;
}
