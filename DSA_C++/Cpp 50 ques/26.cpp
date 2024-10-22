#include<iostream>
using namespace std;

class primechecker{
    public:
    int num;
    bool prime(int num){
        if(num<=1) return false;
        for(int i = 2; i<=num/2; i++){
            if(num % 2 == 0) return false;
        }
        return true;
    }
    void display(int start , int end){
        for(int i = start; i<=end ; i++){
            if(prime(i)){
                cout<< i<<" ";
            }
        }
        cout<<endl;
    }
};

int main (){
    primechecker p;
    int num;
    cout<<"enter the number : ";
    cin>>num;
    cout<<"prime no. : "<<p.prime(num);
    int x , y;
    cin>>x >> y;
    p.display(x , y);

    return 0;

}