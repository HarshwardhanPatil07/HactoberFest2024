#include<bits/stdc++.h> 
using namespace std; 

int maximum(int main_array[], int n) 
{ 
int t, i; 
for (t = 0, i = 0; i < n; ++i) 
	if (main_array[i] > main_array[t]) 
			t = i; 
return t; 
} 

void reverse(int main_array[], int i) 
{ 
	int temp, start = 0; 
	while (start < i) 
	{ 
		temp = main_array[start]; 
		main_array[start] = main_array[i]; 
		main_array[i] = temp; 
		start++; 
		i--; 
	} 
} 


void pancakeSort(int *main_array, int n) 
{ 

	for (int curr_size = n; curr_size > 1; --curr_size) 
	{ 
		int mi = maximum(main_array, curr_size); 
		if (mi != curr_size-1) 
		{ 
			reverse(main_array, mi); 
			reverse(main_array, curr_size-1); 
		} 
	} 
} 

void printer(int main_array[], int n) 
{ 
	for (int i = 0; i < n; ++i) 
		cout<< main_array[i]<<" "; 
} 

int main() 
{ 
	int main_array[] = { 4, 134, 5, 2, 22, 111, 0}; 
	int n = sizeof(main_array)/sizeof(main_array[0]); 

	pancakeSort(main_array, n); 

	cout<<"Sorted main_arrayay "<<endl; 
	printer(main_array, n); 

	return 0; 
} 

