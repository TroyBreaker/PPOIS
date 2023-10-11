#include "Deanery.h"

int Group::GetNumber_of_group()
{
	return Number_of_group;
}

int Group::GetNumberOfStuds()
{
	return NumberOfStuds;
}

Group::Group(int NumberOfStuds, int course, int Number_of_group, Student* students[5], Schedule* schedule)
{
	for (int i = 0; i < NumberOfStuds; i++)
		this->students[i] = students[i];
	this->NumberOfStuds = NumberOfStuds;
	this->course = course;
	this->Number_of_group = Number_of_group;
	this->schedule = schedule;
}

int Accounting::GetfeeForDorm()
{
	return feeForDorm;
}
void Accounting::SetBubget(int budget)
{
	this->budget = budget;
}
int Accounting::GetBubget()
{
	return budget;
}
int Accounting::Getsalary() {
	return salary;
}
int Accounting::GetScholarship()
{
	return scholarship;
}

int Accounting::GetfeeForStudy()
{
	return feeForDorm;
}

int Deanery::GetNumberOfGrs()
{
	return NumberOfGrs;
}

Group* Deanery::GetGroup(int NumberOfGroup)
{
	for (int i = 0; i < NumberOfGrs; i++)
	{
		if (groups[i]->GetNumber_of_group() == NumberOfGroup)
			return groups[i];
	}
}

Department* Deanery::GetDep(string name)
{
	for (int i = 0; i < NumberOfGrs; i++)
	{
		if (departments[i]->GetName() == name)
			return departments[i];
	}
}

Accounting* Deanery::GetAccounting()
{
	return account;
}

Deanery::Deanery(Group* groups[], int NumberOfGrs, string Faculty, Deckan* deckan, Metodist* metodist,Accounting*account, Department* departments[], int NumberOfDep)
{
	this->Faculty = Faculty;
	this->NumberOfGrs = NumberOfGrs;
	this->deckan = deckan;
	this->metodist = metodist;
	this->account = account;
	for (int i = 0; i < NumberOfDep; i++)
	{
		this->departments[i] = departments[i];
	}
	this->NumberOfDep = NumberOfDep;
	for (int i = 0; i < NumberOfGrs; i++)
	{
		this->groups[i] = groups[i];
	}
}

Deanery::~Deanery()
{
	for (int i = 0; i < NumberOfGrs; i++)
	{
		delete groups[i]->GetSchedule();
		for (int j = 0; j < groups[i]->GetNumberOfStuds(); j++)
		{
			delete groups[i]->GetStud(j)->GetRC();
			delete groups[i]->GetStud(j);
		}
	}
	for (int i = 0; i < NumberOfDep; i++)
		for (int j = 0; j < departments[i]->GetNumberOfTeachers(); j++)
		{
			delete departments[i]->GetTeacher(j)->GetSchedule();
			delete departments[i]->GetTeacher(j);
		}
	for (int i = 0; i < NumberOfGrs; i++)
		delete groups[i];
	for (int i = 0; i < NumberOfDep; i++)
		delete departments[i];
}

Department::Department(int NumberOfTeachers, Teacher* teachers[], string name)
{
	for (int i = 0; i < NumberOfTeachers; i++)
	{
		this->teachers[i] = teachers[i];
	}
	this->NumberOfTeachers = NumberOfTeachers;
	this->name = name;
}
string Department::GetName()
{
	return name;
}
void Department::Setname(string name)
{
	this->name = name;
}
int Department::GetNumberOfTeachers()
{
	return NumberOfTeachers;
}
Teacher* Department::GetTeacher(int i)
{
	return teachers[i];
}

/**
	* @brief Method that transfer student from current group to wanted group
	* @param name of student
	* @param student's current group
	* @param number of wanted group
	*/
void Deanery::Transfer(string name, int NumOfCurGr, int NumOfWantedGr)
{
	for (int cur = 0; cur < NumberOfGrs; cur++)

		if (NumOfCurGr == groups[cur]->GetNumber_of_group())

			for (int NumOfStud = 0; NumOfStud < groups[cur]->GetNumberOfStuds(); NumOfStud++)

				if (groups[cur]->GetStud(NumOfStud)->GetFIO() == name)

					for (int want = 0; want < NumOfWantedGr; want++)

						if (NumOfWantedGr == groups[want]->GetNumber_of_group())
						{
							groups[want]->SetStud(groups[cur]->GetStud(NumOfStud));
							groups[cur]->DelStud(NumOfStud);
							return;
						}
}

/**
	* @brief Method that delete student from group
	* @param number of element in massive of students in group
	*/

void Group::DelStud(int i)
{
	for (int j = i; j - 1 < NumberOfStuds; j++)
		students[j] = students[j + 1];
	NumberOfStuds--;
}

Student* Group::GetStud(string name)
{
	for (int i = 0; i < NumberOfStuds; i++)
	{
		if (students[i]->GetFIO() == name)
			return students[i];
	}
}
Student* Group::GetStud(int i)
{
	return students[i];
}

void Group::SetStud(Student* st)
{
	this->students[NumberOfStuds] = st;
	NumberOfStuds++;
}
void Group::SetSchedule(Schedule* schedule)
{
	this->schedule = schedule;
}
Schedule* Group::GetSchedule()
{
	return schedule;
}

/**
	* @brief Method that puts signature in the students' record cards
	* @param number of group
	*/

void Deanery::Signature(int NumOfGr)
{
	for (int c = 0; c < NumOfGr; c++)
	{
		if (NumOfGr == groups[c]->GetNumber_of_group())
		{
			for (int j = 0; j < groups[c]->GetNumberOfStuds(); j++)
			{
				groups[c]->GetStud(j)->GetRC()->SetSign(true);
			}
			return;
		}
	}
}
/**
	* @brief Method of class Metodist that give reference to student
	* @param student
	*/
void Metodist::GiveRef(Student* st)
{
	st->SetRef(true);
}

/**
	* @brief Method that checks grade of student and delete student if he has bad marks in case if Deckan has agreed to expel the student
	* @param number of group
	* @param approval from Deckan
	*/
void  Deanery::DeaneryCheck(int Group, bool approveFromDeckan)
{
	deckan->SetApproval(approveFromDeckan);
	if (deckan->GetApprovalFromDeckan8())
		for (int i = 0; i < NumberOfGrs; i++)
			if (Group == groups[i]->GetNumber_of_group())
				for (int j = 0; j < groups[i]->GetNumberOfStuds(); j++)
				{
					int BadMarks = 0;
					for (int k = 0; k < 5; k++)
						if (groups[i]->GetStud(j)->GetRC()->GetMark(k) < 4) BadMarks++;
					if (BadMarks > 1)
					{
						delete groups[i]->GetStud(j);
						groups[i]->DelStud(j);
					}
				}
}

/**
	* @brief Method that give dormitory to student if he has Benefit
	* @param number of group
	*/
void Deanery::GiveDorm(int Group)
{
	for (int i = 0; i < NumberOfGrs; i++)
		if (Group == groups[i]->GetNumber_of_group())
			for (int j = 0; j < groups[i]->GetNumberOfStuds(); j++)
				if (groups[i]->GetStud(j)->GetBenefit() == 1)
					groups[i]->GetStud(j)->SetDorm(1); 

}
/**
	* @brief Method of class Student that pay fo Dormitory if has dormitory
	* @param Deanery to which student belongs
	*/
void Student::PayForDorm(Deanery* dean)
{
	if (isHasDormitory)
	{
		this->SetMoney(this->GetMoney() - dean->GetAccounting()->GetfeeForDorm());
		dean->GetAccounting()->SetBubget(dean->GetAccounting()->GetBubget() + dean->GetAccounting()->GetfeeForDorm());
	}
}
/**
	* @brief Method that give salary to teacher
	* @param name of teacher
	* @param name of Department to which teacher belongs
	*/
void Deanery::GiveSalary(string name, string NameOFDepartment)
{
	for (int i = 0; i < NumberOfDep; i++)
		if (departments[i]->GetName() == NameOFDepartment)
			for (int j = 0; j < departments[i]->GetNumberOfTeachers(); j++)
				if (name == departments[i]->GetTeacher(j)->GetFIO()) {
					departments[i]->GetTeacher(j)->SetMoney(departments[i]->GetTeacher(j)->GetMoney() + account->Getsalary());
					account->SetBubget(account->GetBubget() - account->Getsalary());
				}
}
/**
	* @brief Method that give scholarship to student if he is budget
	* @param name of student
	* @param number of group to which student belongs
	*/
void Deanery::GiveScholarship(string name, int NumberOfGroup)
{
	for (int i = 0; i < NumberOfGrs; i++)

		if (NumberOfGroup == groups[i]->GetNumber_of_group())

			for (int NumOfStud = 0; NumOfStud < groups[i]->GetNumberOfStuds(); NumOfStud++)

				if (groups[i]->GetStud(NumOfStud)->GetFIO() == name)

					if (groups[i]->GetStud(NumOfStud)->GetBudget())
					{
						groups[i]->GetStud(NumOfStud)->SetMoney(groups[i]->GetStud(NumOfStud)->GetMoney() + account->GetScholarship());
						account->SetBubget(account->GetBubget() - account->GetScholarship());
					}
}
/**
	* @brief Method of class Student that pay fee for study if not budget
	* @param Deanery to which student belongs
	*/
void Student::PayFee(Deanery* dean)
{
	if (!isBudget)
	{
		this->SetMoney(this->GetMoney() - dean->GetAccounting()->GetfeeForStudy());
		dean->GetAccounting()->SetBubget(dean->GetAccounting()->GetBubget() + dean->GetAccounting()->GetfeeForStudy());
	}
}
/**
	* @brief Method that tranfer student who is not budget to budget is he has good marks is Deckan has agreed to transfer student
	* @param number of group
	* @param approval from Deckan
	*/
void Deanery::TransferBudget(int Group, bool approveFromDeckan)
{
	deckan->SetApproval(approveFromDeckan);
	if (deckan->GetApprovalFromDeckan8())
		for (int i = 0; i < NumberOfGrs; i++)
			if (Group == groups[i]->GetNumber_of_group())
				for (int j = 0; j < groups[i]->GetNumberOfStuds(); j++)
				{
					int Average = 0;
					for (int k = 0; k < 5; k++)
						Average = groups[i]->GetStud(j)->GetRC()->GetMark(k) / 5;
					if (Average > 8)
					{
						groups[i]->GetStud(j)->SetBudget(1);
					}
				}
}
/**
	* @brief Method that assign new degree to teacher is Deckan has agreed assignment
	* @param teacher
	* @param approval from Deckan
	* @param name of new degree
	*/
void Deanery::TeacherDegree(Teacher* tch, bool approveFromDeckan, string NewDegree)
{
	if (approveFromDeckan)
		tch->SetDegree(NewDegree);
}
/**
	* @brief Method that set new schedule for Group
	* @param schedule
	* @param number of group
	*/
void Deanery::SetScheduleForGroup(int schedule[], int Group)
{
	for (int i = 0; i < NumberOfGrs; i++)
		if (Group == groups[i]->GetNumber_of_group())
			groups[i]->GetSchedule()->SetSchedule(schedule);
}
/**
	* @brief Method that set new schedule for Teacher
	* @param schedule
	* @param name of teacher
	* @param name of Department to which teacher belongs
	*/
void Deanery::SetScheduleForTeacher(int schedule[], string name, string dep)
{
	for (int i = 0; i < NumberOfDep; i++)
		if (departments[i]->GetName() == dep)
			for (int j = 0; j < departments[i]->GetNumberOfTeachers(); j++)
				if (name == departments[i]->GetTeacher(j)->GetFIO()) {
					departments[i]->GetTeacher(j)->GetSchedule()->SetSchedule(schedule);
					return;
				}
}