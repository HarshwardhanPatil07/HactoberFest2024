#include<iostream>
using namespace std;


// class distance{

//     private:
//     int meters;

//     public:
//     distance(int m){
//         meters = m;
//     }
//     void print(){
//         cout << meters << endl;
//     }
// };

// int main(){
//     distance d1(10);
//     d1.print();
// }


///////////////////////////////////////
// class distance{
//     private:
//     int meters;

//     public:
//     distance(){
//         meters = 0;
//     }

//     void display(){
//         cout << "metr value is :"<< meters << endl;
//     }

//     friend void add(distance &d);
// };

// void add(distance &d){
//     d.meters = dm.meters + 10;
// }

// int main(){

//     distance d1;
//     d1.display();

//     add(d1);
//     d1.display();

//     return 0;

// }
////////////////////////////////////////


// class distance {
//     private:
//     int meters;

//     public:
//     distance() {
//         meters = 0;
//     }

//     void display() {
//         cout << "Meter value is: " << meters << endl;
//     }

//     friend void add(distance &d);
// };

// void add(distance &d) {
//     d.meters += 10; // Corrected to directly modify the meters attribute of d
// }

// int main() {
//     distance d;
//     d.display(); // Displays initial value of meters (0)

//     add(d);
//     d.display(); // Displays updated value of meters (10)

//     return 0;
// }



/*class distance{
    private:
    int meters;

    public:
    distance(){
        meters = 0;
    }


    void display(){
        cout<<"enter the new value :"<<endl;                             **********E
    }                                                                              RR
    friend void add(distance b);                                                   OR***********
};


void add(distance b){
    cout<<"after new value that added :"<<b.meters<<endl;
}


int main (){
    distance d1;
    d1.display();

    add(1200);
    d1.display();

    return 0;
}*/


#include <iostream>
using namespace std;

// Forward declaration of the Derived class
class Derived;

class Base {
private:
    int baseVar;

protected:
    int protVar;

public:
    Base(int a, int b) : baseVar(a), protVar(b) {}

    // Friend function declaration
    friend void display(Base, Derived);
};

class Derived : public Base {
private:
    int derivedVar;

public:
    Derived(int a, int b, int c) : Base(a, b), derivedVar(c) {}

    // Friend function declaration (already declared in Base)
    friend void display(Base, Derived);
};

// Friend function definition
void display(Base b, Derived d) {
    cout << "Base privateVar: " << b.baseVar << endl;
    cout << "Base protectedVar: " << b.protVar << endl;
    cout << "Derived derivedVar: " << d.derivedVar << endl;
}

int main() {
    Base b(1, 2);
    Derived d(3, 4, 5);
    display(b, d);
    return 0;
}
