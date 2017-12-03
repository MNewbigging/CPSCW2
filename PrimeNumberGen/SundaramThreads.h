#pragma once

#include <vector>

using namespace std;

class SundaramThreads
{
public:
	// Constructor - takes in test value and sets to limit
	SundaramThreads(int n);
	~SundaramThreads() {}

	// Holds test limit value
	int limit;
	// Total iterations is half of limit
	int nNew;
	// Sieve function uses list of bools representing prime numbers
	vector<bool> primes;
	
	// Setup primes list for sieving
	void Setup();
	// Multithreaded version of sundaram sieve
	void Sieve();
	// Tasks performed by threads (contains main logic of sundaram sieve)
	void ThreadSieve(int start, int end);
	// Write results to file
	void GatherResults();

};