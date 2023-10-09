// Github username : gauravbhaskar080
// Aim : Added Matrix related problem that help in learning DSA.Covered almost all questions related to matrix in DSA.
// Date : 9-10-2023

#include <iostream>
#include <vector>
using namespace std;

void bTraversal(vector<vector<int>> &arr, int R, int C)
{
    if (R == 1)
    {
        for (int i = 0; i < C; i++)
        {
            cout << arr[0][i] << " ";
        }
    }
    else if (C == 1)
    {
        for (int i = 0; i <= R; i++)
        {
            cout << arr[i][0] << " ";
        }
    }
    else
    {
        for (int i = 0; i < C; i++)
        {
            cout << arr[0][i] << " ";
        }
        for (int i = 1; i < R; i++)
        {
            cout << arr[i][C - 1] << " ";
        }
        for (int i = C - 2; i >= 0; i--)
        {
            cout << arr[R - 1][i] << " ";
        }
        for (int i = R - 2; i >= 1; i--)
        {
            cout << arr[i][0] << " ";
        }
    }
}

int main()
{

    int m, n;
    cout << "Enter the number of rows : ";
    cin >> m;
    cout << "Enter the number of columns : ";
    cin >> n;

    vector<vector<int>> mat;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int element;
            cin >> element;
            v.push_back(element);
        }
        mat.push_back(v);
    }

    bTraversal(mat, m, n);

    return 0;
}
