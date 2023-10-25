// Rope cutting problem

/*
    We have a rope of length n, our task is to cut this rope into 
    maximum number of pieces such that every piece has length equal 
    a or b or c.

    example 1:
    input: n=5, a=2, b=5, c=1
    output: 5

    example 2:
    input: n=23, a=12, b=9, c=11
    output: 2

    example 3:
    input: n=5, a=4, b=2, c=6
    output: -1
*/

#include<iostream>
using namespace std;

int cutTheRope(int n, int a, int b, int c)
{
    if(n==0)
        return 0;
    if(n<0)
        return -1;

    int len_a = cutTheRope(n-a, a, b, c);
    int len_b = cutTheRope(n-b, a, b, c);
    int len_c = cutTheRope(n-c, a, b, c);
    int res = max(len_a, len_b);
    res = max(res, len_c);

    if(res==-1)
        return -1;
    else
        return res+1;
}

int main()
{
    cout<<cutTheRope(5, 2, 5, 1)<<endl;
    cout<<cutTheRope(23, 12, 9, 11)<<endl;
    cout<<cutTheRope(5, 4, 2, 6)<<endl;
    cout<<cutTheRope(9, 2, 2, 2)<<endl;
    return 0;
}