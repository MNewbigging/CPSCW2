#pragma once

#include <vector>

using namespace std;

class SundaramOpenMP
{
public:
	// Constructor takes in test limit, assigns to limit members var and halves for nNew var
	SundaramOpenMP(int n);
	~SundaramOpenMP() {}

	// Hold test limit number
	int limit, nNew;
	// Hold a list of bools representing numbers til n (test limit)
	vector<bool> primes;
	// List of final prime numbers
	vector<int> result;

	// Prepare the primes bools list
	void Setup();
	// The sundaram sieve algorithm with openMP optimization
	void Sieve();
	// Convert bools list into int list of prime numbers
	// Write to file
	void GatherResults();
};
