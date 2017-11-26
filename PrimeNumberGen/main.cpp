#include "stdafx.h"
#include <iostream>

#include "Eratosthenes.h"
#include "Sundaram.h"
#include "Atkin.h"



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


	// Create atkin sieve
	Atkin a(n);
	// Run
	a.Sieve();
	cout << "Atkin:" << endl;
	for (auto &i : a.result)
		cout << i << endl;


	// Keep window open
	getchar();
	return 0;
}