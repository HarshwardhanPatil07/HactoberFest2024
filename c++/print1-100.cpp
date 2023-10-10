#include <bits/stdc++.h>
using namespace std;
void printNumbers(int current, int end) {
    if (current <= end) {
        cout << current << " ";
        printNumbers(current + 1, end);
    }
}

int main() {
    printNumbers(1, 100);
    cout << endl;
    return 0;
}
