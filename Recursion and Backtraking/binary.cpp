// C++ implementation of the above approach:

#include <bits/stdc++.h>
using namespace std;

// Function to print the output
void printTheArray(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Function to generate all binary strings
void generateAllBinaryStrings(int n, int arr[], int i)
{
	if (i == n) {
		printTheArray(arr, n);
		return;
	}

	// First assign "0" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 0;
	generateAllBinaryStrings(n, arr, i + 1);

	// And then assign "1" at ith position
	// and try for all other permutations
	// for remaining positions
	arr[i] = 1;
	generateAllBinaryStrings(n, arr, i + 1);
}

// Driver Code
int main()
{
	int n = 4;

	int arr[n];

	// Print all binary strings
	generateAllBinaryStrings(n, arr, 0);

	return 0;
}
