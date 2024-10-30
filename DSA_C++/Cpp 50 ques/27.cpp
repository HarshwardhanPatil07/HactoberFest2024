#include <iostream>
#include <cmath>
using namespace std;

class NumberConverter {
    public:

    int binaryToDecimal(int num) {
        int remainder, decimal = 0, i = 0;
        while (num != 0) {
            remainder = num % 10;
            decimal += remainder * pow(2, i);  
            num /= 10;  
            i++;
        }
        return decimal;
    }

 
    int decimalToBinary(int n) {
        int binary = 0, i = 1;
        while (n != 0) {
            binary += (n % 2) * i;  
            n /= 2;  
            i *= 10; 
        }
        return binary;
    }
};

int main() {
    NumberConverter converter;  
    int choice, number;

    cout << "1. Binary to Decimal" << endl;
    cout << "2. Decimal to Binary" << endl;
    cout << "Choose an option: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter a binary number: ";
        cin >> number;
        cout << "Decimal equivalent: " << converter.binaryToDecimal(number) << endl;
    } else if (choice == 2) {
        cout << "Enter a decimal number: ";
        cin >> number;
        cout << "Binary equivalent: " << converter.decimalToBinary(number) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
