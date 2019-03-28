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


// Function Prototype for passing the ofstream
void print_stuff_to_two_places(ofstream &outfile, string msg);


int main() {

	string outfile_name;	// holders for file names

	ofstream outfile;		// the actual output file object


	// Prompt the user for the output file.
	cout << "Please enter the output file name: "; // prompt user
	cin >> outfile_name; // grab input
	cout << "User entered output file name as: " << outfile_name << endl; // debug


	// open the output file for writing.
	outfile.open(outfile_name.c_str());
	// Check if we successfully opened file.
	if (!outfile)
	{
		cout << "Error:  Unable to open file " << outfile_name << " for writing." << endl;
		cout << "Terminating Program.";
		return 1;
	}
	else
		cout << "Successfully opened the output file!!!  We must remember to close it before we finish." << endl;;


	print_stuff_to_two_places(outfile, "Hey There!!");

	outfile.close();	// Close any files we open
	cout << "DONE!!! WHEW!!!!";
	return 0;
}



