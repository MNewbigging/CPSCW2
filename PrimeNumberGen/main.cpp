#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Eratosthenes.h"
#include "Sundaram.h"
#include "Atkin.h"
#include "EratosthenesThreads.h"
#include "SundaramThreads.h"
#include "EratosthenesOpenMP.h"
#include "AtkinOpenMP.h"
#include "SundaramOpenMP.h"
#include <chrono>

//#include <string>

using namespace std::chrono;

// Used to run algorithm methods and debug with print statements
int main()
{
	// Four limits being used in each alg test
	int n1 = 500000; // half mil
	int n2 = 1000000; // million
	int n3 = 500000000; // half bil
	int n4 = 1000000000; // billion


	Eratosthenes e(n1);
	e.Setup();
	e.Sieve();
	e.GatherResults();

	Sundaram s(n1);
	s.Setup();
	s.Sieve();
	s.GatherResults();

	Atkin a(n1);
	a.Setup();
	a.Sieve();
	a.GatherResults();
















	//EratosthenesOpenMP e2(n1);
	//e2.Setup();
	//auto start2 = system_clock::now();
	//e2.Sieve();
	//auto end2 = system_clock::now();
	//auto total2 = end2 - start2;
	//cout << duration_cast<nanoseconds>(total2).count() << endl;
	//e2.GatherResults();

	//ofstream results("EratThrds.csv", ofstream::app);
	//EratosthenesThreads e3(n1);
	//for (int i = 0; i < 10; i++)
	//{
	//	e3.Setup();
	//	auto start3 = system_clock::now();
	//	e3.Sieve3();
	//	auto end3 = system_clock::now();
	//	auto total3 = end3 - start3;
	//	results << duration_cast<nanoseconds>(total3).count() << endl;
	//}
	

	

	
	

	// Read in known primes list for comparison
	//ifstream check("First168Primes.txt");
	//vector<string> lines;

	//while (check.eof())
	//{
	//	string line;
	//	getline(check, line);
	//	lines.push_back(line);
	//}
	//
	//cout << (int)lines.size() << endl;



	/* Testing Sundaram OpenMP implementation
	ofstream results("SundOMP.csv", ofstream::app);
	SundaramOpenMP s(n4);
	for (int i = 0; i < 10; i++)
	{
		s.Setup();
		auto start = system_clock::now();
		s.Sieve();
		auto end = system_clock::now();
		auto total = end - start;
		results << duration_cast<milliseconds>(total).count() << ", ";
	}
	results << endl; */


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