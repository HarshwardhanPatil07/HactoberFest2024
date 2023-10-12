// Floyd's Triangle using c++
// github_username -> faizanusmani06
// Date -> 12/oct/2023

#include <iostream>
using namespace std;

int main() {

    int rows, number = 1;

    cout << "Enter number of rows: ";
    cin >> rows;

    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= i; ++j) {
            cout << number << " ";
            ++number;
        }

        cout << endl;
    }

    return 0;
}
