#include "stdafx.h"
#include "AtkinOpenMP.h"
#include <fstream>
#include <thread>


// Constructor sets limit
AtkinOpenMP::AtkinOpenMP(int n)
{
	limit = n;
}

// Preprares bools list for alg
void AtkinOpenMP::Setup()
{
	// Clear from any previous run
	primes.clear();
	// Initiate list to correct size and values
	primes = vector<bool>(limit + 1, false);
}

// Sieve of Atkin algorithm optimized with openMP
void AtkinOpenMP::Sieve()
{
	int rootLimit = ceil(sqrt(limit));

	auto threadCount = thread::hardware_concurrency();

#pragma omp parallel for num_threads(threadCount)
	for (int x = 1; x <= rootLimit; x++)
	{
		for (int y = 1; y <= rootLimit; y++)
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
void AtkinOpenMP::GatherResults()
{
	// Write data to file
	ofstream primeFile("AtkinOMPPrimes.txt", ofstream::out);

	// 2 and 3 are known to be prime, and omitted from test
	//result.push_back(2), result.push_back(3);
	primeFile << 2 << endl;
	primeFile << 3 << endl;

	// Convert from bools to ints 
	for (int i = 5; i < limit; i++)
	{
		if (primes[i])
		{
			//result.push_back(i);
			primeFile << i << endl;
		}
	}
}






