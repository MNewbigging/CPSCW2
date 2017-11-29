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
	// Limit
	int n = 1000000;

	//Eratosthenes e(n);
	//e.Setup();
	//auto start = system_clock::now();
	//e.Sieve();
	//auto end = system_clock::now();
	//auto total = end - start;
	//cout << "Time " << duration_cast<milliseconds>(total).count() << endl;

	EratosthenesThreads e(n);
	e.Setup();
	auto start = system_clock::now();
	e.Sieve();
	auto end = system_clock::now();
	auto total = end - start;
	cout << "Time " << duration_cast<milliseconds>(total).count() << endl;
	e.GatherResults();


	// Create sundaram sieve
	//cout << "Sund started" << endl;
	//Sundaram sund(n);
	//sund.Setup();
	//sund.Sieve();
	////sund.GatherResults();
	//cout << "Sund done" << endl;
	//for (auto &i : sund.result)
	//	cout << i << endl;

	// Create atkin sieve
	//cout << "Atkin started" << endl;
	//Atkin a(n);
	//a.Setup();
	//a.Sieve();
	//a.GatherResults();
	//cout << "Atkin done" << endl;

	// Keep window open
	getchar();
	return 0;
}