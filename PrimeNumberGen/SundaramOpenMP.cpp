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
#pragma omp parallel for schedule(static) num_threads(threadCount)
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
	ofstream primeFile("SundaramOMPPrimes.txt", ofstream::out);
	// Convert bools to ints. 2 is assumed
	//result.push_back(2);
	primeFile << 2 << endl;
	for (int i = 1; i <= nNew; i++)
	{
		if (primes[i])
		{
			primeFile << 2 * i + 1 << endl;
			//result.push_back(2 * i + 1);
		}
	}
}





