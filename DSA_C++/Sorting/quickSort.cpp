#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){ 
  int pivot=arr[high];
  int i=(low-1);
  
  for(int j=low;j<=high-1;j++){

    if(arr[j]<=pivot){
     
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[i+1],arr[high]);
  return (i+1);
}


           
void quickSort(int arr[],int low,int high){
  
  if(low<high){ 
    int pi=partition(arr,low,high);
    
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}


void printArray(int arr[], int size) {                             
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
             
 
int main() {
  int arr[]={10,7,8,9,1,5};
  int n=sizeof(arr)/sizeof(arr[0]);
  
  quickSort(arr,0,n-1);
  cout<<"Sorted Array\n";
  for(int i=0;i<n;i++)
  {                                                                 
    cout<<arr[i]<<" ";
  }
  return 0;
}