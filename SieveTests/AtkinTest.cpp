#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PrimeNumberGen\Atkin.cpp"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SieveTests
{
	TEST_CLASS(AtkinTest)
	{
	public:
		// Ensures constructor works; all member variables are set 
		// with passed params
		TEST_METHOD(AtkinClassVariablesInitOK)
		{
			// Call constructor, pass in test limit number
			Atkin a(20);
			// Ensure that it was set correctly
			Assert assert;
			assert.AreEqual(20, a.limit);
		}

		// Tests setup method
		TEST_METHOD(AtkinSetupOK)
		{
			// Set limit to 20 in constructor
			Atkin a(20);
			// Setup
			a.Setup();
			Assert assert;
			// Ensure primes list size is setup correctly
			assert.AreEqual(20, (int)a.primes.size());
			for (int i = 0; i < 20; i++)
			{
				assert.IsFalse(a.primes[i]);
			}
		}

		// Tests Sieve method
		TEST_METHOD(AtkinSieveOK)
		{
			Atkin a(20);
			a.Setup();
			a.Sieve();

			Assert assert;
			// 5th should be true (assumes 2 and 3)
			assert.IsTrue(a.primes[5]);
			assert.IsTrue(a.primes[7]);
			assert.IsTrue(a.primes[11]);
			assert.IsTrue(a.primes[13]);
		}

		// Tests results method
		TEST_METHOD(AtkinsResultsOK)
		{
			Atkin a(20);
			a.Setup();
			a.Sieve();
			a.GatherResults();

			Assert assert;
			// Ensure output file is created
			ifstream results("AtkinPrimes.txt");
			assert.IsTrue(results.good());

			// Make sure results are correct
			assert.AreEqual(2, a.result[0]);
			assert.AreEqual(3, a.result[1]);
			assert.AreEqual(11, a.result[4]);
			assert.AreEqual(17, a.result[6]);
		}
	};
}