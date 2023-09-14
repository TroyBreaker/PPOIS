#include "Haeder.h"

int NOD(int a, int b)
{
	if (b % a == 0)
		return a;
	else return NOD(b % a, a);
}

int NOK(int n1, int n2)
{
	return n1 * n2 / NOD(n1, n2);
}

void Fraction::Check(Fraction& frac)
{
	int num = frac.GetNum();
	int denom = frac.GetDenom();
	if (num != 0)
	{
		int nod = NOD(abs(num), denom);
		num /= nod;
		denom /= nod;
	}
	frac.SetDenom(denom);
	frac.SetNum(num);
}

double Fraction::Convert()
{
	return num * 1. / denom;
}