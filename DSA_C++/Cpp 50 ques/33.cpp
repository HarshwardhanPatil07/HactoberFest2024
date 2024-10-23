#include <iostream>
using namespace std;

class MatrixAdder {
public:
    void addMatrices(int mat1[3][3], int mat2[3][3], int result[3][3]) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result[i][j] = mat1[i][j] + mat2[i][j];
            }
        }
    }
};

int main() {
    MatrixAdder adder;
    int mat1[3][3], mat2[3][3], result[3][3];

    cout << "Enter elements of first matrix (3x3): ";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter elements of second matrix (3x3): ";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> mat2[i][j];
        }
    }

    adder.addMatrices(mat1, mat2, result);

    cout << "Resultant matrix after addition: " << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
