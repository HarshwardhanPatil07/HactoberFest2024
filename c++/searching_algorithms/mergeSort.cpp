// usename:pritee
// aim:Implementation of mergeSort.
// date:21/10/2023
# include<iostream>
using namespace std;
void mergeSort(int a[],int n,int b[],int m,int c[],int x){
int first=0,second=0,index=0;
//sorting first array
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[j]<a[i]){
            int temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}
//sorting second array
for(int i=0;i<m;i++){
    for(int j=i+1;j<m;j++){
        if(b[j]<b[i]){
            int temp;
            temp=b[i];
            b[i]=b[j];
            b[j]=temp;
        }
    }
}
while(first<n && second<m){
    if(a[first]<b[second]){
        c[index]=a[first];
        first++;
        index++;
    }
    else{
        c[index]=b[second];
        second++;
        index++;
    }
}
if(first==n){
    while(second<m){
        c[index]=b[second];
        index++;
        second++;
    }
}
if(second==m){
    while(first<n){
        c[index]=a[first];
        index++;
        first++;
    }
}
cout<<"array after merge sort is :\n";
for(int i=0;i<x;i++){
    cout<<c[i]<<" ";
}

}
int main(){
    int n,m,x;
    cout<<"enter the number of element in first array\n";
    cin>>n;
    cout<<"enter the number of element in second array\n";
    cin>>m;
      x=m+n;
    int a[n],b[m],c[x];
    cout<<"enter the element of first array one by one\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
     cout<<"enter the element of second array one by one\n";
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    // cout<<"array element before \n";
    // for(int i=0;i<n;i++){
    //     cout<<b[i]<<" ";
    // }
    cout<<"array element after mergeSort is: \n";
    mergeSort(a,n,b,m,c,x);
}