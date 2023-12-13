#pragma once
#include <iostream>
using namespace std;
/**
* @brief Class of Record (base class)
*/
class Record {
	//! length of record
	double length;
	//! name of record
	string name;
public:
	string GetName() const
	{
		return name;
	}
	Record(double length,string name)
	{
		this->length = length;
		this->name = name;
	}
	Record(){}
	virtual void GetInfo(string &line) const
	{

	}
};