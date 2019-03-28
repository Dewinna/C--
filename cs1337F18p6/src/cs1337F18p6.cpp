//============================================================================
// Name        : cs1337F18p6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class AbstractObserver
{
public:
	virtual void subjectChanged(string)=0;
	virtual ~AbstractObserver(){}
};
