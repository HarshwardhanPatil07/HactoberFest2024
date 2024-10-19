// #include<iostream>
// using namespace std;

// class base{
//     public:
//     void member_func(){
//         cout<<"base class"<<endl;
//     }
// };

// class derived_class : public base {
//     private:
//     int age;

//     public:
//     void setdata(int a){
//         age = a;
//     }

//     void getdata(){
//         cout<<"age is "<<age<<endl;
//     }
   
//     void member_func(){
//         cout<<"derived class"<<endl;
//     }    
// };

// int main(){
//     derived_class b;
//     b.setdata(12);
//     b.getdata();
//     b.member_func();

//     b.base::member_func();   // to cll the member funciton of the base class also
//     return 0;
// }





#include<iostream>
using namespace std;

class animal{
    public:
    void sound(){
        cout<<"animal sound"<<endl;
        }
};

class dog : public animal{
    // public:
    // void sound(){
    //     cout<<"Barking"<<endl;
    //     }
};

class cat : public animal{
    public:
    void sound(){
        cout<<"meowing"<<endl;
        }
};


int main (){
    // animal a;
    // a.sound();

    // dog d;
    // d.sound();

    cat c;
    c.sound();

    return 0;
}
