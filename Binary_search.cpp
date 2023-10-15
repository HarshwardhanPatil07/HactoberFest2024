/*
implement the binary search algorithm using recursion approach
*/

#include <iostream>
using namespace std;

int binarysearch(int arr[], int key, int left, int right)
{

    if (left <= right) // first we check  condition
    {
        int mid = left + (right - left) / 2; // find the mid index of sorted array
        if (arr[mid] == key)                 // and check  if mid element equal to the key then return mid index
        {
            return mid;
        }
        else if (arr[mid] > key) // if mid element is greater then key then call recussion function and change right  position with mid-1
        {
            return binarysearch(arr, key, left, mid - 1);
        }
        else
        {
            return binarysearch(arr, key, mid + 1, right); // if mid element is less then key then call the recursion function and change update the left position with mid+1
        }
    }

    return -1;
}
int main()
{
    int n;
    cout << "enter the size of array : ";
    cin >> n;
   int* arr = new int[n];

    cout << "enter the element of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the key you want to search : ";
    int key;
    cin >> key;
    int result = binarysearch(arr, key, 0, n - 1); // call the function
    if (result == -1)
        cout << "Not Found" << endl;
    else
        cout << "Element is found at index " << result << endl;
    return 0;
}


