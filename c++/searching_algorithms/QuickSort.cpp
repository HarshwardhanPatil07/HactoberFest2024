//jo paryant element of i chota a pivot peksha toparyant increment...<=ny tr stop jevha motha
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int makePartition(vector<int> &arr, int low, int high)
{
    // define terms
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1) //increment i until you find element higher than pivot..till that when small element increment i..
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            // j++; silly
            j--;
        }
        //at this point i point and is stopped at element greater than pivot and j stopped at element smaller than pivot
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);  //dont swap pivot..because we have set it to arr[low]..which changesafter every division..thus pivot also changes
    return j;  //if you pass pivot..only the first pivot is considered
}

void quickSort(vector<int> &arr, int low, int high)
{
    // base case   ..silly mistake
    //  if(low<high)
    //  {
    //      return ;
    //  }

    if (low < high)
    {
        int partInd = makePartition(arr, low, high);
        quickSort(arr, low, partInd - 1);
        quickSort(arr, partInd + 1, high);
    }
}

vector<int> getFunc(vector<int> &arr)
{
    quickSort(arr, 0, arr.size() - 1); // pass low high vals
    return arr;
}

void printArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Initialize the vector anna
    vector<int> arr = {7, 9, 0, 5, 3, 4, 2, 1, 6};
    int n = arr.size();

    cout << "Before QuickSort :" << endl;
    printArray(arr, n);

    // Call the function and store the result
    vector<int> result = getFunc(arr); // to get a vector res...store it in vector var

    // Printer
    cout << "After Sorting :" << endl;
    printArray(arr, n);

    return 0;
}




//Normal
#include <iostream>
#include <vector>
using namespace std;

int makePartition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int partInd = makePartition(arr, low, high);
        quickSort(arr, low, partInd - 1);
        quickSort(arr, partInd + 1, high);
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {7, 9, 0, 5, 3, 4, 2, 1, 6};

    cout << "Before QuickSort :" << endl;
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "After Sorting :" << endl;
    printArray(arr);

    return 0;
}

//Easy
