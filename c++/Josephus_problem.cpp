// https://www.geeksforgeeks.org/josephus-problem/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int Josephus_problem(int n, int k)
{
    if(n==1)
        return 0;
    return (Josephus_problem(n-1,k)+k)%n;
}

// If circle position begins with 1
int myJos(int n, int k)
{
    return Josephus_problem(n, k) + 1;
}

int main()
{
    cout<<Josephus_problem(7, 3)<<endl;
    cout<<Josephus_problem(4, 2)<<endl;
    cout<<Josephus_problem(5, 3)<<endl;
    return 0;
}