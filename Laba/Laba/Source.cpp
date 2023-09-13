#include <iostream>
#include <cstdlib>
#include "Header.h"

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "RUSSIAN");
	setlocale(LC_ALL, "ru");
	Fraction first(1, 3);
	Fraction sec(-88, 8);
	Fraction c;
	bool s;
	s = sec < first;
	//c = first--;
	first.Print();
	sec.Print();
	double a = c.Convert();
}