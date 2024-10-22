/*class C
{ 
... .. ... 
};
class B : public C
{
... .. ...
};
class A: public B
{
... ... ...
};*/
#include<iostream>
using namespace std;

class vehicle{
    public:
    vehicle(){
        cout<< "This is vehicle."<<endl;
    }
};

class four_wheeler : public vehicle{
    public:
    four_wheeler(){
        cout<< "This is four wheeler."<<endl;
    }
};

class car : public four_wheeler{
    public:
    car(){
        cout<< "This is car."<<endl;
    }
};

int main (){
    four_wheeler obj;
    car obj1;
}