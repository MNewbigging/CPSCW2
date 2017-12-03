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

	// REMEMBER - USE SIEVE 3 for Eratosthenes Threads!!!

	

	// Keep window open
	cout << "Finished work" << endl;
	getchar();
	return 0;
}