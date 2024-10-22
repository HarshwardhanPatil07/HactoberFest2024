/*Develop a program which will read a string and rewrite it in the alphabetical order.*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string user_input;
    cout<<"Enter a string to sort : "<<endl;
    getline(cin,user_input);
    sort(user_input.begin(),user_input.end());
    cout<<"The sorted string is : "<<user_input<<endl;

    return 0;
}
