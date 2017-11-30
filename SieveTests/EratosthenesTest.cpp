#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PrimeNumberGen\Eratosthenes.cpp"
#include <fstream>
#include <chrono>

using namespace std::chrono;


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SieveTests
{
	TEST_CLASS(EratosthenesTestClass)
	{
	public:
		// Ensures constructor works; all member variables are set 
		// with passed params
		TEST_METHOD(EratosthenesClassVariablesInitOK)
		{
			// Call constructor, pass in test limit number
			Eratosthenes e(500000000);
			// Ensure that it was set correctly
			Assert assert;
			assert.AreEqual(500000000, e.limit);

		}

		// Tests the Setup method 
		TEST_METHOD(EratosthenesSetupOK)
		{
			Eratosthenes e(20);
			e.Setup();
			Assert assert;
			// Primes list should be setup to size of limit + 1
			assert.AreEqual(21, (int)e.primes.size());
			// Each item in list should be true initially
			for (int i = 0; i < 21; i++)
			{
				assert.IsTrue(e.primes[i]);
			}
		}

		// Test the Sieve method
		TEST_METHOD(EratosthenesSieveOK)
		{
			// Set limit to 20 in constructor
			Eratosthenes e(20);
			// Setup
			e.Setup();
			// Run alg
			e.Sieve();
			// Ensure that known primes values are true
			Assert assert;
			assert.IsTrue(e.primes[2]);
			assert.IsTrue(e.primes[3]);
			assert.IsTrue(e.primes[5]);
			assert.IsTrue(e.primes[7]);
			assert.IsTrue(e.primes[11]);
			assert.IsTrue(e.primes[13]);
			assert.IsTrue(e.primes[17]);
			assert.IsTrue(e.primes[19]);
		}
	
		// Test the gather results method
		TEST_METHOD(EratosthenesResultsOK)
		{
			Eratosthenes e(20);
			e.Setup();
			e.Sieve();
			e.GatherResults();
			
			Assert assert;
			// Make sure file is written to correctly
			ifstream results("EratosthenesPrimes.txt");
			assert.IsTrue(results.good());
			
			// TODO - read line, ensure primes are correct
			// and in order
		}
	
	
	
	};
}