#include<iostream>
using namespace std;

// int main (){
//     int num,deno;
//     cout<<"enter the two values : ";
//     cin>>num>>deno;

//     int result = num/deno;
//     cout<<"the result is : "<<result;
    
// }

// int main (){
//     int num,deno,result=0;
//     cout<<"enter the two values : ";
//     cin>>num>>deno;

//     try {
//         if (deno==0){
//             throw deno;
//         }
//         result = num/deno;
//     }
//     catch (int ex){     
//         cout<<"denominator can't be zero : "<<ex<<endl;
//     }

//     cout<<"division is : "<<result;
//     return 0;

// }



#include <iostream>
using namespace std;

int main() {
    int i = 25;
    int j = 0;  // This will cause a divide by zero error
    float k = 0;

    try {
        if (j == 0) {
            throw (float)j;  // Throwing float exception for divide by zero
        }
        k = i / j;
        cout << k << endl;
    }
    catch (float e) {
        cout << "Attempted to divide by zero!" << endl;
    }
    catch (const char* e) {
        cout << e << endl;
    }
    catch (int e) {
        cout << "Integer type exception" << endl;
    }
    catch (...) {
        cout << "Default exception" << endl;
    }

    return 0;
}
