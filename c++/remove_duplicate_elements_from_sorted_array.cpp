////isheta20, 21/10/23
/*Problem: 
Given a sorted array A[] of size N, delete all the duplicated elements from A[]. Modify the array such that if there are X distinct elements in it then the first X positions of the array should be filled with them in increasing order and return the number of distinct elements in the array.*/
#include<iostream>
using namespace std;
int remove_duplicate(int a[],int n){
    int i=0;
    for(int j=1; j<n; j++){
        if(a[i] != a[j]){
            i++;
            a[i] = a[j];
        }
    }

    return i+1;//no. of distinct elements
}

int main() {

    int arr[] = {2,2,2,2,3,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int distinct_ele = remove_duplicate(arr, size);
    cout<<"Number of distinct elements: "<<distinct_ele<<endl;

    cout<<"\nArray after removing duplicates: \n";
    for(int i=0; i<distinct_ele; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}