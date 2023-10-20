//github username: ctln23
//aim: a palindrome triangle pattern
//date: 21/10/2023
#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int i = 1;
    while (i <= n){
        int j = 1;
        while (j <= n - i + 1){
            cout << j << " ";
            j++;
        }
        int star = 1;
        while (star < i){
            cout << '*' << " ";
            star++;
        }
        int star2 = 1;
        while (star2 < i){
            cout << '*' << " ";
            star2++;
        }
        int rev = n - i + 1;
        while (rev >= 1){
            cout << rev << " ";
            rev--;
        }
        cout << endl;
        i++;
    }
    return 0;
}
