// Half pyramid using alphabet
// Date -> 12/oct/2023
// github username -> faizanusmani06
#include <iostream>
using namespace std;

int main() {

    char input, alphabet = 'A';

    cout << "Enter the uppercase character you want to print in the last row: ";
    cin >> input;

    // convert input character to uppercase
    input = toupper(input);

    for(int i = 1; i <= (input-'A'+1); ++i) {
        for(int j = 1; j <= i; ++j) {
            cout << alphabet << " ";
        }
        ++alphabet;

        cout << endl;
    }
    return 0;
}
