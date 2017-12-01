#include "stdafx.h"
#include "EratosthenesOpenMP.h"
#include <fstream>
#include <thread>

// Constructor sets given test limit value
EratosthenesOpenMP::EratosthenesOpenMP(int n)
{
	limit = n;
}

// Sets up sieve requirements; bool primes list
void EratosthenesOpenMP::Setup()
{
	// Prep primes bool list
	primes.clear();
	primes = vector<bool>(limit + 1, true);
}

// Runs the eratosthenes algorithm with OpenMP optimization
void EratosthenesOpenMP::Sieve()
{
	// Find number of threads this hardware supports
	int threadCount = thread::hardware_concurrency();

// Incrementing p can't be done in parallel
	for (int p = 2; p*p <= limit; p++)
	{
		// This line will cause errors if above for loop was parallel; each thread would have different values for primes[p]
		// If prime[p] is not checked/prime
		if (primes[p])
		{
// Crossing out multiples can be made parallel
#pragma omp parallel for schedule(dynamic) num_threads(threadCount)
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
void EratosthenesOpenMP::GatherResults()
{
	// Open file for writing
	ofstream primeFile("EratosthenesOMPPrimes.txt", ofstream::out);
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
