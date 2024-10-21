#include<iostream>
using namespace std;

class exc{};

int main(){

    int a , b;
    cout<<"enter the two number :";
    try{
        cin>>a>>b;
        if(cin.fail()){
            throw runtime_error("invalid input");
        }
        int sum = a + b;
        cout<<"sum of two number is "<<sum<<endl;
    }
    catch (runtime_error &exp){
        cout<<"invalid input";
    } 
}