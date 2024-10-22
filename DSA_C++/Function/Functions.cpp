#include<iostream>
using namespace std;


int max(int a, int b);

int main (){
    int a,b;
    cout<<"Enter the value :";
    cin>>a>>b;
    int c = max(a,b);
    cout<<"The greatest value is : "<<c<<endl;
    cout<<"The greatest value of : "<<max(10,12);
    return 0;

}

int max(int a, int b){
    if(a>b)
    return a;
    else
    return b;
}