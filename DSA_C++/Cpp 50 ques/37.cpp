#include <iostream>
#include <cstring>
using namespace std;

class StringManipulation {
public:
    void countVowelsConsonants(const char* str, int& vowels, int& consonants) {
        vowels = consonants = 0;
        for (int i = 0; str[i] != '\0'; i++) {
            if (isalpha(str[i])) {
                char ch = tolower(str[i]);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    vowels++;
                else
                    consonants++;
            }
        }
    }
};

int main() {
    StringManipulation sm;
    char str[100];
    int vowels, consonants;

    cout << "Enter a string: ";
    cin.getline(str, 100);

    sm.countVowelsConsonants(str, vowels, consonants);
    cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;
    return 0;
}
