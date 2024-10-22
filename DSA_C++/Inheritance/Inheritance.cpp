#include<iostream>
using namespace std;

class human{
    

    private:
    int height;
    int age;
    string weight;



    public:
    void setdata(int height){
        this -> height = height;
    }

    void getdata(){
        cout << "Height: " << height << endl;
    }


    void setage(int age){
        this -> age = age;
    }

    void getage(){
        cout << "Age: " << age << endl;
    }

    void setweight(string weight){
        this -> weight  = weight;
    }

    void getweight(){
        cout <<" weight : " << weight << endl;
    }

};

class male : public human {

    private:
    string name;

    public:
    void setname(string name){
        this -> name = name;
    }

    void getname(){
        cout << "name: " << name << endl;
    }
    //cout << " enter your name : "<<endl;
    //cin>>name;
};

int main (){
    male m;
    m.setdata(5);
    
    m.getdata();

    m.setage(28);
    cout<< " age :";
    m.getage();

    m.setweight("44kg");
    cout<<" your weight :";
    m.getweight();

    m.setname("red");
    cout<<" color is : ";
    m.getname();

    return 0;
}





// #include <iostream>
// using namespace std;

// class Human {
// public:
//     // Public setters and getters
//     void setData(int height) {
//         this->height = height;
//     }

//     void getData() {
//         cout << "Height: " << height << endl;
//     }

//     void setAge(int age) {
//         this->age = age;
//     }

//     void getAge() {
//         cout << "Age: " << age << endl;
//     }

//     void setDob(int dob) {
//         this->dob = dob;
//     }

//     void getDob() {
//         cout << "DOB: " << dob << endl;
//     }

// private:
//     int height;
//     int age;
//     int dob;
// };

// class Male : public Human {
// public:
//     void setName(string name) {
//         this->name = name;
//     }

//     void getName() {
//         cout << "Name: " << name << endl;
//     }

// private:
//     string name;
// };

// int main() {
//     Male m;
//     m.setData(5);
//     cout << "Your height: ";
//     m.getData();

//     m.setAge(28);
//     cout << "Your age: ";
//     m.getAge();

//     m.setDob(19951124); // assuming dob is in YYYYMMDD format
//     cout << "Your DOB: ";
//     m.getDob();

//     m.setName("Red");
//     cout << "Your name: ";
//     m.getName();

//     return 0;
// }
