//#include <iostream>
//using namespace std;
//
//int NOD(int a, int b)
//{
//	if (b % a == 0)
//		return a;
//	else return NOD(b % a, a);
//}
//
//int NOK(int n1, int n2)
//{
//	return n1 * n2 / NOD(n1, n2);
//}
//class Fraction;
//void Check(Fraction&);
//
//class Fraction {
//private:
//	int integer;
//	int num;
//	int denom;
//public:
//	Fraction(int integer, int num, int denom)
//	{
//		if (denom < 0 || num < 0)
//		{
//			cout << "Числитель и знаменатель взяты по модулю." << endl;
//			num = fabs(num);
//			denom = fabs(denom);
//		}
//		if (denom == 0)
//		{
//			cout << "Знаменатель не может быть равен нулю! Знаменатель заменён на 1." << endl;
//			denom = 1;
//		}
//
//		if (num != 0)
//		{
//			int nod = NOD(num, denom);
//			num /= nod;
//			denom /= nod;
//		}
//		if (num >= denom)
//		{
//			int extra_int = num / denom;
//			integer += extra_int;
//			num = num - extra_int * denom;
//		}
//		this->integer = integer;
//		this->num = num;
//		this->denom = denom;
//	}
//
//	Fraction()
//	{}
//
//	void Print()
//	{
//		cout << "Дробь " << this << " " << integer << " " << num << "/" << denom << endl;
//	}
//
//	int GetInt()
//	{
//		return integer;
//	}
//	int GetNum()
//	{
//		return num;
//	}
//	int GetDenom()
//	{
//		return denom;
//	}
//	void SetInt(int integer)
//	{
//		this->integer = integer;
//	}
//	void SetNum(int num)
//	{
//		this->num = num;
//	}
//	void SetDenom(int denom)
//	{
//		this->denom = denom;
//	}
//
//	void operator =(const Fraction& other)
//	{
//		this->denom = other.denom;
//		this->num = other.num;
//		this->integer = other.integer;
//	}
//
//	Fraction operator+(int digit)
//	{
//		Fraction temp;
//		temp.integer = this->integer + digit;
//		temp.denom = this->denom;
//		temp.num = this->num;
//		return temp;
//	}
//
//	void operator +=(int digit)
//	{
//		Fraction temp;
//		temp.integer = this->integer + digit;
//		temp.denom = this->denom;
//		temp.num = this->num;
//		*this = temp;
//	}
//
//	Fraction operator +(Fraction& other)
//	{
//		Fraction temp;
//		int nok = NOK(this->denom, other.denom);
//		int firstQuo = nok / this->denom;
//		int secQuo = nok / other.denom;
//		this->num *= firstQuo;
//		this->denom *= firstQuo;
//		other.num *= secQuo;
//		other.denom *= secQuo;
//		temp.integer = this->integer + other.integer;
//		temp.num = this->num + other.num;
//		temp.denom = this->denom;
//		Check(*this);
//		Check(other);
//		Check(temp);
//		return temp;
//	}
//
//	void operator +=(Fraction& other)
//	{
//		Fraction temp;
//		int nok = NOK(this->denom, other.denom);
//		int firstQuo = nok / this->denom;
//		int secQuo = nok / other.denom;
//		this->num *= firstQuo;
//		this->denom *= firstQuo;
//		other.num *= secQuo;
//		other.denom *= secQuo;
//		temp.integer = this->integer + other.integer;
//		temp.num = this->num + other.num;
//		temp.denom = this->denom;
//		Check(*this);
//		Check(other);
//		Check(temp);
//		*this= temp;
//		// cout << &temp.denom << " " << &(this->denom) << endl;
//	}
//
//	Fraction operator -(Fraction& other)
//	{
//		Fraction temp;
//		int nok = NOK(this->denom, other.denom);
//		int firstQuo = nok / this->denom;
//		int secQuo = nok / other.denom;
//		this->num *= firstQuo;
//		this->denom *= firstQuo;
//		other.num *= secQuo;
//		other.denom *= secQuo;
//		temp.integer = this->integer - other.integer;
//		temp.num = this->num - other.num;
//		temp.denom = this->denom;
//		Check(*this);
//		Check(other);
//		Check(temp);
//		return temp;
//	}
//};
//
//void Check(Fraction& frac)
//{
//	int num = frac.GetNum();
//	int denom = frac.GetDenom();
//	int integer = frac.GetInt();
//	if (num != 0)
//	{
//		int nod = NOD(num, denom);
//		num /= nod;
//		denom /= nod;
//	}
//	if (num >= denom)
//	{
//		int extra_int = num / denom;
//		integer += extra_int;
//		num = num - extra_int * denom;
//	}
//	frac.SetDenom(denom);
//	frac.SetInt(integer);
//	frac.SetNum(num);
//}
//
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	Fraction first(0, 5, 7);
//	Fraction sec(8, 3, 8);
//	Fraction c;
//	c = sec + first;
//	first.Print();
//	sec.Print();
//	c.Print();
//}