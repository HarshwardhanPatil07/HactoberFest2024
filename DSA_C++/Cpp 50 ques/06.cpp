#include<iostream>
using namespace std;

class checker{
    public:
    int num;
    void evenodd(int num){
        if(num % 2==0){
            cout<<"even";
        }
        else{
            cout<<"odd";
        }
    }
};

int main (){
    checker no;
    int num;
    cout<<"enter the number :";
    cin>>num;
    no.evenodd(num);

    return 0;
}