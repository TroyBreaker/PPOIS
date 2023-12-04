#pragma once
#include <iostream>
using namespace std;
/**
* @brief Class of Record (base class)
*/
class Record {
	double length;
	string name;
public:
	double GetLength()
	{
		return length;
	}
	string GetName()
	{
		return name;
	}
	Record(double length,string name)
	{
		this->length = length;
		this->name = name;
	}
	Record(){}
	virtual void GetInfo(string &line)
	{

	}
};