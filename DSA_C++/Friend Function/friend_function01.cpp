#include<iostream>
using namespace std;
// // class Distance{
// //     private:
// //     double meters;

// //     public:
// //     Distance(){
// //         meters = 0;
// //     }


// //     void set_data(double x){
// //         meters = x;
// //     }

// //     void display(){
// //         cout<<"The current value is :"<<meters<<endl;
// //     }

// //     friend void add(Distance &b);
// // };

// // void add(Distance &b){
// //     cout<<"enter the vlaue:"<<endl;
// //     double a;
// //     cin>>a;
// //     b.meters = b.meters + a;
// //     cout<<"final value :"<<b.meters<<endl;
// // }
 
// // int main(){
// //     Distance box;
// //     box.set_data(12);
// //     box.display();

// //     add(box);
  
// //     return 0;
// // }



// #include <iostream>
// using namespace std;

// class box {
// public:
//     int x;

//     box() {
//         cout << "Enter the name of the box" << endl;  // Fixed output statement
//     }

//     void set_data(int a) {
//         x = a;
//     }

//     void print() {
//         cout << "This is value: " << x << endl;  // Printing the value of x
//     }

//     // Friend function declaration
//     friend void display(box &b);  
// };

// // Friend function definition
// void display(box &b) {
//     cout << "This is display: " << b.x << endl;  // Accessing private data of box
// }

// int main() {
//     box b;
//     b.set_data(2);
//     b.print();
//     display(b);  // Correct way to call a friend function

//     return 0;
//}
