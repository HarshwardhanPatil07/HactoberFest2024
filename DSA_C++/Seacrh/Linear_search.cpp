#include<iostream>
using namespace std;


int linearsearch(int arr[] , int size , int key){
    for(int i=0; i<size; i++){
        if(arr[i]==key){
            return i;
        }
        else{
            return -1;
        }
    }
    
}

int main (){

    int size;
    cout<<"Enter the size of array : ";
    cin>>size;

    int arr[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the element you need to find : ";
    cin>>key;

    int result = linearsearch(arr,size,key);

    if(result == -1){
        cout << "Element is not present in array";
        }
    else{
        cout << "Element is present at index " << result;
    }
    return 0;
}