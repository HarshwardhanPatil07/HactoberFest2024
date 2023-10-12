//github username - rudra76 date : 12/10/23 Aim: Created number pattern in cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of rows:";
    cin >> n;
    int row = 1;
    while (row <= n)
    {
        int col = 1;
        int value = row;
        while (col <= row)
        {
            cout << value << " ";
            value++;
            col++;
        }
        cout << endl;
        row++;
    }
}