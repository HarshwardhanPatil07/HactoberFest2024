// Simple solution to calculate square without
// using * and pow()
#include <iostream>
using namespace std;

int square(int n)
{
	if (n < 0)
		n = -n;

	int res = n;

	for (int i = 1; i < n; i++)
		res += n;

	return res;
}

int main()
{
	for (int n = 1; n <= 5; n++)
		cout << "n = " << n << ", n^2 = " << square(n)
			<< endl;
	return 0;
}
