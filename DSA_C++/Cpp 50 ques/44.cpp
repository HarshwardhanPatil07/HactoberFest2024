#include <iostream>
using namespace std;

class Distance {
public:
    int feet;
    int inches;

    // Function to get input from the user
    void getInput() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    // Function to display the distance
    void display() {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    // Function to add two Distance objects
    Distance add(Distance d2) {
        Distance result;
        result.inches = inches + d2.inches;
        result.feet = feet + d2.feet + result.inches / 12;
        result.inches %= 12; // Convert excess inches to feet
        return result;
    }
};

int main() {
    Distance d1, d2, result;

    cout << "Enter first distance:\n";
    d1.getInput();

    cout << "Enter second distance:\n";
    d2.getInput();

    result = d1.add(d2);

    cout << "Sum of distances: ";
    result.display();

    return 0;
}
