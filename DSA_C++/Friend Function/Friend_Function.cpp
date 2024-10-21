
#include <iostream>
using namespace std;

class AnotherClass; // Forward declaration of AnotherClass

class MyClass {
private:
    int num_1;

public:
    MyClass(int value) : num_1(value) {}

    // Friend function declaration to access private members
    friend int findMax(MyClass&, AnotherClass&);
};

class AnotherClass {
private:
    int num_2;

public:
    AnotherClass(int value) : num_2(value) {}

    // Friend function declaration to access private members
    friend int findMax(MyClass&, AnotherClass&);
};

// Friend function definition outside the class
int findMax(MyClass &obj1, AnotherClass &obj2) {
    return (obj1.num_1 > obj2.num_2) ? obj1.num_1 : obj2.num_2;
}

int main() {
    int num_1, num_2;

    cout << "Enter the first number (MyClass): ";
    cin >> num_1;

    cout << "Enter the second number (AnotherClass): ";
    cin >> num_2;

    MyClass obj1(num_1);
    AnotherClass obj2(num_2);

    int max_value = findMax(obj1, obj2);

    cout << "The maximum number is: " << max_value << endl;

    return 0;
}
