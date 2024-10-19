#include<iostream>
using namespace std;

int main (){
    int num;
    cout<<"enter the number :";
    cin>>num;

    string result = (num % 2 == 0) ? "even" :"odd";
    cout<<"rsults is :"<<result;

    return 0;
}
