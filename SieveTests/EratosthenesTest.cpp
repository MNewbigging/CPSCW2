#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PrimeNumberGen\Eratosthenes.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SieveTests
{
	TEST_CLASS(EratosthenesTestClass)
	{
	public:
		// Ensures constructor works; all member variables are set 
		// with passed params
		TEST_METHOD(FunctionVariablesInitOk)
		{
			// Call constructor, pass in test limit number
			Eratosthenes e(20);
			// Ensure that it was set correctly
			Assert assert;
			assert.AreEqual(20, e.n);
		}


	};
}