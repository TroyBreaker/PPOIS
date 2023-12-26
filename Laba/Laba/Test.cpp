//#include <cstdlib>
#include "Haeder.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(SimpleCount, test1)
{
	Fraction first(5, -15);
	Fraction sec(0, 0);
	Fraction third(-58, 13);
	EXPECT_EQ(third.GetInt(), -4);
	Fraction fourth;
	fourth = sec + first;
	EXPECT_EQ(fourth.GetNum(), 1);
	bool isBigger = first > sec;
	EXPECT_TRUE(isBigger);
	isBigger = first > -5;
	EXPECT_TRUE(isBigger);
	isBigger = first < sec;
	EXPECT_TRUE(!isBigger);
	isBigger = first < -5;
	EXPECT_TRUE(!isBigger);
	double a = fourth.Convert();
	EXPECT_EQ(a, 1 / 3.);
	Fraction fifth = first + 7;
	a = fifth.Convert();
	EXPECT_EQ(a, 22 / 3.);
	NOK(1, 5);
}

TEST(SimpleCount, test2)
{
	Fraction first(-4, 9);
	Fraction sec(4, 9);
	bool isLess = first < sec;
	EXPECT_TRUE(isLess);
	isLess = sec < 4;
	EXPECT_TRUE(isLess);
	isLess = first > sec;
	EXPECT_TRUE(!isLess);
	isLess = sec > 4;
	EXPECT_TRUE(!isLess);
	Fraction third;
	first += sec;
	double a = first.Convert();
	EXPECT_EQ(a, 0);
	first.SetNum(41);
	first.SetDenom(8);
	third = sec - first;
	sec - first;
	a = third.Convert();
	EXPECT_EQ(a, -337. / 72);
	third = sec - 5;
	a = third.Convert();
	EXPECT_EQ(a, -41. / 9);
}

TEST(SimpleCount, test3)
{
	Fraction first(2, 3);
	Fraction sec(8, 16);
	bool isBigger = first >= sec;
	EXPECT_TRUE(isBigger);
	isBigger = first >= -5;
	EXPECT_TRUE(isBigger);
	isBigger = first <= sec;
	EXPECT_TRUE(!isBigger);
	isBigger = first <= -5;
	EXPECT_TRUE(!isBigger);
	first += sec;
	double a = first.Convert();
	EXPECT_EQ(a, 7. / 6);
	sec += 2;
	a = sec.Convert();
	EXPECT_EQ(a, 2.5);
}

TEST(SimpleCount, test4)
{
	Fraction first(2, 3);
	Fraction sec(8, 16);
	bool isLess = sec <= first;
	EXPECT_TRUE(isLess);
	isLess = first <= 5;
	EXPECT_TRUE(isLess);
	isLess = sec >= first;
	EXPECT_TRUE(!isLess);
	isLess = first >= 5;
	EXPECT_TRUE(!isLess);
	first -= sec;
	double a = first.Convert();
	EXPECT_EQ(a, 1. / 6);
	sec -= 2;
	a = sec.Convert();
	EXPECT_EQ(a, -1.5);
}

TEST(SimpleCount, test5)
{
	Fraction first(0, 8);
	Fraction sec(6, 21);
	Fraction third;
	third = sec * 3;
	double a = third.Convert();
	EXPECT_EQ(a, 6./7);
	third *= -3;
	a = third.Convert();
	EXPECT_EQ(a, -18. / 7);
}

TEST(SimpleCount, test6)
{
	Fraction first(-6, 7);
	Fraction sec(-9, 7);
	Fraction third;
	third = first / sec;
	double a = third.Convert();
	EXPECT_EQ(a, 2. / 3);
	first /= sec;
	a = first.Convert();
	EXPECT_EQ(a, 2. / 3);
	third = first / 2;
	a = third.Convert();
	EXPECT_EQ(a, 1. / 3);
}

TEST(SimpleCount, test7)
{
	Fraction first(6, 7);
	Fraction sec(-9, 7);
	Fraction third;
	third = first / sec;
	double a = third.Convert();
	EXPECT_EQ(a, -2. / 3);
	first /= sec;
	a = first.Convert();
	EXPECT_EQ(a, -2. / 3);
}

TEST(SimpleCount, test8)
{
	Fraction first(4, 7);
	Fraction sec(5, 7);
	bool isBigger_eq = first >= sec;
	EXPECT_TRUE(!isBigger_eq);
	first *= sec;
	double a = first.Convert();
	EXPECT_EQ(a, 20. / 49);
	sec /= 2;
	a = sec.Convert();
	EXPECT_EQ(a, 5. / 14);
}

TEST(SimpleCount, test9)
{
	Fraction first(5, 7);
	--first--;
	++first++;
	double a = first.Convert();
	EXPECT_EQ(a, 5. / 7);
}

TEST(SimpleCount, test10)
{
	Fraction first(6, 7);
	Fraction sec(0, 7);
	Fraction third;
	third = first / sec;
	double a = third.Convert();
	EXPECT_EQ(a, 6);
}

TEST(SimpleCount, test11)
{
	Fraction first(0, 8);
	Fraction sec(0, 21);
	Fraction third;
	third = sec * first;
	double a = third.Convert();
	EXPECT_EQ(a, 0);
	third *= 0;
	a = third.Convert();
	EXPECT_EQ(a, 0);
}

TEST(SimpleCount, test12)
{
	Fraction first(0, 8);
	Fraction sec(0, 21);
	Fraction third;
	third = sec * 3;
	double a = third.Convert();
	EXPECT_EQ(a,0);
	third *= sec;
	a = third.Convert();
	EXPECT_EQ(a, 0);
}

TEST(SimpleCount, test13)
{
	Fraction first(0, 8);
	Fraction sec(0, 21);
	Fraction third;
	third = sec / 3;
	double a = third.Convert();
	EXPECT_EQ(a, 0);
	third /= -3;
	a = third.Convert();
	EXPECT_EQ(a, 0);
}

TEST(SimpleCount, test14)
{
	Fraction first(0, 8);
	Fraction sec(0, 21);
	Fraction third;
	third = sec / first;
	double a = third.Convert();
	EXPECT_EQ(a, 0);
	third /= sec;
	a = third.Convert();
	EXPECT_EQ(a, 0);
}

TEST(SimpleCount, test15)
{
	Fraction first(0, 8);
	Fraction sec(0, 8);
	Fraction third;
	third = sec + first;
	double a = third.Convert();
	EXPECT_EQ(a,0);
	third =sec - first;
	a = third.Convert();
	EXPECT_EQ(a, 0);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
