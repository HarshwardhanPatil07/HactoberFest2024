#include<iostream>
using namespace std;

void TowerOfHanoi(int n, char a, char b, char c)
{
    if(n==0)
    {
        return;
    }
    TowerOfHanoi(n-1,a,c,b);
    cout<<"Move disc "<<n<<" from "<<a<<" to "<<c<<endl;
    TowerOfHanoi(n-1,b,a,c);
}

int main()
{
    TowerOfHanoi(3, 'A', 'B', 'C');
    return 0;
}