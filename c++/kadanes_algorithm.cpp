#include <iostream>
using namespace std;

// Kadane's algorithm for Largest Sub-Array Sum

int max_subarray_sum(int arr[], int n)
{
    int max_sum = INT32_MIN;

    int currentElementMax = 0;
    for (int i = 0; i < n; i++)
    {
        currentElementMax = max(arr[i], currentElementMax + arr[i]);
        max_sum = max(max_sum, currentElementMax);
    }

    return max_sum;
}

int main()
{
    int n;
    cout << "Enter Number of Elements in Array: ";

    cin >> n;
    int arr[n];

    cout << "Enter the Elements of the Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Maximum Subarray sum is: " << max_subarray_sum(arr, n) << endl;

    return 0;
}
