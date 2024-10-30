#include<iostream>
using namespace std;

class palindrome{
    public:
    int num;
    //bool check(int num){
        int original = num;
        int digit , remainder = 0;
        while(num != 0){
            digit = num %10;
            remainder = remainder * 10 + digit;
            num /= 10;
        }
        return original == remainder;
    }
};

int main() {
    palindrome c;
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    if (c.check(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }
    return 0;
}