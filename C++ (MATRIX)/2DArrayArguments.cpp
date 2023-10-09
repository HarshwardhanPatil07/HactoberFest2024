// Github username : gauravbhaskar080
// Aim : Added Matrix related problem that help in learning DSA.Covered almost all questions related to matrix in DSA.
// Date : 9-10-2023

#include <iostream>
#include <vector>
    using namespace std;

void print1(int mat[3][2])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
}
void print2(int mat[][2], int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
}

const int R = 3;
const int C = 2;

void print3(int mat[R][C])
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
}

void print4(int **arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 1;
            cout << arr[i][j] << " ";
        }
    }
}

void print5(int *arr[], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 2;
            cout << arr[i][j] << " ";
        }
    }
}

void print6(vector<int> arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}

void print7(vector<vector<int>>&arr){
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout<< arr[i][j] << " ";
        }
        cout << endl;
    }   
}

int main()
{
    cout << "1st approach : ";
    int mat1[3][2] = {{10, 20}, {30, 40}, {50, 60}};
    print1(mat1);

    cout << "\n2nd approach(Varibale Sized) : ";
    print2(mat1, 3);

    cout << "\n3rd approach(Global varibale) : ";
    print3(mat1);

    cout << "\n4th approach(Double Pointer) : ";
    int **arr1;
    int a = 3, b = 2;
    arr1 = new int *[a];
    for (int i = 0; i < a; i++)
    {
        arr1[i] = new int[b];
    }
    print4(arr1, a, b);

    cout << "\n5th approach(Array of Pointers) : ";
    int c = 3, d = 2;
    int *arr2[c];
    for (int i = 0; i < c; i++)
    {
        arr2[i] = new int[d];
    }
    print5(arr2, c, d);

    cout << "\n6th approach(Array of Vectors) : ";
    int e = 3, f = 2;
    vector<int> arr3[e];
    for (int i = 0; i < e; i++)
    {
        for (int j = 0; j < f; j++)
        {
            arr3[i].push_back(i);
        }
    }
    print6(arr3, e);

    cout << "\n7th approach(Vector of Vectors) : ";
    int g = 3, h = 2;
    vector<vector<int>> arr4;
    for (int i = 0; i < g; i++)
    {
        vector<int> v;
        for (int j = 0; j < h; j++)
        {
            v.push_back(i+1);
        }
        arr4.push_back(v);
    }
    print7(arr4);

    return 0;
}
