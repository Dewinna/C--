//=============================================================================================
// Name        : AircraftPilot.cpp   	 (Get it?) (like...) (driver...)
// Author      : Anthony Swink
// Version     : 0.887
// Copyright   : Mine not yours
// Description : Driver (or Pilot) file for aircraft program. Opens the input file,
//         reads then handles the commands by passing them to the correct functions/classes
//=============================================================================================



#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Aircrafts.h"
using namespace std;

int Aircraft::count = 0;	//Declare static variable in ONE implementation file
int i = 1;					//Keeps track of while loop

int twoString(string &full, string &empty);	//Declare functions that aren't member functions of classes in the .h file
void oneString(string &quoted);
void checkComma(char &comma, int i);

int main() {
	fstream fin;					//Input file variable
	vector<Aircraft*> aircraft;		//Create vector of pointers to type Aircraft

	fin.open("Aircrafts.txt");      //open file to access information
	if(!fin){
		cout << "Error Opening file. Exiting program." << endl;
	}
	while (true){   			//Read in info until end of file

		char command = 'f'; 	//Set to invalid character handling if loop runs one time too many
		int type;		//Lot's of variable declarations to hold onto info to be passed to objects
		int seats;
		int engines;
		char comma;		//Used to pass commas in input file
		string speed;
		string name;
		string description;
		string company;
		string capacity;
		string invalid;
		fin >> command;

		if(fin.eof()){		//Check if end of file and break if so
					break;
				}

		if(command == 'n'){	//If commanded to create new plane
			fin >> type;
			if(type == 0){	//type Aircraft
				fin >> comma;
				checkComma(comma, i);
				fin >> engines;						//(Reading in info)
				fin >> comma;
				checkComma(comma, i);
				fin >> seats;
				Aircraft *temp = new Aircraft(engines, seats);	//Passes info to new object
				aircraft.push_back (temp);
			}else if(type == 1){	//type Fighter
				fin >> comma;
				checkComma(comma, i);
				fin >> engines;
				fin >> comma;
				checkComma(comma, i);
				fin >> seats;
				fin >> comma;
				checkComma(comma, i);
				getline(fin, speed);
				oneString(speed);	//Format string input
				Fighter *temp = new Fighter(engines, seats, speed);  //Passes info to new object
				aircraft.push_back(temp);
			}else if(type == 2){	//type Acrobat
				fin >> comma;
				checkComma(comma, i);
				getline(fin, name);
				description = "";
				if(twoString(name, description) != 0){	//Assign and format strings, also checks that strings were formatted correctly
					cout << "Strings in line " << i << " were formatted incorrectly. Make sure they are quoted and there's a comma then space between them." << endl;
				}
				Acrobat *temp = new Acrobat(name, description); //Passes info to new object
				aircraft.push_back(temp);
			}else if(type == 3){		//type Freight
				fin >> comma;
				checkComma(comma, i);
				fin >> engines;
				fin >> comma;
				checkComma(comma, i);
				getline(fin, company);
				capacity = "";
				if(twoString(company, capacity) != 0){	//Assign and format strings, also checks that strings were formatted correctly
					cout << "Strings in line " << i << " were formatted incorrectly. Make sure they are quoted and there's a comma then space between them." << endl;
				}
				Freight *temp = new Freight(engines, company, capacity);	//Passes info to new object
				aircraft.push_back(temp);
			}

		}else if(command == 'p'){		//Print command
			fin >> type;
			if(type == 0){	//type Aircraft
				for (int i = 0; i < Aircraft::getCount(); i++){	//Finds all Aircraft objects and calls print functions for each
					if(!(aircraft[i]->instanceof<Fighter>(aircraft[i])||aircraft[i]->instanceof<Acrobat>(aircraft[i])||aircraft[i]->instanceof<Freight>(aircraft[i]))){
						aircraft[i]->printCharacteristics();
					}
				}
			}else if (type == 1){	//type Fighter
				for (int i = 0; i < Aircraft::getCount(); i++){	//Finds all Fighter objects and calls print functions for each
					if(aircraft[i]->instanceof<Fighter>(aircraft[i])){
						aircraft[i]->printCharacteristics();
					}
				}
			}else if (type == 2){ 	//type Acrobat
				for (int i = 0; i < Aircraft::getCount(); i++){	//Finds all Acrobat objects and calls print functions for each
					if(aircraft[i]->instanceof<Acrobat>(aircraft[i])){
						aircraft[i]->printCharacteristics();
					}
				}
			}else if (type == 3){	//type Freight
				for (int i = 0; i < Aircraft::getCount(); i++){	//Finds all Freight objects and calls print functions for each
					if(aircraft[i]->instanceof<Freight>(aircraft[i])){
						aircraft[i]->printCharacteristics();
					}
				}
			}
		}else{
			cout << "Invalid command on line " << i << " checking for new command..." << endl;
			getline(fin, invalid);												//Passes rest of line to invalid holder in order to skip to the next line for a proper command
		}
	i++;

	}
	fin.close( );	//Close input file
	return 0;
}
