//============================================================================
// Name        : cs1337p5.cpp
// Author      : Anthony Swink
// Version     :
// Copyright   : no taek
// Description : Driver file to implement logging program.
//============================================================================

#include <iostream>
#include "cs1337p5.h"

using namespace std;

int LogSingleton::LogCount;

int main(){
	LogSingleton::LogCount = 0;	//Set LogCount to 0, CS1337Logger constructor will increment it when called.
	CS1337Logger* log = LogSingleton::GetLogger(T_FileLogger); //Choose which log type, simple choose T_ScreenLogger to log to screen or T_FileLogger to log to output file.	  (Not required in program but I wanted to allow the log type to be chosen dynamically and Prof. Perkins said it was okay.
	log->setLogger(true);	//enable logging
	log->logMessage("Display screen message\n");	//log
	log->logMessage("wat");
	log->setLogger(false);	///diable logging
	log->logMessage("logging is disabled, this won't be logged.");	//won't log
	log->setLogger(true);	//re-enable
	log->logMessage("SAHHHHHH.");	//log
	delete log;	//delete the log object
	//Can't make any more instances, as intended for the singleton design pattern.

	return 0;
}

