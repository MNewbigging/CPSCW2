#include "stdafx.h"
#include "Atkin.h"
#include <fstream>

// Constructor takes and sets test limit
Atkin::Atkin(int n)
{
	limit = n;
}

// Prepare bools list for alg
void Atkin::Setup()
{
	// Clear from any previous run
	primes.clear();
	// Initiate list to correct size and values
	primes = vector<bool>(limit + 1, false);
}

// The sieve of atkin algorithm
void Atkin::Sieve()
{
	// Go through numbers 1 til sqrt(limit) (same as this number squared and limit)
	for (int x = 1; x*x <= limit; x++)
	{
		for (int y = 1; y*y <= limit; y++)
		{
			// This number being considered
			int n = (4 * x * x) + (y * y);
			// Check for a, b, c as above
			if (n <= limit && (n % 12 == 1 || n % 12 == 5))
				primes[n] = true;

			n = (3 * x * x) + (y * y);
			if (n <= limit && n % 12 == 7)
				primes[n] = true;

			if (x > y)
			{
				n = (3 * x * x) - (y * y);
				if (x > y && n <= limit && n % 12 == 11)
					primes[n] = true;
			}


		} // end for y
	} // end for x

	// Mark all multiples of squares as non-prime
	for (int s = 5; s*s <= limit; s++)
	{
		if (primes[s])
		{
			for (int i = s*s; i < limit; i += s)
			{
				primes[i] = false;
			}
		}
	}
}

// Convert bool list to int results list, write to file
void Atkin::GatherResults()
{
	// Write data to file
	ofstream primeFile("AtkinPrimes.txt", ofstream::out);

	// 2 and 3 are known to be prime, and omitted from test
	primeFile << 2 << endl;
	primeFile << 3 << endl;

	// Go through numbers 5 to limit
	for (int i = 5; i < limit; i++)
	{
		// If number is marked as prime
		if (primes[i])
		{
			// Write it to file
			primeFile << i << endl;
		}
			
	}

}





// The sieve of atkin algorithm 
// OLD = original implementation before refactoring
void Atkin::OLDSieve()
{
	// 2 and 3 are known to be prime, and omitted from test
	result.push_back(2), result.push_back(3);

	// Prep bool list
	for (int i = 0; i < limit; i++)
	{
		primes.push_back(false);
	}

	/* Mark siev[n] is true if one of the following is true:
	a) n = (4*x*x)+(y*y) has odd number of solutions, i.e., there exist
	odd number of distinct pairs (x, y) that satisfy the equation and
	n % 12 = 1 or n % 12 = 5.
	b) n = (3*x*x)+(y*y) has odd number of solutions and n % 12 = 7
	c) n = (3*x*x)-(y*y) has odd number of solutions, x > y and n % 12 = 11 */

	for (int x = 1; x*x < limit; x++)
	{
		for (int y = 1; y*y < limit; y++)
		{
			// This number being considered
			int n = (4 * x * x) + (y * y);
			// Check for a, b, c as above
			if (n <= limit && (n % 12 == 1 || n % 12 == 5))
				primes[n] = true;

			n = (3 * x * x) + (y * y);
			if (n <= limit && n % 12 == 7)
				primes[n] = true;

			n = (3 * x * x) - (y * y);
			if (x > y && n <= limit && n % 12 == 11)
				primes[n] = true;

		} // end for y
	} // end for x

	// Mark all multiples of squares as non-prime
	for (int s = 5; s*s < limit; s++)
	{
		if (primes[s])
		{
			for (int i = s*s; s < limit; i += s*s)
			{
				primes[i] = false;
			}
		}
	}


	// Convert from bools to ints 
	for (int i = 5; i < limit; i++)
	{
		if (primes[i])
			result.push_back(i);
	}

}