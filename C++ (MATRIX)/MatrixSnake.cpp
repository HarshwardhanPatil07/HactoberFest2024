// Github username : gauravbhaskar080
// Aim : Added Matrix related problem that help in learning DSA.Covered almost all questions related to matrix in DSA.
// Date : 9-10-2023

#include <iostream>
using namespace std;

void printSnake(int **mat, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                cout << mat[i][j] << " ";
            }
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

    // Dynamically allocate memory for the matrix
    int **mat = new int *[m];
    for (int i = 0; i < m; i++)
    {
        mat[i] = new int[n];
    }

    cout << "Enter the elements:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << "Print a Matrix in Snake Pattern :" << endl;
    printSnake(mat, m, n);

    for (int i = 0; i < m; i++)
    {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}
