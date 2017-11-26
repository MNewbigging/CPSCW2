#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PrimeNumberGen\Atkin.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SieveTests
{
	TEST_CLASS(AtkinTest)
	{
	public:
		// Ensures constructor works; all member variables are set 
		// with passed params
		TEST_METHOD(FunctionVariablesInitOk)
		{
			// Call constructor, pass in test limit number
			Atkin a(20);
			// Ensure that it was set correctly
			Assert assert;
			assert.AreEqual(20, a.limit);
			// Run alg
			a.Sieve();
			// Ensure result is not empty
			assert.AreNotEqual(0, (int)a.result.size());
		}

		TEST_METHOD(CorrectPrimesTo20)
		{
			// Set limit to 20 in constructor
			Atkin a(20);
			// Run alg
			a.Sieve();
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
				int actual = a.result[i];
				int check = checkResult[i];
				assert.AreEqual(check, actual);
			}
		}
	};
}