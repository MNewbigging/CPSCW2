#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PrimeNumberGen\EratosthenesThreads.cpp"
#include <fstream>
#include <chrono>

using namespace std::chrono;


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SieveTests
{
	TEST_CLASS(EratosthenesThreadsTestClass)
	{
	public:
	
		// Test vars are set correctly
		TEST_METHOD(EratosthenesThreadSetupOK)
		{
			EratosthenesThreads et(20);
			et.Setup();
			et.Sieve();
			Assert assert;
			// Should only have 3 total iterations of alg loop
			assert.AreEqual(3, et.totalIterations);
			// Therefore threadCount should be set to 3
			assert.AreEqual(3, et.threadCount);
			// Work should be divided evenly; 1 iteration per thread
			assert.AreEqual(1, et.workChunk);
		}

		// Ensure sieve data is correct
		TEST_METHOD(EratosthenesThreadSieveOK)
		{
			EratosthenesThreads et(20);
			et.Setup();
			et.Sieve();
			et.GatherResults();
			// Checked the file for now - finish this later
		}

		// Gather performance stats on threads method
		TEST_METHOD(EratosthenesThreadPerformance)
		{
			EratosthenesThreads et(1000000);
			ofstream EratThreads("EratThreads.csv", ofstream::app);
			Assert assert;
			// Run test 10 times
			for (int i = 0; i < 10; i++)
			{
				et.Setup();
				auto start = system_clock::now();
				et.Sieve();
				auto end = system_clock::now();
				auto total = end - start;
				EratThreads << duration_cast<milliseconds>(total).count() << ", " << duration_cast<nanoseconds>(total).count() << endl;			
			}
		}
	};
}