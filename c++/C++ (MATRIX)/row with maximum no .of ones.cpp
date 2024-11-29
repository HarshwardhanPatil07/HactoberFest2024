// C++ program to find the row with maximum
// number of 1s
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
// The main function that returns index of row with maximum
// number of 1s.
int rowWithMax1s(bool mat[R][C])
{
	// Initialize first row as row with max 1s
	int j,max_row_index = 0;
	j = C - 1;

	for (int i = 0; i < R; i++) {
		// Move left until a 0 is found
	bool flag=false; //to check whether a row has more 1's than previous
		while (j >= 0 && mat[i][j] == 1) {
			j = j - 1; // Update the index of leftmost 1
					// seen so far
		flag=true ;//present row has more 1's than previous
		}
	// if the present row has more 1's than previous
	if(flag){
			max_row_index = i; // Update max_row_index
		}
	}
	if(max_row_index==0&&mat[0][C-1]==0)
			return -1;
	return max_row_index;
}
// Driver Code
int main()
{
	bool mat[R][C] = { {0, 0, 0, 1},
					{0, 1, 1, 1},
					{1, 1, 1, 1},
					{0, 0, 0, 0}};

	cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);

	return 0;
}
// this code is contributed by Rishabh Chauhan
