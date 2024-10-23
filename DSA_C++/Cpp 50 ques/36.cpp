#include <iostream>
using namespace std;

class StringManipulation {
public:
    void copyString(char* dest, const char* src) {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
};

int main() {
    StringManipulation sm;
    char source[100], destination[100];

    cout << "Enter a string: ";
    cin.getline(source, 100);

    sm.copyString(destination, source);
    cout << "Copied string: " << destination << endl;

    return 0;
}
