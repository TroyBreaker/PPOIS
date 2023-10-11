#pragma once
#include "Human.h"
#include "Record_Card.h"

class Deanery;
/**
* @brief Class of Student for Group (derived class)
*/
class Student :public Human
{
private:
	bool isHasBenefit;
	Record_Card* rc;
	bool isBudget;
	bool isHasDormitory;
	bool isHasReference;
public:
	Student() {}
	Student(bool isHasBenefit, Record_Card* rc, bool isBudget, bool isHasDormitory, bool isHasReference)
	{
		this->isHasBenefit = isHasBenefit;
		this->rc = rc;
		this->isBudget = isBudget;
		this->isHasDormitory = isHasDormitory;
		this->isHasReference = isHasReference;
	}
	void SetRef(bool isHasReference)
	{
		this->isHasReference = isHasReference;
	}
	Record_Card* GetRC()
	{
		return rc;
	}
	bool GetBenefit()
	{
		return isHasBenefit;
	}
	void SetDorm(bool isHasDormitory)
	{
		this->isHasDormitory = isHasDormitory;
	}
	bool GetBudget()
	{
		return isBudget;
	}
	void SetBudget(bool isBudget)
	{
		this->isBudget = isBudget;
	}

	void PayForDorm(Deanery* dean);
	void PayFee(Deanery* dean);
};