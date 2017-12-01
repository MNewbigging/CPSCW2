#pragma once

#include <vector>

using namespace std;

class SundaramThreads
{
public:
	SundaramThreads(int n);
	~SundaramThreads() {}

	int limit;
	int nNew;
	vector<bool> primes;
	


	void Setup();

	void Sieve();
	void ThreadSieve(int start, int end);
	void GatherResults();

};