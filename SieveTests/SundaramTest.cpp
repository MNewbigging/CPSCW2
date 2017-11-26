#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PrimeNumberGen\Sundaram.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SieveTests
{
	TEST_CLASS(SundaramTest)
	{
	public:
		// Ensures constructor works; all member variables are set 
		// with passed params
		TEST_METHOD(FunctionVariablesInitOk)
		{
			// Call constructor, pass in test limit number
			Sundaram s(20);
			// Ensure that it was set correctly
			Assert assert;
			assert.AreEqual(20, s.limit);
			// Run alg
			s.Sieve();
			// Ensure result is not empty
			assert.AreNotEqual(0, (int)s.result.size());
		}

		TEST_METHOD(CorrectPrimesTo20)
		{
			// Set limit to 20 in constructor
			Sundaram s(20);
			// Run alg
			s.Sieve();
			// Create correct results to check against
			vector<int> checkResult;
			checkResult.push_back(2);
			checkResult.push_back(3);
			checkResult.push_back(5);
			checkResult.push_back(7);
			checkResult.push_back(11);
			checkResult.push_back(13);
			checkResult.push_back(17);
			checkResult.push_back(19);
			// Create assert to perform checks
			Assert assert;
			for (int i = 0; i < checkResult.size(); i++)
			{
				int actual = s.result[i];
				int check = checkResult[i];
				assert.AreEqual(check, actual);
			}
		}
	};
}