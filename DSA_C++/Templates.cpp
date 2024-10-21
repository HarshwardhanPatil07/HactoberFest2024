#include<iostream>
using namespace std;

template<typename T , typename U>

class dase{
    private:
    T data;
    U value;

    public:
    
    void set(T d , U v){
        data = d;
        value = v;
    }

    void get(){
        cout<<"value "<<data<<endl;
        cout<<"value "<<value<<endl;
    }

};

int main(){
    dase<int , double> d1;
    d1.set(12 , 0.545);
    d1.get();

    return 0;
}



template<typename t>
t add(t a, t b){
    return a + b;
}

int main(){
    cout<<add<int>(5, 7)<<endl;
    cout<<add<double>(5.5, 7.7)<<endl;
    return 0;
}


// template<typename t> /*, typename u*/
// t add(t a , t b){
//     return a + b;
// }

// int main(){
//     cout<<add<float >(5, 8.5)<<endl;
//     //cout<<add(5, 7)<<endl;
//     return 0;
// }

// template <typename t , typename u>

// t add(t x , u y){
//     return x + y;
// }

// int main (){
//     cout<<add<int>(21, 10.5);

//     return 0;
// }