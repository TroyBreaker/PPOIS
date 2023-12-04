#pragma once
#include "Student.h"
#include "Schedule.h"
/**
* @brief Class of Group for Deanery
*/
class Group
{
private:
	int NumberOfGroup;
	int course;
	int NumberOfStuds;
	Student* students[30];
	Schedule* schedule;
public:
	Group(int NumberOfStuds, int course, int Number_of_group, Student* students[5], Schedule* schedule);
	int GetNumberOfGroup();
	int GetNumberOfStuds();
	Student* GetStud(string name);
	Student* GetStud(int i);
	void SetStud(Student* st);
	void SetSchedule(Schedule* schedule);
	Schedule* GetSchedule();
	void DelStud(int i);
};