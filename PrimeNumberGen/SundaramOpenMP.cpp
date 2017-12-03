#include "stdafx.h"
#include "SundaramOpenMP.h"
#include <fstream>
#include <thread>

// Constructor takes in test limit, halves it for loop limit
SundaramOpenMP::SundaramOpenMP(int n)
{
	limit = n;
	nNew = limit / 2;
}


// Prepare the primes bools list
void SundaramOpenMP::Setup()
{
	// Clear from any previous run
	primes.clear();
	// Initiate list to correct size and values
	primes = vector<bool>(nNew + 1, true);
}

// Run sieve algorithm optimized with openMP
void SundaramOpenMP::Sieve()
{
	// Find out number of supported threads
	int threadCount = thread::hardware_concurrency();

	// Optimize using openMP
#pragma omp parallel for num_threads(threadCount)
	// This is same logic found in Sundaram.cpp sieve() function
	for (int i = 1; i < nNew; ++i)
	{
		for (int j = i; j <= (nNew - i) / (2 * i + 1); ++j)
		{
			primes[i + j + 2 * i * j] = false;
		}
	}
}

// Convert bools list into int list of prime numbers and write to file
void SundaramOpenMP::GatherResults()
{
	// Open file for writing
	ofstream primeFile("SundaramOMPPrimes.txt", ofstream::out);
	// 2 is assumed
	primeFile << 2 << endl;
	// Go through numbers 1 til half limit
	for (int i = 1; i <= nNew; i++)
	{
		// If marked as prime
		if (primes[i])
		{
			// Write prime number (2*currentNumber+1) to file
			primeFile << 2 * i + 1 << endl;
		}
	}
}





