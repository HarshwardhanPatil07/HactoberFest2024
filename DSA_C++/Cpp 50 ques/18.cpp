#include<iostream>
using namespace std;

class count{
    public:
    
    int countdigit(int n){
        int countno = 0;
        while(n != 0){
            n /= 10;
            countno ++;
            
        }
        return countno;
    }
};

int main (){
    count n;
    int num;
    cout<<"enter the number : ";
    cin>>num;

    cout<<"total digit in number : "<<n.countdigit(num);

    return 0;
}