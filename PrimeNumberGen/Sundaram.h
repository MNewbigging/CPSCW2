#pragma once

#include <vector>

using namespace std;

class Sundaram
{
public:
	// Construtor takes in test limit
	Sundaram(int n) { limit = n; }
	~Sundaram() {}

	// Hold test limit number
	int limit;
	// Hold a list of bools representing numbers til test limit
	vector<bool> primes;
	// List of final prime numbers
	vector<int> result;

	// The sieve algorithm
	void Sieve();
};