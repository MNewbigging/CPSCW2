#include "stdafx.h"
#include "Eratosthenes.h"
#include <fstream>


// Sets up sieve requirements; bool primes list
void Eratosthenes::Setup()
{
	// Prep primes bool list
	primes.clear();
	// (1n) 
	for (int i = 0; i < limit + 1; i++)
	{
		primes.push_back(true);
	}
}

// Runs the eratosthenes algorithm
void Eratosthenes::Sieve()
{
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

// Convert bools list into int list of prime numbers
void Eratosthenes::GatherResults()
{
	// Open file for writing
	ofstream primeFile("EratosthenesPrimes.txt", ofstream::out);
	// Turn bools list into prime numbers result list
	// (2n)
	for (int p = 2; p <= limit; p++)
	{
		if (primes[p])
		{
			primeFile << p << ", ";
			
			result.push_back(p);
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


