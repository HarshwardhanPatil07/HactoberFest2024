#include<iostream>
using namespace std;

class fact{
    public:
    int n;
    int factorial(int n){
        int result = 1;
        for(int i = 2; i<=n; i++){
            result = result * i;
        }
        return result;
    }
};

int main(){
    fact m;
    int n;
    cout<<"enter the number :";
    cin>>n;
    cout<<"factorial"<<n <<"is : "<<m.factorial(n);

    return 0;

}