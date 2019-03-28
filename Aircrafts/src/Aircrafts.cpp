//=============================================================================================
// Name        : Aircrafts.cpp
// Author      : Anthony Swink
// Version     : 0.887
// Copyright   : Mine not yours
// Description : Holds the functions used for Aircraft program, holds functions from classes as
// 					well as two functions meant for formatting string inputs.
//=============================================================================================
#include <iostream>
#include <string>
#include <vector>
#include "Aircrafts.h"
using namespace std;


Aircraft::Aircraft(int engines, int seats){	//Constructor, always called when object (or derived class object) gets instantiated, keeps track of count.
	this -> engines = engines;
	this -> seats = seats;
	Aircraft::count++;
	}

Aircraft::~Aircraft(){						//Virtual destructor allowing RTTI, keeps track of count though it's not necessary
	Aircraft::count--;
}

Fighter::Fighter(int engines, int seats, string speed) : Aircraft(engines, seats){	//Derived class constructor
	this -> engines = engines;
	this -> seats = seats;
	this -> speed = speed;
}

Acrobat::Acrobat(string name, string description) : Aircraft(0,0){					//Derived class constructor
	this -> name = name;
	this -> description = description;
}

Freight::Freight(int engines, string company, string capacity) : Aircraft(engines, 0){	//Derived class constructor
	this -> engines = engines;
	this -> company = company;
	this -> capacity = capacity;
}

int Aircraft::getCount(){										//Used to access the private count variable
	return count;
}

void Aircraft::printCharacteristics(){							//Parent print function
	cout << "Aircraft info: " << endl;
	cout << "Engines: " << engines << endl;
	cout << "Seats: " << seats << endl << endl;
}
void Fighter::printCharacteristics(){							//Derived print function
	cout << "Fighter info: " << endl;
	cout << "Engines: " << engines << endl;
	cout << "Seats: " << seats << endl;
	cout << "Speed: " << speed <<endl << endl;
}
void Acrobat::printCharacteristics(){							//Derived print function
	cout << "Acrobat info: " << endl;
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl << endl;
}
void Freight::printCharacteristics(){							//Derived print function
	cout << "Freight info: " << endl;
	cout << "Engines: " << engines << endl;
	cout << "Company: " << company << endl;
	cout << "Capacity: " << capacity << endl << endl;
}

int twoString(string &full, string &empty){					//Function to separate two strings
	int betweenStr = full.find("\", \"");	//Finds the place to separate
	if(full.find("\", \"") == string::npos){
			full = empty = "Strings were formatted incorrectly. Make sure they are quoted and there's a comma then space between them.";
			return 1;
		}
	empty = full.substr(betweenStr+4, full.size()-(betweenStr + 1)); //Assigns second string to second string variable
	full.resize(betweenStr);		//Formats first string
	full.erase(0,2);				//^^^^^^^^^^^^^^^^^^^^
	empty.erase(empty.size() -1, 1);//Format second string
	return 0;
}

void oneString(string &quoted){		//Formats string for aircrafts with one string variable
	quoted.erase(quoted.size() - 1, 1);
	quoted.erase(0,2);
}

void checkComma(char &comma, int i){
	if(comma != ','){
		cout << "You have a formatting issue related to commas on line " << i << "." << endl;
	}
}
