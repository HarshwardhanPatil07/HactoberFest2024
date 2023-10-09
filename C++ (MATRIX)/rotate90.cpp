// Github username : gauravbhaskar080
// Aim : Added Matrix related problem that help in learning DSA.Covered almost all questions related to matrix in DSA.
// Date : 9-10-2023

#include <iostream>
#include <vector>
using namespace std;

/*
Efficient solution:
Time : θ(n^2)
Auxiliary Space : θ(1)
*/
void rotate90(vector<vector<int>> &mat, int m)
{
    // Transpose of matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Reverse individual columns
    for (int i = 0; i < m; i++)
    {
        int low = 0, high = m - 1;
        while (low <= high)
        {
            swap(mat[low][i], mat[high][i]);
            low++;
            high--;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m;
    cout << "Enter the number (rows = columns) : ";
    cin >> m;
    vector<vector<int>> mat;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            int element;
            cin >> element;
            v.push_back(element);
        }
        mat.push_back(v);
    }
    cout << "\nPrinting matrix after rotate anti-clockwise 90 degree : " << endl;
    rotate90(mat, m);
    return 0;
}
