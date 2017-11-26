#include "stdafx.h"
#include <iostream>

#include "Eratosthenes.h"





// Used to run algorithm methods and debug with print statements
int main()
{
	// Limit
	int n = 20;
	// Create eratosthenes sieve
	Eratosthenes erat(n);
	// Run
	erat.Sieve();
	for (auto &i : erat.result)
		cout << i << endl;

	// Keep window open
	getchar();
	return 0;
}