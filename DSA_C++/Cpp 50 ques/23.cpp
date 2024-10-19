#include<iostream>
using namespace std;

class switch_case{
    public:
    float a , b;
    char ch;
    void useswitch(float a,float b,char ch){
        switch (ch){
            case '+':
                cout<<a + b<<endl;
                break;
            case '-':
                cout<<a - b<<endl;
                break;
            default :
                cout<<"invalid"<<endl;
                break;
        }
    }
};

int main(){
    switch_case s;
    float a ,b;
    char c;
    cout<<"enter operants and operator : ";
    cin>>a>>b>>c;
    s.useswitch(a,b,c);

    return 0;
}