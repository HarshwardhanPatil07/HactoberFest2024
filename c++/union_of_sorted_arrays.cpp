//isheta20, getting the union of two sorted arrays, 21/10/23
#include<iostream>
#include<vector>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{

    vector<int> u;
    int i=0, j=0;
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            if(u.size() == 0 || arr1[i]!=u.back()){ 
                u.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(u.size() == 0 || arr2[j]!=u.back()){
                u.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n){
        if(u.size() == 0 || arr1[i]!=u.back()){
            u.push_back(arr1[i]); 
        }
        i++;
    }
    while(j<m){
        if(u.size() == 0 || arr2[j]!=u.back()){
            u.push_back(arr2[j]); 
        }
        j++;
    }

    return u;
}
int main() {

    int arr1[] = {2,2,3,4,5};
    int arr2[] = {1,1,2,3,4};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    vector<int> ans = findUnion(arr1, arr2, size1, size2);

    cout<<"\nUnion of both arrays: \n";
    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}