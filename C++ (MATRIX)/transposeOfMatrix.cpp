// Github username : gauravbhaskar080
// Aim : Added Matrix related problem that help in learning DSA.Covered almost all questions related to matrix in DSA.
// Date : 9-10-2023
#include <iostream>
#include <vector>
using namespace std;

/*Efficient solution
 -> In-place
 -> One - Traversal
*/ 

void transposeMatrix(vector<vector<int>> &mat, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(mat[i][j], mat[j][i]);
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

/*Navie solution*/

// void transposeMatrix(vector<vector<int>>&mat,int m){
//     int temp[m][m];
//     for (int i = 0 ;i <m;i++) {
//         for (int j=0;j<m;j++){
//             temp[i][j] = mat[j][i];
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < m; j++){
//             mat[i][j] = temp[i][j];
//         }
//     }

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout<<mat[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }

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
    transposeMatrix(mat, m);
    return 0;
}
