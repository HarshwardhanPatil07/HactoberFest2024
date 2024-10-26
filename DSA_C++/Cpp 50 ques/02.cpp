#include<iostream>
using namespace std;

class num{
    public:
    int n;

    void display(int n){
        cout<<"entered number : "<<n<<endl;//this is a function within which we just print out the number that han been entered by the user 
    }
};

int main(){
    int n;
    int m=1;
    while(m==1){
    cout<<"enter the number you want to display : ";
    cin>>n;
    num obj;
    obj.display(n);
    cout<<"if you want to exit entering the numbers enter 0 or if you like to continue enter 1 " <<endl;
    cin>>m;
    }
    
    return 0;
}
