#pragma once

#include <vector>

using namespace std;

class Eratosthenes
{
public:
	// Constructor takes in size of test, sets to internal member var
	Eratosthenes(int n) { limit = n; }
	~Eratosthenes() {}
	
	// Hold test limit number
	int limit;
	// Hold a list of bools representing numbers til n (test limit)
	vector<bool> primes;
	// List of final prime numbers
	vector<int> result;

	// Prepare the primes bools list
	void Setup();
	// The eratosthenes algorithm
	void Sieve();
	// Thread task - cross out multiples of current number in alg
	void CrossOutMultiples(int p);

	// Convert bools list into int list of prime numbers
	// Write to file
	void GatherResults();


	// The sieve algorithm in full
	// OLD = original implementation before refactoring
	void OLDSieve();

};