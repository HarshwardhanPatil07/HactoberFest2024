#include <bits/stdc++.h>
using namespace std;

void insertionSort(int main_array[], int size)
{
	int i,j,key;
	for (i = 1; i < size; i++) {
		key = main_array[i];
		j = i - 1;
		while (j >= 0 && main_array[j] > key) {
			main_array[j + 1] = main_array[j];
			j = j - 1;
		}
		main_array[j + 1] = key;
	}
}

void printer(int main_array[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << main_array[i] << " ";
	cout << endl;
}

int main()
{
	int main_array[] = { 4, 134, 5, 2, 22, 111, 0};
	int size = sizeof(main_array) / sizeof(main_array[0]);

	insertionSort(main_array, size);
	printer(main_array, size);

	return 0;
}
