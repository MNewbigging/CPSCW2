#pragma once

#include <vector>

using namespace std;

class AtkinThreads
{
public:
	// Constructor takes in test limit, sets it to limit var
	AtkinThreads(int n);
	~AtkinThreads() {}

	// Holds test limit
	int limit;
	// Holds list of bools representing prime numbers, used in sieve function
	vector<bool> primes;

	// Set size and values of primes list
	void Setup();
	// Perform sieve of Atkin multithreaded
	void Sieve();
	// Task for each thread to perform 
	void ThreadSieve(int start, int end);
	// Print results to file
	void GatherResults();
};