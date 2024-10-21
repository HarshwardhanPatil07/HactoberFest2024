#include<iostream>
using namespace std;

class number{
    public:
    int a , b ,c;

    void largest(int a , int b ,int c){
        if(a>b && a>c){
            cout<<"a is largest";
        }
        else if(b>a &&b>c){
            cout<<"b is largest";
        }
        else{
            cout<<"c is largest";
        }
    }
};

int main(){
    number n;
    int a , b, c;
    cout<<"enter three number";
    cin>>a>>b>>c;
    n.largest(a , b, c);

    return 0;
}