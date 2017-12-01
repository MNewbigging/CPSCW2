#pragma once
#include <vector>
#include <mutex>
#include <iostream>

using namespace std;

class EratosthenesThreads
{
public:
	// Constructor takes in size of test, sets to internal member var
	EratosthenesThreads(int n) { limit = n; }
	~EratosthenesThreads() {}

	// Hold test limit number
	int limit;

	// Threads variables
	int totalIterations = 0;
	int threadCount = 0;
	int workChunk = 0; // Iterations count per thread
	mutex mut;

	// Hold a list of bools representing numbers til n (test limit)
	vector<bool> primes;
	// List of final prime numbers
	vector<int> result;

	// Prepare the primes bools list
	void Setup();
	// The eratosthenes algorithm
	void Sieve();

	// Thread task - cross out multiples of current number in alg
	void ThreadSieve(int start, int end);
	// Thread approach 2
	void Sieve2();
	// thread task 2
	void ThreadCrossOutMultiples(int p);

	void Sieve3();

	void ThreadMultiples(int num, int start, int end);


	// Convert bools list into int list of prime numbers
	// Write to file
	void GatherResults();


	// The sieve algorithm in full
	// OLD = original implementation before refactoring
	void OLDSieve();

};