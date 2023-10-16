//similar to binary search

#include <iostream>
using namespace std;

int ternary_search(int l, int r, int key, int ar[]){
    if(r>=l){
        int mid1 = l+(r-l)/3;
        int mid2 = r-(r-l)/3;

        if(ar[mid1]==key){
            return mid1;
        }
        if(ar[mid2]==key){
            return mid2;
        }
        if(key<ar[mid1]){
            return ternary_search(l, mid1 - 1, key,ar);
        }
        else if (key > ar[mid2]) {
            return ternary_search(mid2 + 1, r, key,ar);
        }
        else {
            return ternary_search(mid1 + 1, mid2 - 1, key,ar);
        }

    }
    return -1;
}

int main(){
    int l,r,p,key;

    int ar[]={2,4,6,8,9,12,14,15};
    //starting index
    l=0;
    //ending index
    r=7;
    key=15;

    p= ternary_search(l, r, key,ar);

    cout<<"Index of "<<key<<" is "<<p<<endl;
}

//Time Complexity- O(logN base 3)
//best Case- O(1)
//Space complexity- O(1)