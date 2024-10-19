#include <iostream>
using namespace std;

class Largest {
public:
    int findLargest(int arr[], int size) {
        int max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }
};

int main() {
    Largest largest;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Largest element is: " << largest.findLargest(arr, n) << endl;
    return 0;
}
