// github-username : "charmee123"
// aim : "C++ programs for searching algorithms so that it will help to find all the searching algorithms at one place"
// date : "16/10/2023"

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int start=0;
    int end = size-1;

    int mid= start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int main(){
    int arr[5]={2,5,7,9,11};
    int index=binarySearch(arr,5,7);

    cout<<"Index of 7 is "<<index<<endl;
}


//Time complexity- O(logN)
//Space complexity- O(1)