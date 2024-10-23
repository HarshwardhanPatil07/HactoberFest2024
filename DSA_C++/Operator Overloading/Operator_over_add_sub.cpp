#include<iostream>
using namespace std;
/*
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
}   */


#include<iostream>
using namespace std;

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

    marks operator-(marks m){
        marks temp;
        temp.intmarks = intmarks - m.intmarks;
        temp.extmarks = extmarks - m.extmarks;
        return temp;
    }
};


int main(){
    marks m1(90, 80);
    m1.display();
    marks m2(100 , 120);
    m2.display();
    marks m3 ;

    m3 = m1-m2;

    m3.display();

    return  0;
}  