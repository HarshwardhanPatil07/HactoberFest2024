#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    
    cout << "Enter a string: ";
    cin >> input;

    // Reverse the string
    string reversed = "";
    for (int i = input.length() - 1; i >= 0; i--) {
        reversed += input[i];
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}
