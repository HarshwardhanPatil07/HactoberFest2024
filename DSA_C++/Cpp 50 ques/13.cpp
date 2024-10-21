#include<iostream>
using namespace std;

class alpha{
    public:
    char ch;
    void alphabet(char ch){
        if((ch>='a' && ch <='z') || (ch>='A' && ch<='Z')){
            cout<<"alphabet valid"<<endl;
        }
        else{
            cout<<"not valid";
        }
    } 
};

int main(){
    alpha a;
    char ch;
    cout<<"enter alphabet : ";
    cin>>ch;
    a.alphabet(ch);

    return 0;
}