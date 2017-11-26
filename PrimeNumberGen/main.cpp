#include "stdafx.h"
#include <iostream>

#include "Eratosthenes.h"
#include "Sundaram.h"




// Used to run algorithm methods and debug with print statements
int main()
{
	// Limit
	int n = 20;
	// Create eratosthenes sieve
	Eratosthenes erat(n);
	// Run
	erat.Sieve();
	cout << "Eratosthenes:" << endl;
	for (auto &i : erat.result)
		cout << i << endl;

	// Create sundaram sieve
	Sundaram sund(n);
	// Run
	sund.Sieve();
	cout << "Sundaram:" << endl;
	for (auto &i : sund.result)
		cout << i << endl;
	// Keep window open
	getchar();
	return 0;
}