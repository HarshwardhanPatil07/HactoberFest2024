#include<iostream>
using namespace std;

class num{
    public:
    float n , m;

    void multiply(float n , float m){
        cout<<"multiplyyy "<<n*m<<endl;
     
    }
   
};

int main(){
    float n , m;
    cout<<"enter the number u want to display : ";
    cin>>n>>m;
    num obj;
    obj.multiply(n,m);
    
    return 0;
}