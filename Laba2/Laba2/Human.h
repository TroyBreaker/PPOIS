#pragma once
#include <string>
using namespace std;
/**
* @brief Class of Human (base class)
*/
class Human
{
private:
	string fio;
	int money;
public:
	string GetFIO()
	{
		return fio;
	}
	void SetFIO(string fio)
	{
		this->fio = fio;
	}
	int GetMoney()
	{
		return money;
	}
	void SetMoney(int money)
	{
		this->money = money;
	}
};