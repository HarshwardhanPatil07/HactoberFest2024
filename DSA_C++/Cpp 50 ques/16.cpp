#include<iostream>
using namespace std;

class multi{
    public:
    int n;
    void table(int n){
        for(int i = 1; i <=10; i++){
            cout<<n <<" * "<<i<<" = "<<n * i<<endl;
        }
    }
};

int main (){
    multi m;
    int n;
    cout<<"enter number : ";
    cin>>n;

    m.table(n);

    return 0;


}