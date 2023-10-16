#include <bits/stdc++.h>
using namespace std;

int jumpSearch(int arr[],int x,int n){
    int block = sqrt(n);
    int prev = 0;
    while(arr[min(block,n)-1]<x){
        prev = block;
        block = block+sqrt(n);
        if(prev>= n){
            return -1;
        }
    }
    while(arr[prev]<x){
        prev++;

        if(prev==min(block,n)){
            return -1;
        }
    }
    if(arr[prev]==x){
        return prev;
    }
    return -1;
}

//driver code
int main(){
    int arr[8]={2,4,6,7,8,9,10,12};
    int x=8;
    int n = sizeof(arr) / sizeof(arr[0]);

    int ans = jumpSearch(arr,x,n);

    cout<<x<<" is at index "<<ans<<endl;

    return 0;
}

//Time Complexity : O(√n) 
//Space Complexity: O(1)