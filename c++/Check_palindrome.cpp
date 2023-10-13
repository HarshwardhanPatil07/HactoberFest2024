// Program to check whether a number is palindrome or not by conversion to string

#include <bits/stdc++.h>
using namespace std;

// Function to check if a given number is palindrome or not
bool isPalindrome(int n)
{

		string num = to_string(n);          //integer to sting
		string reversed = num;
	
		reverse(reversed.begin(), reversed.end());  // reversing the number (in string form)
		
		if (num == reversed) return true;
	  return false;
}

// Driver Code
int main() {

	int n;
  cout<<"Enter the number to be checked: ";
  cin>>n;
  if(isPalindrome(n))	cout<<"Is "<< n << " a Palindrome number? : "<<"Yes"<<endl;
  else cout<<"Is "<< n << " a Palindrome number? : "<<"NO"<<endl;
	return 0;
}
