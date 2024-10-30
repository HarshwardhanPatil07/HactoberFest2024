#include<iostream>
using namespace std;

class checker{
    public:
    int num;
    void evenodd(int num){
        string x = (num % 2==0) ? "even" : "odd";
        cout<<"number iz: "<<x;
    }
};

int main(){
    checker n;
    int num;
    cout<<"enter th num";
    cin>>num;
    n.evenodd(num);

    return 0;
}