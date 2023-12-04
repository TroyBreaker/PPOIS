#pragma once
#include "Human.h"
#include "Schedule.h"
/**
* @brief Class of Teacher for Department (derived class)
*/
class Teacher : public Human
{
private:
	string degree;
	Schedule* schedule;
public:
	Teacher(string degree, Schedule* schedule)
	{
		this->degree = degree;
		this->schedule = schedule;
	}
	string GetDegree()
	{
		return degree;
	}
	Schedule* GetSchedule()
	{
		return schedule;
	}
	void SetDegree(string degree)
	{
		this->degree = degree;
	}
	void SetSchedule(Schedule* schedule)
	{
		this->schedule = schedule;
	}
};