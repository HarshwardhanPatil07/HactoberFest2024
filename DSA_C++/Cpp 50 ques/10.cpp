#include<iostream>
using namespace std;


class vowel{
    public:
    char ch;

    void check(char ch){
        if(ch == 'a'|| ch=='e'||ch=='i'||ch=='o'||ch == 'u'){
            cout<<"the letter is vowel";
            }
        else if(ch >= 'a' && ch<= 'z'){
            cout<<"consonant";
            }
        else{
            cout<<"invalid letter";   
           }
    }
};

int main (){
    vowel v;
    char c;
    cout<<"enter teh charcter : ";
    cin>>c;
    v.check(c);


    return 0;
}