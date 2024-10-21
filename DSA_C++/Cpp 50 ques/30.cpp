#include <iostream>
using namespace std;

class Math {
public:
    // Function to find G.C.D using recursion
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

int main() {
    int num1, num2;
    Math math;  // Creating an object of class Math

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Calling gcd function through the object
    cout << "G.C.D is: " << math.gcd(num1, num2) << endl;

    return 0;
}
