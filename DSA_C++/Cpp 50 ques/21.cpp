#include<iostream>
using namespace std;

class primeno{
    public:
    int num;
    bool isprime(int num){
        for(int i = 2; i<= num/2; i++){
            if(num % i == 0)
            return false;
        }
        return true;
    }
};

int main() {
    PrimeChecker checker;
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (checker.isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }
    return 0;
}