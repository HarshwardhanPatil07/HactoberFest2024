#include<iostream>
using namespace std;

/*class class_one{
    private:
    int abc , def ;

    public:
    class_one(int x , int y){
        this -> abc = x;
        this -> def = y;
        
    }

    void print (){
        cout << abc << " " << def << endl;
    }
};

int main (){
    class_one obj(12,22);
    //obj.
    obj.print();

    return 0;
}*/


/*

class complex{
    private:
    float real , img;

    public:

    complex(){
        real = 0;
        img = 0;
        
    }
    complex(float x , float y){
        real = x;
        img = y;
    }


    void display(){
        cout<<" the result of above defind values are : "<<real<<" + "<<img<<"i"<<endl;
    }

    complex operator +(complex c){
        complex temp;
        temp.real =  real + c.real;
        temp.img  = img + c.img;

        return temp;

    }
}; */

/*
int main (){
    complex c1(12.5 , 30.5);
    complex c2(24.5 , 60.5);
    complex c3;
    c3  = c1 + c2;

    c3.display();

    return 0 ;
}   */





class marks{
    int intmarks;
    int extmarks;
    
    public:
    marks(){
        intmarks = 0 ;
        extmarks = 0 ;
    }
    marks(int in , int ex){
        intmarks = in ;
        extmarks = ex ;
    }


    void display(){
        cout<<"internam marks : "<<intmarks<<endl<<"external marks :"<<extmarks<<endl;
    }

    marks operator+(marks m){
        marks temp;
        temp.intmarks = intmarks + m.intmarks;
        temp.extmarks = extmarks + m.extmarks;
        return temp;
    }
};


int main(){
    marks m1(90, 80);
    m1.display();
    marks m2(100 , 120);
    m2.display();
    marks m3 ;

    m3 = m1+m2;

    m3.display();

    return  0;
}