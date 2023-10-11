#pragma once
/**
* @brief Class of Schedule for Group and Teacher
*/
class Schedule
{
private:
	int schedule[7];
public:
	void SetSchedule(int schedule[])
	{
		for (int i = 0; i < 7; i++)
			this->schedule[i] = schedule[i];
	}
	Schedule() {}
};