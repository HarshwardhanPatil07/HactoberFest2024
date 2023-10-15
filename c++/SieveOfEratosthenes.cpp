// The sieve of Eratosthenes is one of the most efficient ways to find 
// all primes smaller than n when n is smaller than 10 million or so.

// C++ program to print all primes smaller than or equal to 
// n using Sieve of Eratosthenes 
#include <bits/stdc++.h> 
using namespace std; 

void SieveOfEratosthenes(int n) 
{ 
	bool prime[n + 1]; 
	memset(prime, true, sizeof(prime)); 

	for (int p = 2; p * p <= n; p++) { 
		if (prime[p] == true) { 
			for (int i = p * p; i <= n; i += p) 
				prime[i] = false; 
		} 
	} 

	for (int p = 2; p <= n; p++) 
		if (prime[p]) 
			cout << p << " "; 
} 

// Driver Code 
int main() 
{ 
	int n = 30; // chnage your input here
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl; 
	SieveOfEratosthenes(n); 
	return 0; 
}

// Contributed by: Priyansh Choudhary
