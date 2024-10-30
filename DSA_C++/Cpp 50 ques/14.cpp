#include<iostream>
using namespace std;

class number{
    public:
    int n;
    int sum(int n){
        return (n*(n+1))/2; 
    }
};

int main (){
    number n;
    int num;
    cout<<"enter the number : ";
    cin>>num;

    cout<<"the sum of first "<<num<<"is"<<n.sum(num);

    return 0;
}