#include <iostream>
#include <string>
using namespace std;
int main()
{
    const int a = 3;
    string word[a] = {"apple", "ball", "cat"};
    string nword[a] = {"lppea", "lalb", "cta"};
    string j;
    int point;
    int p = 0;
    int ctr = 0;

    cout << "BASIC" << endl;
    for (int i = 0; i < a; i++)
    {
        cout << nword[i] << endl;
        cin >> j;

        ctr++;
        if (j == word[i])
        {
            cout << "==========Congratulation=========" << endl;
            cout << "==========You Have Score:" << endl;
            cout << "       " << i + 1 << " " << "Point" << endl;
        }
        else
        {
            cout << "Wrong" << endl;
        }
    }
    // cout<<"Your Score Is:"<<point<<endl;
    return 0;
}