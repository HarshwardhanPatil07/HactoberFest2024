#include <iostream>
using namespace std;
void reverse(string s)
{
    string ros;
    if (s.length() == 0)
        return;
    ros = s.substr(1);
    reverse(ros);
    cout << s[0];//first item of array[0]
}
int main()
{
    string x;
    cout << "enter your string \n";
    cin >> x;
    reverse(x);

    return 0;
}
