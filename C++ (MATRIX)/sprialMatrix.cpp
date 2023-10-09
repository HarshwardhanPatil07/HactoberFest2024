// Github username : gauravbhaskar080
// Aim : Added Matrix related problem that help in learning DSA.Covered almost all questions related to matrix in DSA.
// Date : 9-10-2023

#include <iostream>
#include <vector>
using namespace std;

// Time : θ(R*C)

void printSpiral(vector<vector<int>> &mat, int R, int C)
{
    int top = 0, bottom = R - 1, left = 0, right = C - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            cout << mat[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            cout << mat[i][right] << " ";
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << mat[i][left] << " ";
            }
            left++;
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

    printSpiral(mat, m, n);

    return 0;
}
