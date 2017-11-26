#pragma once

#include <vector>

using namespace std;

class Eratosthenes
{
public:
	// Constructor takes in size of test, sets to internal member var
	Eratosthenes(int limit) { n = limit; }
	~Eratosthenes() {}
	
	// Hold test limit number
	int n;
	// Hold a list of bools representing numbers til n (test limit)
	vector<bool> primes;
	// List of final prime numbers
	vector<int> result;

	// The sieve algorithm
	void Sieve();

};