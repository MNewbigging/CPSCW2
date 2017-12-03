#pragma once

#include <vector>

using namespace std;

class AtkinOpenMP
{
public:
	// Constructor takes in test limit, assings to limit var and halves for nNew var
	AtkinOpenMP(int n);
	~AtkinOpenMP() {}

	// Hold test limit number
	int limit, nNew;
	// Hold a list of bools representing numbers til n (test limit)
	vector<bool> primes;
	// List of final prime numbers - used for debugging (not used in final imp)
	vector<int> result;

	// Prepare the primes bools list
	void Setup();
	// The atkin sieve algorithm with OpenMP optimization
	void Sieve();
	// Convert bools list into int list of prime numbers
	// Write to file
	void GatherResults();
};
