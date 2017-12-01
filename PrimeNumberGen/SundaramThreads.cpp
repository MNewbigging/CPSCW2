#include "stdafx.h"
#include "SundaramThreads.h"
#include <fstream>
#include <thread>

SundaramThreads::SundaramThreads(int n)
{
	limit = n;
	nNew = limit / 2;
}



void SundaramThreads::Setup()
{
	primes.clear();
	primes = vector<bool>(nNew + 1, true);
}


void SundaramThreads::Sieve()
{
	int threadCount = 2;
	int workChunk = nNew / threadCount;
	int start = 1;
	int end = start;
	vector<thread> threads;
	for (int t = 0; t < threadCount; t++)
	{
		end += workChunk;
		threads.push_back(thread(&SundaramThreads::ThreadSieve, this, start, end));
		start = end;
	}

	for (auto &t : threads)
		t.join();
}


void SundaramThreads::ThreadSieve(int start, int end)
{
	for (int i = start; i < end; ++i)
	{
		for (int j = i; j <= (nNew - i) / (2 * i + 1); ++j)
		{
			primes[i + j + 2 * i * j] = false;
		}
	}
}



void SundaramThreads::GatherResults()
{
	ofstream primeFile("SundaramThreadsPrimes.txt", ofstream::out);
	// Convert bools to ints. 2 is assumed
	primeFile << 2 << ", ";
	for (int i = 1; i <= nNew; i++)
	{
		if (primes[i])
		{
			primeFile << 2 * i + 1 << ", ";
		}
	}
}










