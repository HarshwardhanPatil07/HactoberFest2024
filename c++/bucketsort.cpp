#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bucketSort(float arr[], int n){

    vector<vector <float>> bucket(n, vector<float> ());//2D vector

    float max_ele = arr[0];
    float min_ele = arr[0];

    //Finding range of the elements in array
    for(int i=1; i<n; i++) {
        max_ele = max(max_ele, arr[i]);
        min_ele = min(min_ele,arr[i]);
    }
    float range = (max_ele-min_ele)/n;

    //Inserting elements into bucket
    for(int i=0; i<n; i++) {
        int index = (arr[i]-min_ele)/range;
        //boundary elements
        float diff = (arr[i]-min_ele)/range - index; 

        //max element will give the size of the array on calculation but since arr stores only till n-1 so we have to place it ourself
        if(diff==0 && arr[i] != min_ele) {  
            bucket[index-1].push_back(arr[i]);
        }
        else{
            bucket[index].push_back(arr[i]);
        }
    }

    //sorting individual buckets using any stable sort
    for(int i=0; i<n; i++){
        sort(bucket[i].begin(), bucket[i].end()); //eg - from [0][0] to [0][4]
    } 

    //Combining elements from buckets
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<bucket[i].size(); j++){
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {

    float arr[] = {2.4, 5.6, 7.8, 4.2, 3.9, 8.4, 9.1, 10.3, 4.7, 7.4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Array before sorting: \n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    bucketSort(arr, n);

    cout<<"\n\nArray after sorting: \n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}