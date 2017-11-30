#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Eratosthenes.h"
#include "Sundaram.h"
#include "Atkin.h"
#include "EratosthenesThreads.h"
#include <chrono>

using namespace std::chrono;

// Used to run algorithm methods and debug with print statements
int main()
{
	// Four limits being used in each alg test
	int n1 = 500000;
	int n2 = 1000000;
	int n3 = 500000000;
	int n4 = 1000000000;
	

	/* Testing Eratosthenes original implementation
	//ofstream results("EratBaseline.csv", ofstream::app);
	//Eratosthenes e(n1);
	//for (int i = 0; i < 10; i++)
	//{
	//	e.Setup();
	//	auto start = system_clock::now();
	//	e.Sieve();
	//	auto end = system_clock::now();
	//	auto total = end - start;
	//	results << duration_cast<nanoseconds>(total).count() << ", ";
	//}
	//results << endl;
	*/


	/* Testing Sundaram original implementation
	//ofstream results("SundBasline.csv", ofstream::app);
	//Sundaram s(n3);
	//results << endl;
	//for (int i = 0; i < 10; i++)
	//{
	//	s.Setup();
	//	auto start = system_clock::now();
	//	s.Sieve();
	//	auto end = system_clock::now();
	//	auto total = end - start;
	//	results << duration_cast<milliseconds>(total).count() << ", ";
	//}
	*/


	/* Testing Atkin original implementation
	//ofstream results("AtkinBasleine.csv", ofstream::app);
	//results << endl;
	//Atkin a(n2);
	//for (int i = 0; i < 10; i++)
	//{
	//	a.Setup();
	//	auto start = system_clock::now();
	//	a.Sieve();
	//	auto end = system_clock::now();
	//	auto total = end - start;
	//	results << duration_cast<milliseconds>(total).count() << ", ";	
	//}
	*/



	// Keep window open
	cout << "Finished work" << endl;
	getchar();
	return 0;
}