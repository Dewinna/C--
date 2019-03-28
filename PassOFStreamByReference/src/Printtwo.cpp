//============================================================================
// Name        : PassOFStreamByReference
// Author      : Stephen Perkins
// Version     : 1.0
// Copyright   : Uhhh... yeah... its mine.
// Description :
//
//		Shows how to pass an OFStream as a function parameter
//
//============================================================================



#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print_stuff_to_two_places(ofstream &outfile, string msg)
{
	cout << msg << endl;
	outfile << msg << endl;
	return;
}
