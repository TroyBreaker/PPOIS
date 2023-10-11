#pragma once
#include "Human.h"
/**
* @brief Class of Deckan for Deanery (derived class)
*/
class Deckan :public Human
{
private:
	bool approval;
public:
	bool GetApprovalFromDeckan8()
	{
		return approval;
	}
	void SetApproval(bool approval)
	{
		this->approval = approval;
	}
};