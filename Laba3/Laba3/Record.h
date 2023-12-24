#pragma once
#include <iostream>
using namespace std;
/**
* @brief Class of Record (base class)
*/
class Record {
	//! length of record
	double const length;
	//! name of record
	string const name;
public:
	string GetName() const
	{
		return name;
	}
	Record(double length, string name) : length(length), name(name) {};
	virtual void GetInfo(string &line) const {}
};