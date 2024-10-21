#include <iostream>
#include <cstring>
using namespace std;

class StringManipulation {
public:
    void findFrequency(const char* str) {
        int freq[256] = {0};
        for (int i = 0; str[i] != '\0'; i++) {
            freq[(int)str[i]]++;
        }
        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) {
                cout << (char)i << ": " << freq[i] << endl;
            }
        }
    }
};

int main() {
    StringManipulation sm;
    char str[100];

    cout << "Enter a string: ";
    cin.getline(str, 100);

    sm.findFrequency(str);
    return 0;
}
