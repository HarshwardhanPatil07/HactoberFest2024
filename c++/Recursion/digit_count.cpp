#include <iostream>
using namespace std;
int digit(int n)
{
    int p, i = 1;
    if (n == 0)
        return n;
    p = i + digit(n / 10);
    return p;
}
int main()
{
    int x, z;
    cout << "enter your value \n";
    cin >> x;
    z = digit(x);
    cout << "your digit cout is " << z;
}