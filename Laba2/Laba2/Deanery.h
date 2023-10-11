#pragma once
#include "Deckan.h"
#include "Metodist.h"
#include "Department.h"
#include "Group.h"
#include "Accounting.h"
/**
* @brief Class of Deanery
*/
class Deanery {
private:
	string Faculty;
	Deckan* deckan;
	Metodist* metodist;
	Department* departments[5];
	Group* groups[10];
	Accounting* account;
	int NumberOfGrs;
	int NumberOfDep;
public:
	Deanery(Group* groups[], int NumberOfGrs, string Faculty, Deckan* deckan, Metodist* metodist, Accounting* account, Department* departments[], int NumberOfDep);
	Group* GetGroup(int NumberOfGroup);
	Department* GetDep(string name);
	int GetNumberOfGrs();
	Accounting* GetAccounting();
	void Transfer(string name, int NumOfCurGr, int NumOfWantedGr);
	void Signature(int NumOfGr);
	void DeaneryCheck(int Group, bool approveFromDeckan);
	void GiveDorm(int Group);
	void GiveSalary(string name, string NameOFDepartment);
	void GiveScholarship(string name, int NumberOfGroup);
	void TransferBudget(int Group, bool approveFromDeckan);
	void TeacherDegree(Teacher* tch, bool approveFromDeckan, string NewDegree);
	void SetScheduleForGroup(int schedule[], int Group);
	void SetScheduleForTeacher(int schedule[], string name, string dep);
	~Deanery();
};