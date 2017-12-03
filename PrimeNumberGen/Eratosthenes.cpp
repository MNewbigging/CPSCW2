#include "stdafx.h"
#include "Eratosthenes.h"
#include <fstream>
#include <thread>
#include <iostream>

// Constuctor sets given test limit value
Eratosthenes::Eratosthenes(int n)
{
	limit = n;
}

// Sets up sieve requirements; bool primes list
void Eratosthenes::Setup()
{
	// Clear from any previous runs
	primes.clear();
	// Initiate list to correct size and values
	primes = vector<bool>(limit + 1, true);
}

// Runs the eratosthenes algorithm
void Eratosthenes::Sieve()
{
	// Increment current number being looked at so long as 
	// it is less than sqrt of limit (or itself squared is less than limit)
	for (int p = 2; p*p <= limit; p++)
	{
		// If prime[p] is not checked/prime
		if (primes[p])
		{
			// Update all multiples of p
			for (int i = p * 2; i <= limit; i += p)
			{
				// This is not a prime
				primes[i] = false;
			}
		}
	} // end run loop
}

// Convert bools list into int list of prime numbers and write to file
void Eratosthenes::GatherResults()
{
	// Open file for writing
	ofstream primeFile("EratosthenesPrimes.txt", ofstream::out);
	// Go through all indices in bools list
	for (int p = 2; p <= limit; p++)
	{
		// If it is marked true
		if (primes[p])
		{
			// Write this prime to the file
			primeFile << p << endl;
		}
	}
}



// Perform prime number gen algorithm
// OLD = original implementation before refactoring
void Eratosthenes::OLDSieve()
{
	// Prep primes bool list
	// (1n) Good place to make parallel
	for (int i = 0; i < limit + 1; i++)
	{
		primes.push_back(true);
	}

	// Run
	// (?n) 
	for (int p = 2; p*p <= limit; p++)
	{
		// If prime[p] is not checked/prime
		if (primes[p])
		{
			// Update all multiples of p
			for (int i = p * 2; i <= limit; i += p)
			{
				// This is not a prime
				primes[i] = false;
			}
		}
	} // end run loop

	// Turn bools list into prime numbers result list
	// (2n)
	for (int p = 2; p <= limit; p++)
	{
		if (primes[p])
		{
			result.push_back(p);
		}
	}
}


