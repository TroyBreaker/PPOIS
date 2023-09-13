#pragma once
using namespace std;
class Fraction;

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

void Check(Fraction& frac);

/**
* @brief Class of Fraction with sign
*/

class Fraction {
//! Numenator
	int num;
	//! Denominator
	int denom;
public:
	/**
	 * @brief Class constructor
	 * @param Numenator (if you want negative fraction, then numenator is negative)
	 * @param Denominator (always positive)
     */
	Fraction(int num, int denom)
	{
		if (denom < 0)
		{
			denom = abs(denom);
		}
		if (denom == 0)
		{
			denom = 1;
		}
		if (num != 0)
		{
			int nod = NOD(abs(num), denom);
			num /= nod;
			denom /= nod;
		}
		this->num = num;
		this->denom = denom;
	}
	/**
	 * @brief Class constructor
	 */
	Fraction()
	{}
	/**
	 * @brief Function that output fraction
	 */
	void Print();
	/*
	* @brief Function that output integer part of fraction
	* @return Integer part of fraction
	 */
	int GetInt()
	{
		return num / denom;
	}
	/*
	* @brief Getter for numenator
	* @return Numenator
	 */
	int GetNum()
	{
		return num;
	}
	/*
	* @brief Getter for denominator
	* @return Denominator
	 */
	int GetDenom()
	{
		return denom;
	}
	/**
	 * @brief Function, that set numenator
	 * @param Numenator
	 */
	void SetNum(int num)
	{
		this->num = num;
	}
	/**
	 * @brief Function, that set denominator
	 * @param Denominator
	 */
	void SetDenom(int denom)
	{
		this->denom = denom;
	}
	/**
	* @brief Operator = overloading
	* @param The object from which fields are assigned
	*/
	void operator =(const Fraction& other)
	{
		this->denom = other.denom;
		this->num = other.num;
	}
	/**
	* @brief Operator + overloading
	* @param The second summand in the form of an integer
	* @return Sum
	*/
	Fraction &operator+(int digit)
	{
		Fraction temp(digit, 1);
		temp = temp + *this;
		return temp;
	}
	/**
	* @brief Operator += overloading
	* @param The second summand in the form of an integer
	* @return Sum
	*/
	Fraction &operator +=(int digit)
	{
		Fraction temp(digit, 1);
		*this = temp + *this;
		return *this;
	}
	/**
	* @brief Operator + overloading
	* @param The object from which fields are assigned
	* @return Sum
	*/
	Fraction& operator +(Fraction& other)
	{
		Fraction temp;
		int nok = NOK(this->denom, other.denom);
		int firstQuo = nok / this->denom;
		int secQuo = nok / other.denom;
		this->num *= firstQuo;
		this->denom *= firstQuo;
		other.num *= secQuo;
		other.denom *= secQuo;
		temp.num = this->num + other.num;
		temp.denom = this->denom;
		Check(*this);
		Check(other);
		Check(temp);
		return temp;
	}
	/**
	* @brief Operator += overloading
	* @param The object from which fields are assigned
	* @return Sum
	*/
	Fraction& operator +=(Fraction& other)
	{
		*this = other + *this;
		return *this;
	}
	/**
	* @brief Operator - overloading
	* @param The object from which fields are assigned
	* @return Difference
	*/
	Fraction& operator -(Fraction& other)
	{
		Fraction temp(-(other.GetNum()), other.GetDenom());
		return *this + temp;
	}
	/**
	* @brief Operator -= overloading
	* @param The object from which fields are assigned
	* @return Difference
	*/
	Fraction& operator -=(Fraction& other)
	{
		*this = *this - other;
		return *this;
	}
	/*!
	* @brief Operator - overloading
	* @param Subtrahend  in the form of an integer
	* @return Difference
	*/
	Fraction operator-(int digit)
	{
		Fraction temp(digit, 1);
		temp = *this - temp;
		return temp;
	}
	/*!
	* @brief Operator -= overloading
	* @param Subtrahend in the form of an integer
	* @return Difference
	*/
	Fraction operator -=(int digit)
	{
		Fraction temp(digit, 1);
		*this = *this - temp;
		return *this;
	}
	/**
	* @brief Operator * overloading
	* @param The object from which fields are assigned
	* @return Composition
	*/
	Fraction& operator*(const Fraction& other)
	{
		Fraction temp;
		temp.num = this->num * other.num;
		temp.denom = this->denom * other.denom;
		Check(temp);
		return temp;
	}

	Fraction operator*(int digit)
	{
		Fraction temp(digit, 1);
		temp = *this * temp;
		return temp;
	}
	/**
	* @brief Operator *= overloading
	* @param The object from which fields are assigned
	* @return Composition
	*/
	void operator *=(const Fraction& other)
	{
		*this = *this * other;
	}

	void operator *=(int digit)
	{
		Fraction temp(digit, 1);
		*this = *this * temp;
	}
	/**
	* @brief Operator / overloading
	* @param The object from which fields are assigned
	* @return Quotient
	*/
	Fraction& operator/(const Fraction& other)
	{
		Fraction temp;
		temp.num = this->num * other.denom;
		temp.denom = this->denom * other.num;
		if (other.num < 0 && this->num < 0)
		{
			temp.num *= -1;
			temp.denom *= -1;
		}
		if (other.num < 0 && this->num > 0)
		{
			temp.num *= -1;
			temp.denom *= -1;
		}
		Check(temp);
		return temp;
	}
	/**
	* @brief Operator /= overloading
	* @param The object from which fields are assigned
	* @return Quotient
	*/
	void operator /=(Fraction& other)
	{
		*this = *this / other;
	}

	Fraction operator/(int digit)
	{
		Fraction temp(digit, 1);
		temp = *this / temp;
		return temp;
	}

	void operator /=(int digit)
	{
		Fraction temp(digit, 1);
		*this = *this / temp;
	}

	Fraction& operator++()
	{
		Fraction temp(1, 1);
		*this = temp + *this;
		return *this;
	}

	Fraction& operator++(int value)
	{
		Fraction temp = *this;
		++* this;
		return temp;
	}

	Fraction& operator--()
	{
		Fraction temp(1, 1);
		*this = *this - temp;
		return *this;
	}

	Fraction& operator--(int value)
	{
		Fraction temp = *this;
		--* this;
		return temp;
	}
	/**
	* @brief Operator > overloading
	* @param The object from which fields are assigned
	* @return Is it bigger
	*/
	bool operator>(Fraction& other)
	{
		int nok = NOK(this->denom, other.denom);
		int firstQuo = nok / this->denom;
		int secQuo = nok / other.denom;
		this->num *= firstQuo;
		this->denom *= firstQuo;
		other.num *= secQuo;
		other.denom *= secQuo;
		if (this->num > other.num)
		{
			Check(*this);
			Check(other);
			return true;
		}
		else
		{
			Check(*this);
			Check(other);
			return false;
		}
	}
	/**
	* @brief Operator < overloading
	* @param The object from which fields are assigned
	* @return Is it less
	*/
	bool operator<(Fraction& other)
	{
		return !(*this > other);
	}
	/**
	* @brief Operator >= overloading
	* @param The object from which fields are assigned
	* @return Is it more or equal
	*/
	bool operator>=(Fraction& other)
	{
		int nok = NOK(this->denom, other.denom);
		int firstQuo = nok / this->denom;
		int secQuo = nok / other.denom;
		this->num *= firstQuo;
		this->denom *= firstQuo;
		other.num *= secQuo;
		other.denom *= secQuo;
		if (this->num >= other.num)
		{
			Check(*this);
			Check(other);
			return true;
		}
		else
		{
			Check(*this);
			Check(other);
			return false;
		}
	}
	/**
	* @brief Operator <= overloading
	* @param The object from which fields are assigned
	* @return Is it less or equal
	*/
	bool operator<=(Fraction& other)
	{
		return !(*this > other);
	}

	bool operator>(int digit)
	{
		return this->num * 1. / this->denom > digit;
	}

	bool operator<(int digit)
	{
		return this->num * 1. / this->denom < digit;
	}

	bool operator>=(int digit)
	{
		return this->num * 1. / this->denom >= digit;
	}

	bool operator<=(int digit)
	{
		return this->num * 1. / this->denom <= digit;
	}

	double Convert();

};

double Fraction::Convert()
{
	return num * 1. / denom;
}

void Fraction::Print()
{
	cout << "ִנמבü " << this << " " << num << "/" << denom << endl;
}

void Check(Fraction& frac)
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