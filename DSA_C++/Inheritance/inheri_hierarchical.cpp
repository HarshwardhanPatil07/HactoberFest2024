#include<iostream>
using namespace std;

class human {
    private:
    string name;
    int age;

    public:

    human(){
        cout<<"this is huma constructor"<<endl;
    }
    // void set_name(string n){
    //     name = n;
    // }
    // string get_name(){
    //     return name;
    // }
};


class male : public human{
    public :
    male(){
        cout << "male constructor called" << endl;
    }
};

class female : public human {
    public:
    female(){
        cout<< " female constructor called";
    }
};

int main (){
    male m;
    female f;
    
    return 0;
}