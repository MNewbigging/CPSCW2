#pragma once

#include <vector>

using namespace std;

class Atkin
{
public: 
	// Constructor takes and sets test limit
	Atkin(int n);
	~Atkin() {}

	// Hold test limit
	int limit;
	// Hold a list of bools representing numbers til test limit
	vector<bool> primes;
	// List of final prime numbers - for debugging (not used in final imp)
	vector<int> result;

	// Prepare bools list for alg
	void Setup();
	// Atkin sieve alg
	void Sieve();
	// Convert bool list to int results list, write to file
	void GatherResults();


	// The alg
	void OLDSieve();
};

