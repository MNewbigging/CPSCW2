#pragma once

#include <vector>

using namespace std;

class EratosthenesOpenMP
{
public:
	// Constructor takes in test limit value, sets to limit member var
	EratosthenesOpenMP(int n);
	~EratosthenesOpenMP() {}

	// Hold test limit number
	int limit;
	// Hold a list of bools representing numbers til n (test limit)
	vector<bool> primes;
	// List of final prime numbers - used for debugging (not used in final imp)
	vector<int> result;

	// Prepare the primes bools list
	void Setup();
	// The eratosthenes algorithm with OpenMP optimization
	void Sieve();
	// Convert bools list into int list of prime numbers
	// Write to file
	void GatherResults();
};