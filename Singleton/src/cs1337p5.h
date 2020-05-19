 //============================================================================
// Name        : cs1337p5.cpp
// Author      : Anthony Swink
// Version     :
// Copyright   : no taek
// Description : Header file for Logging program.
//============================================================================

#ifndef CS1337P5_H_
#define CS1337P5_H_
#include<fstream>

using namespace std;

enum LogType {						//enum for the two log types
    T_ScreenLogger, T_FileLogger
};

class CS1337Logger{					//Abstract Class, overwritten by ScreenLogger and FileLogger
private:
	bool loggingEnabled;

public:
	CS1337Logger();
	virtual ~CS1337Logger();
	void setLogger(bool);
	virtual void displayMessage(const char*) = 0;
	void logMessage(const char*);
};

class ScreenLogger: public CS1337Logger{	//Derived Class
private:

public:
	ScreenLogger();
	void displayMessage(const char*);
};


class FileLogger: public CS1337Logger{		//Derived Class
private:
	ofstream fout;
public:
	FileLogger();
	~FileLogger();

	void displayMessage(const char*);
};

class LogSingleton{							//Singleton Class used to create instances of the derived logging classes
private:
	LogSingleton();

public:
	static int LogCount;
	static CS1337Logger* GetLogger(LogType);

};



#endif /* CS1337P5_H_ */
