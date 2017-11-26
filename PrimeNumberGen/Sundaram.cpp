#include "stdafx.h"
#include "Sundaram.h"


// The sieve of sundaram algorithm
void Sundaram::Sieve()
{
	// Half n
	int nNew = (n - 2) / 2;
	// Prep prime bools list
	for (int i = 0; i < nNew + 1; i++)
	{
		primes.push_back(false);
	}
	// Mark all numbers that fit i + j + 2ij as true
	// where 1 <= i <= j
	for (int i = 1; i <= nNew; i++)
	{
		for (int j = i; (i + j + 2 * i*j) <= nNew; j++)
		{
			primes[i + j + 2 * i * j] = true;
		}
	}

	// Convert bools to ints. 2 is assumed
	result.push_back(2);
	for (int i = 1; i <= nNew; i++)
	{
		if (!primes[i])
		{
			result.push_back(2 * i + 1);
		}
	}
}