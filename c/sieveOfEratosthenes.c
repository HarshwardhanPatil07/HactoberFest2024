// C program to print all primes smaller than or equal to 
// The sieve of Eratosthenes is one of the most efficient ways to find 
// all primes smaller than n when n is smaller than 10 million or so.

// C program to print all primes smaller than or equal to 
// n using Sieve of Eratosthenes 
#include <stdio.h> 
#include <stdbool.h> 
#include <string.h> 

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
			printf("%d ",p); 
} 

// Driver Code 
int main() 
{ 
	int n = 30; 
	printf("Following are the prime numbers smaller than or equal to %d \n", n); 
	SieveOfEratosthenes(n); 
	return 0; 
} 
