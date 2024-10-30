#include <iostream>
#include <cstring>
using namespace std;

class StringManipulation {
public:
    void concatenate(char* dest, const char* src) {
        strcat(dest, src);
    }
};

int main() {
    StringManipulation sm;
    char str1[100], str2[100];

    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);

    sm.concatenate(str1, str2);
    cout << "Concatenated string: " << str1 << endl;
    return 0;
}
