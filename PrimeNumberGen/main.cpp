#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Eratosthenes.h"
#include "Sundaram.h"
#include "Atkin.h"



// Used to run algorithm methods and debug with print statements
int main()
{
	// Limit
	int n = 20;
	// Create eratosthenes class, set limit
	Eratosthenes erat(n);
	erat.Setup();
	erat.Sieve();
	erat.GatherResults();


	// Create sundaram sieve
	Sundaram sund(n);
	sund.Setup();
	sund.Sieve();
	sund.GatherResults();


	// Create atkin sieve
	Atkin a(n);
	a.Setup();
	a.Sieve();
	a.GatherResults();
	for (auto &i : a.primes)
	{
		cout << i << endl;
	}
	for (auto &i : a.result)
		cout << i << endl;

	// Keep window open
	getchar();
	return 0;
}