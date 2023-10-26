#include<iostream>
using namespace std;
int fact(int n)
{
int p;
if(n<=1)
{
 return 1;
}
p=n*fact((n-1));
return p;
}
int main()
{
int x,z;
cout<<"enter no"<<endl;
cin>>x;
z=fact(x);
cout<<"factorial "<<z;
}
