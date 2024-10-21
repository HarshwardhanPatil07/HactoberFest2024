#include<iostream>
using namespace std;

class fibbo{
    public:
    int n;
    void series(int n){
        int t1 = 0, t2 = 1 , nextterm;
        cout <<t1<<" "<<t2<<" ";
        for(int i = 2; i<=n; i++){
            nextterm = t1 + t2;
            t1 = t2;
            t2 = nextterm;
        }
        cout<<endl;
    }
};

int main (){
    fibbo num;
    int n;
    cout<<"enter the range : ";
    cin>>n;
    num.series(n);


    return 0;

}