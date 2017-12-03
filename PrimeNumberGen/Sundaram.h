#pragma once

#include <vector>

using namespace std;

class Sundaram
{
public:
	// Construtor takes in test limit
	Sundaram(int n);
	~Sundaram() {}

	// Hold test limit number
	int limit;
	int nNew;
	// Hold a list of bools representing numbers til test limit
	vector<bool> primes;
	// List of final prime numbers - used for debugging (not included in final imp)
	vector<int> result;

	// Prepare bools list for alg
	void Setup();
	// Sundaram sieve alg
	void Sieve();
	// Convert primes bools list to ints list, write to file
	void GatherResults();

	// The sieve algorithm
	void OLDSieve();
};