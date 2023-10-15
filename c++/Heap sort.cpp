//Username=manish-bhukar
//Date=15/10/2023
//sorting of array using heap sort
#include <iostream>
using namespace std;

void maxheapify(int arr[], int N, int i)
{
    // Initialize largest as root
    int largest = i;
    // left child= 2*i + 1
    int l = 2 * i + 1;
 
    // right child= 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root then largest is left
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        maxheapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
    // Build heap (rearrange array) beause at below n/2 leaf node so no need of calling heapify for them
    for (int i = N / 2 - 1; i >= 0; i--)
        maxheapify(arr, N, i);
 
    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        maxheapify(arr, i, 0);
    }
}
 
// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);//for size of array
 
    // Function call for heap sort
    heapSort(arr, N);
 
    cout << "Sorted array is \n";
    printArray(arr, N);//for printing resultant array
}