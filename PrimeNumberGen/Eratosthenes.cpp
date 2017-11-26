#include "stdafx.h"
#include "Eratosthenes.h"



// Perform prime number gen algorithm
void Eratosthenes::Sieve()
{
	// Prep primes bool list
	// Uses this class' n value for limit (set in constructor)
	for (int i = 0; i < limit + 1; i++)
	{
		primes.push_back(true);
	}

	// Run
	for (int p = 2; p*p <= limit; p++)
	{
		// If prime[p] is not changed, it's a prime
		if (primes[p])
		{
			// Update all multiples of p
			for (int i = p * 2; i <= limit; i += p)
			{
				primes[i] = false;
			}
		}
	} // end run loop

	// Turn bools list into prime numbers result list
	for (int p = 2; p <= limit; p++)
	{
		if (primes[p])
		{
			result.push_back(p);
		}
	}
}


