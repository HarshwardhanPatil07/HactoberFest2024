#include <iostream>
using namespace std;

class AverageCalculator {
public:
    double calculateAverage(int arr[], int size) {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += arr[i];
        }
        return (sum) / size;
    }
};

int main() {
    AverageCalculator calculator;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Average: " << calculator.calculateAverage(arr, n) << endl;

    return 0;
}



#include <iostream>
using namespace std;

class LargestElementFinder {
public:
    int findLargest(int arr[], int size) {
        int largest = arr[0];
        for (int i = 1; i < size; ++i) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }
        return largest;
    }
};

int main() {
    LargestElementFinder finder;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Largest element: " << finder.findLargest(arr, n) << endl;

    return 0;
}
