#include <iostream>
using namespace std;

class ArrayManipulation {
public:
    void accessElements(int* arr, int size) {
        for (int i = 0; i < size; i++) {
            cout << "Element " << i + 1 << ": " << *(arr + i) << endl;
        }
    }
};

int main() {
    ArrayManipulation am;
    int arr[5] = {1, 2, 3, 4, 5};

    am.accessElements(arr, 5);
    return 0;
}
