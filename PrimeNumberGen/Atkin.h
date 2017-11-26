#pragma once

#include <vector>

using namespace std;

class Atkin
{
public: 
	// Constructor takes and sets test limit
	Atkin(int n);
	~Atkin();

	// Hold test limit
	int limit;
	// Hold a list of bools representing numbers til test limit
	vector<bool> primes;
	// List of final prime numbers
	vector<int> result;

	// The alg
	void Sieve();
};

