#include "stdafx.h"
#include "AtkinThreads.h"
#include <fstream>
#include <thread>


// Constructor sets test limit
AtkinThreads::AtkinThreads(int n)
{
	limit = n;
}

// Setup prime bools list for use in sieve method
void AtkinThreads::Setup()
{
	// Clear from any previous run
	primes.clear();
	// Initiate list to correct size and values
	primes = vector<bool>(limit + 1, false);
}

// Multithreaded atkin sieve method
void AtkinThreads::Sieve()
{
	// Find number of supported threads on this hardware
	//int threadCount = thread::hardware_concurrency();
	int threadCount = 2; // supported threads gives incorrect results

	// Total iterations is sqrt(limit)
	int rootLimit = ceil(sqrt(limit));
	// Divide work evenly by number of threads
	int workChunk = rootLimit / threadCount;
	// Index variables initialised to 1
	int start = 1;
	int end = start;
	// To hold all threads spawned
	vector<thread> threads;
	// For all threads to be made...
	for (int i = 0; i < threadCount; i++)
	{
		// Update end index position
		end = start + workChunk;
		// In case of uneven chunks, if end exceeds limit reset it to limit
		if (end > limit)
			end = limit;
		// Spawn thread with atkin sieve task
		threads.push_back(thread(&AtkinThreads::ThreadSieve, this, start, end));
		// Update start index 
		start = end + 1;
	}

	// Execute all threads
	for (auto &t : threads)
		t.join();



	// Mark all multiples of squares as non-prime
	for (int s = 5; s*s <= limit; s++)
	{
		if (primes[s])
		{
			for (int i = s*s; i < limit; i += s)
			{
				primes[i] = false;
			}
		}
	}
}

// Thread task - carries out main logic of Atkin sieve
void AtkinThreads::ThreadSieve(int start, int end)
{
	// Begin at given start index, up to and including given end index
	for (int x = start; x <= end; x++)
	{
		for (int y = 1; y*y <= limit; y++)
		{
			// Atkin performs modulo operations to determine primes
			int n = (4 * x * x) + (y * y);		
			if (n <= limit && (n % 12 == 1 || n % 12 == 5))
				primes[n] = true;

			n = (3 * x * x) + (y * y);
			if (n <= limit && n % 12 == 7)
				primes[n] = true;

			if (x > y)
			{
				n = (3 * x * x) - (y * y);
				if (x > y && n <= limit && n % 12 == 11)
					primes[n] = true;
			}
		} // end for y
	} // end for x
}


// Write result to file
void AtkinThreads::GatherResults()
{
	// Open file for writing
	ofstream primeFile("AtkinThreadsPrimes.txt", ofstream::out);

	// 2 and 3 are known to be prime, and omitted from test	
	primeFile << 2 << endl;
	primeFile << 3 << endl;

	// Go through numbers 5 to limit
	for (int i = 5; i < limit; i++)
	{
		// If marked true for prime
		if (primes[i])
		{
			// Write current number to primes file
			primeFile << i << endl;
		}
	}
}









