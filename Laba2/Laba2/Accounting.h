#pragma once
/**
* @brief Class of Accounting for Deanery
*/
class Accounting
{
private:
	int feeForDorm;
	int feeForStudy;
	int scholarship;
	int salary;
	int budget;
public:
	int GetfeeForDorm();
	int Getsalary();
	int GetScholarship();
	void SetBubget(int budget);
	int GetBubget();
	int GetfeeForStudy();
	Accounting(int feeForDorm, int feeForStudy, int scholarship, int salary, int budget)
	{
		this->feeForDorm = feeForDorm;
		this->salary = salary;
		this->feeForStudy = feeForStudy;
		this->scholarship = scholarship;
		this->budget = budget;
	}
};