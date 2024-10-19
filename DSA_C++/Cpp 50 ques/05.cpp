#include<iostream>
using namespace std;

class solve{
    public:
    void display(int a , int b){
        if(b == 0){
            throw runtime_error("invalid input");
        }
        int x = a / b;
        int y = a % b;
        cout<<"x : "<<x<<endl;
        cout<<"y : "<<y<<endl;

    }
};

int main (){
    int divisor , dividend;
    cout<<"enter the value :";
    solve m;
    
    try{
        cin>>divisor>>dividend;
        if(cin.fail()){
            throw runtime_error("error");
        }
    }
    return 0;

}