#pragma once

#include <vector>

using namespace std;

class AtkinThreads
{
public:
	AtkinThreads(int n);
	~AtkinThreads() {}

	int limit;
	vector<bool> primes;

	void Setup();
	void Sieve();
	void ThreadSieve(int start, int end);
	void GatherResults();
};