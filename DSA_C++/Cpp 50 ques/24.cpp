#include <iostream>

using namespace std;

class Pyramid {
public:
    void createPyramid(int rows) {
        for (int i = 1; i <= rows;i++) {
            for (int j = 1; j <= rows - i;j++) {
                cout << " ";
            }
            for (int k = 1; k <= 2 * i - 1;k++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    Pyramid pyramid;
    int rows;
    cout << "Enter the number of rows: ";
    cin >> rows;

    pyramid.createPyramid(rows);
    return 0;
}
