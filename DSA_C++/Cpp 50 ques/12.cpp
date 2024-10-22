#include<iostream>
using namespace std
class year{
    public:
    int year;

    bool check(int year){
        if(year % 4 ==0){
            if(year % 100 ==0){
                if(year % 400 == 0) return true;
                else return false;
            } else return true;
        } else false;
    }
};

int main(){
    year n;
    int year;
    cin>>year;

    if(n.check(year)){
        cout<<"leap year";
    }
    else{
        cout<<"not leap year";
    }

    return 0;
}

