#include<iostream>
using namespace std;

int main (){
    int n;
    cout<<"enter the number :";
    cin>>n;
    char op;
    cout<<"enter the operator (+,-,*,/) :";
    cin>>op;
    int m;
    cout<<"enter the second number :";
    cin>>m;

    switch(op){
        case '+' :
            cout<<"result :"<<n+m<<endl;
        case '-' :
            cout<<"result :"<<n-m<<endl;
        case '*' :
            cout<<"result :"<<n*m<<endl;
        case '/' :
            cout<<"result :"<<n/m<<endl;
        default:
            cout<<"invalid operator";
    }
}