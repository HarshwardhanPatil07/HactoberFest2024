#include <iostream>
using namespace std;
int sum(int n)
{
    int p;
    if (n == 0)
    {
        return n;
    }
    p = n % 10 + sum(n / 10);
    return p;
}
int main()
{
    int x, z;
    cout << "enter no" << endl;
    cin >> x;

    z = sum(x);
    cout << "sum is " << z << endl;
}
