#include <iostream>
using namespace std;

//function for searching
int search(int arr[], int size, int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

//driver code
int main(void){
    int arr[]={1,35,67,89,123,456};
    int key=456;
    int N=sizeof(arr)/sizeof(arr[0]);

    int ans=search(arr,N,key);
    if(ans==-1){
        cout<<"Elements is not present in the array."<<endl;
    }
    else{
        cout<<"Elemet is present at index "<<ans;
    }
}



//Time Complexity
//Best case- O(1)
//Worst case- O(N)

//Space complexity - O(1)