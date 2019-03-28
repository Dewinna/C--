//=============================================================================================
// Name        : Aircrafts.h
// Author      : Anthony Swink
// Version     : 0.887
// Copyright   : Mine not yours
// Description : Header file for aircraft program, declares Aircraft class as well as three
//				children classes
//=============================================================================================


#ifndef AIRCRAFTS_H_
#define AIRCRAFTS_H_
#include <string>
using namespace std;

class Aircraft{				//Parent class
private:
	int engines;			//Private variables
	int seats;
	static int count;
public:
	Aircraft(int, int);		//Constructor
	virtual ~Aircraft();	//Virtual Destructor
	static int getCount();	//Keeps track of # of aircraft (or derived) objects created
	virtual void printCharacteristics();	//Print function meant to be overriden by children classes
	template<typename Base, typename T>		//Dynamic type checking from elearning, defining it in the Aircrafts.cpp file led to an error that only got fixed when moving it hear and removing "inline"
	bool instanceof(const T *ptr) {
			return dynamic_cast<const Base*>(ptr) != nullptr;
		}

};

class Fighter: public Aircraft{	//Derived class w/ constructor and overridden printCharacteristics function
private:
	int engines;
	int seats;
	string speed;
public:
	Fighter(int, int, string);
	void printCharacteristics();

};
class Acrobat: public Aircraft{	//Derived class w/ constructor and overridden printCharacteristics function
private:
	string name;
	string description;
public:
	Acrobat(string, string);
	void printCharacteristics();
};
class Freight: public Aircraft{	//Derived class w/ constructor and overridden printCharacteristics function
private:
	int engines;
	string company;
	string capacity;
public:
	Freight(int, string, string);
	void printCharacteristics();
};

#endif /* AIRCRAFTS_H_ */

