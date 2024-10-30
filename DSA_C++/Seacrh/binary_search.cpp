#include<iostream>
using namespace std;




int binarysearch(int arr[], int size, int key){
    int s = 0;         //startingpoint
    int e = size-1;         //ending point
    while(s<size){
        int mid = (s+(e-1))/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid] > key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    //if not work then we ll return -1
    return -1;
}








int main (){

    int size;
    cout<<"enter the size of the array : ";
    cin>>size;
    int key;
    cout<<"enter the key : ";
    cin>>key;

    int arr[size];
    cout<<"Enter the elements of array : "<<endl;
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }
    int result = binarysearch(arr,size,key);
    if(result == -1){
        cout<<"Element is not present in the array"<<endl;
        }
    else{
        cout<<"Element is present at index "<<result<<endl;
    }

    return 0;
}