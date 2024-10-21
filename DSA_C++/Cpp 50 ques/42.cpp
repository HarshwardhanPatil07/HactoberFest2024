#include <iostream>
#include <cstring>
using namespace std;

class StringManipulation {
public:
    void countVowelsConsonants(const char* str, int* vowels, int* consonants) {
        *vowels = *consonants = 0;
        for (const char* ptr = str; *ptr != '\0'; ptr++) {
            if (isalpha(*ptr)) {
                char ch = tolower(*ptr);
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    (*vowels)++;
                else
                    (*consonants)++;
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

    sm.countVowelsConsonants(str, &vowels, &consonants);
    cout << "Vowels: " << vowels << ", Consonants: " << consonants << endl;
    return 0;
}
