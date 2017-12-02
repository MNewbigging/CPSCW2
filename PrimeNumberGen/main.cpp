#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <omp.h>

#include "Eratosthenes.h"
#include "Sundaram.h"
#include "Atkin.h"
#include "EratosthenesThreads.h"
#include "SundaramThreads.h"
#include "AtkinThreads.h"
#include "EratosthenesOpenMP.h"
#include "SundaramOpenMP.h"
#include "AtkinOpenMP.h"



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


	// Sundaram threads are definitely ok
	// Atkin and erat not so (at hardware concurrency, at 2 threads they're ok)
	EratosthenesThreads e(n1);
	e.Setup();
	e.Sieve3();
	e.GatherResults();

	// Erat and Sundaram OMP looks ok - check at 1 billion
	// Atkin definitely isn't ok

	

	// Keep window open
	cout << "Finished work" << endl;
	getchar();
	return 0;
}