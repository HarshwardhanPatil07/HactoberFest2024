#include<iostream>
using namespace std;

class base {
    public:
    int x = 2;
    /*virtual*/ void display (){
        cout<<"Displaying the value of x variable:"<<x<<endl;
    }
};

class derived_class : public base{
    public:
    int a = 5;
    void display (){
        cout<<"displaying the value of another variable :"<<a<<endl;
    }
};

int main(){
    base *base_class_pointer;
    base object;
    derived_class object1; 

    base_class_pointer = &object1;  // base_case = new object1();
    base_class_pointer->display();

    return 0;
}


/*here we have assigned the value  of object of derived classto the pointer variable i.e base class pointer of base class
and we are assiging the address value of object1 i.e of derived class object..... and we are displaying the final assigned base clas pointer which 
storing the address of derived class obj therefroe it should diplay the result of derived class function value 
but we are getting the base func value.*/



/*but if wr use the virtual function in base function thenw e will get the correct result*/