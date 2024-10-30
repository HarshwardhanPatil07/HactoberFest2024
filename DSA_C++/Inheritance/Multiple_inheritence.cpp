#include<iostream>
using namespace std;

class solar_system{

    private:
    int num_planets;

    public:
    void set_planet(int n){
        num_planets = n;
    }

    void get_planet(){
        cout << "Number of planets: " << num_planets << endl;
    }
};

class planets{
    public :
    void pl(){
        cout<<"This is the planet session."<<endl;
    }
};

class plan : public solar_system , public planets{
    private :
    string name;
    public:
    void set_data(string n){
        name = n;
    }

    void get_data(){
        cout<< "Name of the planet is : "<<name<<endl;
    }
};

int main(){
    plan p;
    p.set_planet(9);
    p.get_planet();

    p.set_data("Earth");
    p.get_data();

    p.pl();

    return 0;
}