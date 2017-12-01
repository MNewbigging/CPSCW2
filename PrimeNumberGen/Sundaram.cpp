#include "stdafx.h"
#include "Sundaram.h"
#include <fstream>
#include <iostream>
#include <string>

// Constructor takes in test limit 
// Also defines half limit for which alg runs up until
Sundaram::Sundaram(int n)
{
	limit = n;
	nNew = (limit) / 2;
}

// Prepare bools list for alg
void Sundaram::Setup()
{
	// Clear from any previous run
	primes.clear();
	// Initiate list to correct size and values
	primes = vector<bool>(nNew + 1, true);
}

// Run sieve of sundaram algorithm
void Sundaram::Sieve()
{
	for (int i = 1; i < nNew; ++i)
	{
		for (int j = i; j <= (nNew - i) / (2 * i + 1); ++j)
		{
			primes[i + j + 2 * i * j] = false;
		}
	}
}

// Convert primes bools list to ints list, write to file
void Sundaram::GatherResults()
{
	ofstream primeFile("SundaramPrimes.txt", ofstream::out);
	// Convert bools to ints. 2 is assumed
	result.push_back(2);
	primeFile << 2 << endl;
	for (int i = 1; i <= nNew; i++)
	{
		if (primes[i])
		{
			primeFile << 2 * i + 1 << endl;
			result.push_back(2 * i + 1);
		}
	}
}


// The sieve of sundaram algorithm
void Sundaram::OLDSieve()
{
	// Half n
	int nNew = (limit - 2) / 2;
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