// Github username : gauravbhaskar080
// Aim : Added Matrix related problem that help in learning DSA.Covered almost all questions related to matrix in DSA.
// Date : 9-10-2023

#include<iostream>
#include<vector>
using namespace std;

// Time : O(R+C)
void searchInSortedMatrix(vector<vector<int>> &mat,int R,int C,int x){
    int i=0,j=C-1;
    while(i<R && j>=0){
        if(mat[i][j]==x){
            cout << "Found at (" << i << ", " << j << ")";

            return;
        }
        else if(mat[i][j]>x){
            j--;
        }
        else{
            i++;
        }
    }
    cout << "\nNot Found" << endl;
}

int main(){
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

    int x;
    cout << "Enter the target number : ";
    cin >> x;

    searchInSortedMatrix(mat, m, n,x);
    return 0;
}

