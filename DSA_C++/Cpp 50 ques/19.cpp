#include<iostream>
using namespace std;

class reverse{
    public:
    int num;

    void rev(int num){
        int remainder = 0;
        while(num != 0){
            int digit = num / 10;
            remainder = remainder * 10 + digit;
            num /= 10;
        }
        return remainder;
    }   
};

int main (){
    reverse r;
    int n;
    cout<<"enter the number to get reversed : ";
    cin>>n;

    cout<<"reversed no" <<r.rev(n);

    return 0;
}

#include<iostream>
using namespace std;

class reverse{
    public:
    int num;

    void rev(int num){
        int digit = num / 10;
        int remainder = remainder * 10 + digit;
        num /= 10;
    }
};

int main (){
    reverse r;
    int n;
    cout<<"enter the number to get reversed : ";
    cin>>n;

    cout<<"reversed no"<<r.rev(n);

    return 0;
}