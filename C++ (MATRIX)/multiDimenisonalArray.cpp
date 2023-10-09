// Github username : gauravbhaskar080
// Aim : Added Matrix related problem that help in learning DSA.Covered almost all questions related to matrix in DSA.
// Date : 9-10-2023

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "1st approach : ";
    int arr1[3][2] = {{10, 20}, {30, 40}, {50, 60}};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr1[i][j] << " ";
        }
    }

    cout << "\n2nd approach(Varibale Sized) : ";
    int m = 3, n = 2;
    int arr2[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr2[i][j] = i + j;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr2[i][j] << " ";
        }
    }

    cout << "\n3rd approach(Double Pointer) : ";
    int a = 3, b = 2;
    int **arr3;
    arr3 = new int *[a];
    for (int i = 0; i < a; i++)
    {
        arr3[i] = new int[b];
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            arr3[i][j] = 10;
            cout << arr3[i][j] << " ";
        }
    }

    cout << "\n4th approach(Array of Pointers) : ";
    int c = 3, d = 2;
    int *arr4[c];
    for (int i = 0; i < c; i++)
    {
        arr4[i] = new int[d];
    }
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            arr4[i][j] = 20;
            cout << arr4[i][j] << " ";
        }
    }

    cout << "\n5th approach(Array of Vectors) : ";
    int e = 3, f = 2;
    vector<int> arr5[e];
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < f; j++)
        {
            arr5[i].push_back(30);
        }
    }
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < f; j++)
        {
            cout << arr5[i][j] << " ";
        }
    }

    cout << "\n6th approach(Vector of Vectors) : ";
    int g = 3, h = 2;
    vector<vector<int>> arr6;
    for (int i = 0; i < g; i++)
    {
        vector<int> v;
        for (int j = 0; j < h; j++)
        {
            v.push_back(40);
        }
        arr6.push_back(v);
    }
    for (int i = 0; i < arr6.size(); i++)
    {
        for (int j = 0; j < arr6[i].size(); j++)
        {
            cout << arr6[i][j] << " ";
        }
    }

    return 0;
}
