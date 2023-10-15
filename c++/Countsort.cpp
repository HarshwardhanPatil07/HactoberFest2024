//manish-bhukar==username 
//aim =sorting of array using count sort
//Date=15/10/2023
#include <bits/stdc++.h>
using namespace std;
 
vector<int> countSort(vector<int>& inputArray)
{
 
    int N = inputArray.size();
 
    // Finding the maximum element of array inputArray[].
    int M = 0;
 
    for (int i = 0; i < N; i++)
        M = max(M, inputArray[i]);
 
    // Initializing countArray[] with 0
    vector<int> countArray(M + 1, 0);
 
 //calculation frequency of each element
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;
 
    //sum of all frequency previous to one 
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
 
    // Creating outputArray[] from countArray[] array
    vector<int> outputArray(N);
 
    for (int i = N - 1; i >= 0; i--)
    {
        outputArray[countArray[inputArray[i]] - 1]
            = inputArray[i];
        countArray[inputArray[i]]--;//after puting element in output array decrease their frequency
    }
    return outputArray;
}
 
// Driver code
int main()
{//array which we are going to sort
    vector<int> inputArray = { 4, 3, 12, 1, 5, 5, 3, 9 };
    vector<int> outputArray = countSort(inputArray);
 
    for (int i = 0; i < inputArray.size(); i++)
        cout << outputArray[i] << " ";
 
    return 0;
}