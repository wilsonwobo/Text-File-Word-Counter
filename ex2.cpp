/*
 * ex2.cpp
 *
 *  Created on: 18 Nov 2017
 *      Author: Wilson Wobo
 */

using namespace std;

#include "ReadWords.h"
#include "FormBar.h"
#include <iostream>

/**
 * Main program to test the classes.
 * @param args - unused command line items.
 */

int main()
{
	cout << "Input the file, which contains the search words!" << '\n';
	string x;
	cin>>x;

	cout << "Input the file, which you wish to search!" << '\n';
	string y;
	cin>>y;

	ReadWords readSearch(x.c_str());
	ReadWords readWords(y.c_str());
	FormBar mapz(readWords, readSearch);

	int z;
	cin>>z;
}


