#include "stdafx.h"
#include "SundaramThreads.h"
#include <fstream>
#include <thread>

// Constructor - takes in test limit, sets to member var and finds half limit
SundaramThreads::SundaramThreads(int n)
{
	limit = n;
	nNew = limit / 2;
}

// Prepare bools list for algorithm
void SundaramThreads::Setup()
{
	// In case of any previous run
	primes.clear();
	// Set list to correct size and values
	primes = vector<bool>(nNew + 1, true);
}

// Sundaram sieve multithreaded function
void SundaramThreads::Sieve()
{
	// Find total number of supported threads
	int threadCount = thread::hardware_concurrency(); 
	// Divide total iterations by threads to find work amount for each thread
	int workChunk = nNew / threadCount;
	// Initialise index variables to 1
	int start = 1;
	int end = start;
	// To hold all threads spawned
	vector<thread> threads;
	// For each thread...
	for (int t = 0; t < threadCount; t++)
	{
		// Update end index position
		end += workChunk;
		// Spawn thread, give it task
		threads.push_back(thread(&SundaramThreads::ThreadSieve, this, start, end));
		// Update start index position
		start = end;
	}

	// Execute all threads
	for (auto &t : threads)
		t.join();
}

// Thread task - performs main logic of sundaram sieve
void SundaramThreads::ThreadSieve(int start, int end)
{
	// Begin at given start index, up to given end index
	for (int i = start; i < end; ++i)
	{
		// This is identical to Sundaram.cpp sieve() logic
		for (int j = i; j <= (nNew - i) / (2 * i + 1); ++j)
		{
			primes[i + j + 2 * i * j] = false;
		}
	}
}

// Write results to file
void SundaramThreads::GatherResults()
{
	// Open file for writing
	ofstream primeFile("SundaramThreadsPrimes.txt", ofstream::out);
	// 2 is assumed
	primeFile << 2 << endl;
	// For 1 through iteration limit
	for (int i = 1; i <= nNew; i++)
	{
		// If marked true for prime
		if (primes[i])
		{
			// i*2+1 is the prime number, write to file
			primeFile << 2 * i + 1 << endl;
		}
	}
}










