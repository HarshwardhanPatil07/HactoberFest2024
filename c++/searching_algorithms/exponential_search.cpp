// github-username : "charmee123"
//  aim : "C++ programs for searching algorithms so that it will help to find all the searching algorithms at one place"
//  date : "16/10/2023"


//find range where elements is present
//do binary search

#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int,int,int);
int exponential_search(int arr[], int size, int key){
    if(arr[0]==key){
        return 0;
    }
    int i=1;
    while(i<size&& arr[i]<=key){
        i=i*2;
    }
    return binarySearch(arr, i/2, min(i, size-1), key); 
                           
}

int binarySearch(int arr[], int s, int e, int key){
    if (e >= s){
        int mid = s + (e - s)/2;
 
        if (arr[mid] == key)
            return mid;
 
        if (arr[mid] > key)
            return binarySearch(arr, s, mid-1, key);
 
        return binarySearch(arr, mid+1, e, key);
    }
    return -1;
}

//driver code
int main(void){
    int arr[5]={10,20,30,40,50};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int key = 20;
    int ans=exponential_search(arr,n,key);
    if(ans==-1){
        cout<<"Element is not present in the array";
    }
    else{
        cout<<"Element is present at index "<<ans;
    }
    return 0;
}

//Time complexity-O(logn)
//Space complexity - O(1)