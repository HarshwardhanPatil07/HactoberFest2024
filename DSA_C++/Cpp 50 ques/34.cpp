#include <iostream>
#include <cstring>
using namespace std;

class StringManipulation {
public:
    int findLength(const char* str) {
        return strlen(str);
    }
};

int main() {
    StringManipulation sm;
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    cout << "Length of the string is: " << sm.findLength(str) << endl;
    return 0;
}
