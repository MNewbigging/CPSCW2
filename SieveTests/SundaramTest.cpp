#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PrimeNumberGen\Sundaram.cpp"
#include <fstream>
#include <chrono>

using namespace std::chrono;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SieveTests
{
	TEST_CLASS(SundaramTest)
	{
	public:
		// Ensures constructor works; all member variables are set 
		// with passed params
		TEST_METHOD(SundaramClassVariablesInitOK)
		{
			// Call constructor, pass in test limit number
			Sundaram s(20);
			// Ensure that it was set correctly
			Assert assert;
			assert.AreEqual(20, s.limit);
			// Ensure half limit was set correctly (-2 / 2)
			assert.AreEqual(9, s.nNew);
		}

		// Tests setup method
		TEST_METHOD(SundaramSetupOK)
		{
			Sundaram s(20);
			s.Setup();
			Assert assert;
			// Ensure primes list size is setup correctly
			assert.AreEqual(10, (int)s.primes.size());
			// Ensure everything is false
			for (int i = 0; i < 10; i++)
			{
				assert.IsFalse(s.primes[i]);
			}
		}

		// Tests Sieve method
		TEST_METHOD(SundaramSieveOK)
		{
			Sundaram s(20);
			s.Setup();
			s.Sieve();

			// First 4 should be false
			Assert assert;
			for (int i = 0; i < 4; i++)
			{
				assert.IsFalse(s.primes[i]);
			}
			// 5th should be true
			assert.IsTrue(s.primes[4]);
		}

		// Tests results method
		TEST_METHOD(SundaramResultsOK)
		{
			Sundaram s(20);
			s.Setup();
			s.Sieve();
			s.GatherResults();

			Assert assert;
			// Make sure file is written to correctly
			ifstream results("SundaramPrimes.txt");
			assert.IsTrue(results.good());

			// Make sure results are correct
			assert.AreEqual(2, s.result[0]);
			assert.AreEqual(3, s.result[1]);
			assert.AreEqual(11, s.result[4]);
			assert.AreEqual(17, s.result[6]);
		}

		// Gather timing data for baseline performance
		TEST_METHOD(SundaramBaselinePerformance)
		{
			Sundaram s(10000);
			// Time Sieve method only 10 times
			ofstream SundResults("SundBaseline.csv", ofstream::app);
			for (int i = 0; i < 10; i++)
			{
				s.Setup();
				auto start = system_clock::now();
				s.Sieve();
				auto end = system_clock::now();
				auto total = end - start;
				SundResults << duration_cast<milliseconds>(total).count() << ", ";
			}
		}
	};
}