//============================================================================
// Name        : cs1337p5.cpp
// Author      : Anthony Swink
// Version     :
// Copyright   : no taek
// Description : Functions for Logging program.
//============================================================================

#include <iostream>
#include <fstream>
#include "cs1337p5.h"

using namespace std;


CS1337Logger::CS1337Logger(){		//Constructor for CS1337Logger, called before constructing an instance of a derived class
	bool set = false;
	setLogger(set);
	LogSingleton::LogCount++;
}

CS1337Logger::~CS1337Logger(){		//Virtual destructor allowing dynamic destruction
	LogSingleton::LogCount--;
}

FileLogger::FileLogger(){			//Constructor for File logging derived class, opens output file.
	fout.open ("Log.txt");
}

ScreenLogger::ScreenLogger(){		//Constructor for Screen logging derived class.

}

FileLogger::~FileLogger(){			//Destructor for file logging used to close the output file.
	fout.close();
}

void CS1337Logger::setLogger(bool set){		//setLogger method to enable/disable logging
	loggingEnabled = set;
}

void CS1337Logger::logMessage(const char* message){	//sends signal to display message, displays to file if being called by FileLogger or to screen if called by ScreenLogger
	if(loggingEnabled == true){
		displayMessage(message);
	}
}

void ScreenLogger::displayMessage(const char* message){	//ScreenLogger handling display message
	cout << message << endl;
}

void FileLogger::displayMessage(const char* message){	//FileLogger handling display message
	fout << message <<endl;

}

CS1337Logger* LogSingleton::GetLogger(LogType type){	//Method from LogSingleton used to create object for Screen or File Logger.
	if(LogSingleton::LogCount == 0){
		if(type == T_ScreenLogger){
			CS1337Logger* singleton = new ScreenLogger;
			return singleton;
		}else if(type == T_FileLogger){
			CS1337Logger* singleton = new FileLogger;
			return singleton;
		}else{
			return NULL;
		}
	}else return NULL;

}





