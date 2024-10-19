#include<iostream>
#include<cmath>
using namespace std;

class armstrong{
    public:
    int num;
    bool arm(int num){
        int original, count = 0;
        while(num != 0){
            num /= 10;
            count++;
        }
        original == num;
        int digit , result = 0;
        while(num != 0){
            digit = num % 10;
            result += pow(digit, count);
            num /= 10;
            
        }
        return original == result;
    }
};

int main (){
    armstrong a;
    int n;
    cout<<"enter the number : ";
    cin>>n;

    if(a.arm(n)){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}