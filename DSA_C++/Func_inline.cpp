#include <iostream>
using namespace std;

// class Math {
// public:
// // Inline function to add two numbers
//     inline int add(int a, int b) {
//         return a + b;
//     }
// };
// int main() {
//     Math math;
//     int result = math.add(3, 5);                   // This call to add() 
//     cout << "The sum is: " <<result<<endl;         // will be expanded inline, if possible
//     return 0;
// }




/*
*
*
*
*
*
*
*/


inline int add(int a , int b){
    return a+b;
}
int main (){
    int a,b;
    cout<<"Enter two numbers: "<<endl;
    cin>>a>>b;
    cout<<"Addition value : "<<add(a,b);

}