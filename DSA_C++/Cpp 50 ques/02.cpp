#include<iostream>
using namespace std;

class num{
    public:
    int n;

    void display(int n){
        cout<<"entered number"<<n<<endl;
    }
};

int main(){
    int n;
    cout<<"enter the number u want to display : ";
    cin>>n;
    num obj;
    obj.display(n);
    
    return 0;
}