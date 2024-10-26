#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    // for (int i = n - 1; i > 0; i--) {
    //     swap(arr[0], arr[i]);
    //     heapify(arr, i, 0);
    // }
    while(n>1){
        swap(arr[0], arr[n-1]);
        n--;
        heapify(arr, n, 0);
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    heapSort(arr);
    cout << "Sorted array is \n";
    printArray(arr);
    return 0;
}