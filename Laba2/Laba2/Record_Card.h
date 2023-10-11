#pragma once
/**
* @brief Class of Record card for Student
*/
class Record_Card
{
private:
	int marks_for_exam[5];
	bool signature;
public:
	Record_Card(int marks[], bool s) {
		signature = s;
		for (int i = 0; i < 5; i++)
			marks_for_exam[i] = marks[i];
	}
	void SetSign(bool signature)
	{
		this->signature = signature;
	}
	int GetMark(int i)
	{
		return marks_for_exam[i];
	}
};