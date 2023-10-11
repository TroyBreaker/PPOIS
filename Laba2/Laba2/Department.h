#pragma once
#include "Teacher.h"
/**
* @brief Class of Department for Deanery
*/
class Department
{
private:
	string name;
	Teacher* teachers[10];
	int NumberOfTeachers;
public:
	Department(int NumberOfTeachers, Teacher* teachers[], string name);
	string GetName();
	int GetNumberOfTeachers();
	Teacher* GetTeacher(int i);
	void Setname(string);
};
