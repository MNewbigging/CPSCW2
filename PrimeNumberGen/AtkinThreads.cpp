#include "stdafx.h"
#include "AtkinThreads.h"
#include <fstream>
#include <thread>


// Constructor sets test limit
AtkinThreads::AtkinThreads(int n)
{
	limit = n;
}

void AtkinThreads::Setup()
{
	// Clear from any previous run
	primes.clear();
	// Initiate list to correct size and values
	primes = vector<bool>(limit + 1, false);
}

void AtkinThreads::Sieve()
{
	//int threadCount = thread::hardware_concurrency();
	int threadCount = 2;
	int rootLimit = ceil(sqrt(limit));
	int workChunk = rootLimit / threadCount;
	int start = 1;
	int end = start;
	vector<thread> threads;
	for (int i = 0; i < threadCount; i++)
	{
		end += workChunk;
		if (end > limit)
			end = limit;
		threads.push_back(thread(&AtkinThreads::ThreadSieve, this, start, end));
		start = end;
	}

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


void AtkinThreads::ThreadSieve(int start, int end)
{
	for (int x = start; x <= end; x++)
	{
		for (int y = 1; y*y <= limit; y++)
		{
			// This number being considered
			int n = (4 * x * x) + (y * y);
			// Check for a, b, c as above
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

void AtkinThreads::GatherResults()
{
	// Write data to file
	ofstream primeFile("AtkinThreadsPrimes.txt", ofstream::out);

	// 2 and 3 are known to be prime, and omitted from test
	
	primeFile << 2 << endl;
	primeFile << 3 << endl;

	// Convert from bools to ints 
	for (int i = 5; i < limit; i++)
	{
		if (primes[i])
		{
			primeFile << i << endl;
		}
	}
}









