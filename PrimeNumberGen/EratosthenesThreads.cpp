#include "stdafx.h"
#include "EratosthenesThreads.h"
#include <fstream>
#include <thread>

// Sets up sieve requirements; bool primes list
void EratosthenesThreads::Setup()
{
	// Prep primes bool list
	primes.clear();
	// Reset global vars
	totalIterations = threadCount = workChunk = 0;
	
	 
	// (1n) 
	for (int i = 0; i < limit + 1; i++)
	{
		primes.push_back(true);
	}
}

// Runs the eratosthenes algorithm
void EratosthenesThreads::Sieve()
{

	// 1 - Determine how many iterations in total
	for (int p = 2; p*p <= limit; p++)
	{
		totalIterations++;
	}


	// 2 - Setup appropriate number of threads

	// If the iterations count is less than total number of supported threads on this system
	if (totalIterations < thread::hardware_concurrency())
	{
		// Only use as many threads as necessary (as iterations count)
		threadCount = totalIterations;
	}
	else
	{
		// Otherwise, use max number of supported threads
		threadCount = thread::hardware_concurrency();
	}

	// 3 - Assign work to threads, work size is based on totalIterations over threads
	// How many iterations will each thread perform? 
	// TODO - deal with unequal work loads
	workChunk = totalIterations / threadCount;

	/* Sketch - 3 threads (threadCount), 1 iteration each (workChunk)
	: start = 2, end = start(2) + workChunk(1)
	## loop ##
	-> each thread does:  p = start(2); p < end(3); p++ 
	start++
	: start = 3, end = start(3) + workChunk(1)
	## next loop ##
	-> each thread does: p = start(3); p < end(4); p++
	*/
	// 3 - Use threads to execute given portions of total iterations
	vector<thread> threads;

	int start = 2;	
	// For each thread...
	for (int i = 0; i < threadCount; i++)
	{
		// Assign it's work load
		int end = start + workChunk;
		// thread
		threads.push_back(thread(&EratosthenesThreads::ThreadSieve, this, start, end));
		// Update start point for next thread
		start = end;
	}

	for (auto &t : threads)
		t.join();

}

// Thread task - cross out multiples of current number in alg
void EratosthenesThreads::ThreadSieve(int start, int end)
{
	// Perform given allotment of iterations
	for (int p = start; p < end; p++)
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
void EratosthenesThreads::GatherResults()
{
	// Open file for writing
	ofstream primeFile("EratosthenesThreadsPrimes.txt", ofstream::out);
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
void EratosthenesThreads::OLDSieve()
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


