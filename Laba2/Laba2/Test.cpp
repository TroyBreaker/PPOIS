#include <iostream>
#include <gtest/gtest.h>
#include "Deanery.h"

TEST(TestCaseName, TestName) {
	//srand(time(NULL));
	string names[30] = {
		"John", "Emma", "Michael", "Olivia", "William", "Ava",
		"James", "Sophia", "Benjamin", "Isabella", "Daniel", "Mia",
		"Joseph", "Charlotte", "Henry", "Amelia", "Alexander", "Harper",
		"David", "Evelyn", "Matthew", "Abigail", "Samuel", "Emily",
		"Ethan", "Elizabeth", "Daniel", "Sofia", "Andrew", "Grace"
	};
	Student* ArrSt[7];
	Group* ArrGr[2];
	Student* St;
	Schedule* sch;
	int i = 0;
	int j = 0;
	for (j = 0; j < 2; j++)
	{
		for (i = 0; i < 7; i++)
		{
			int arr[5];
			for (int j = 0; j < 5; j++)
			{
				arr[j] = rand() % 9 + 2;
			}
			Record_Card* RC = new Record_Card(arr, 0);
			int a = rand() % 700 + 300;
			bool Budget = rand() % 2;
			bool Benefit = rand() % 2;
			St = new Student(Benefit, RC, Budget, 0, 0);
			St->SetFIO(names[rand() % 30]);
			St->SetMoney(a);
			ArrSt[i] = St;
		}
		int course = rand() % 4 + 1;
		int group = 221700 + 1 + j;
		sch = new Schedule();
		Group* Gr = new Group(i, course, group, ArrSt, sch);
		ArrGr[j] = Gr;
	}
	Teacher* ArrTch[7];
	Department* ArrDep[2];
	Teacher* Tch;

	int numberOfTeachers;
	int numberOfDeps = 0;
	for (numberOfDeps = 0; numberOfDeps < 2; numberOfDeps++)
	{
		for (numberOfTeachers = 0; numberOfTeachers < 2; numberOfTeachers++)
		{
			int a = rand() % 900 + 300;
			sch = new Schedule();
			Tch = new Teacher("Assistant", sch);
			Tch->SetFIO(names[rand() % 30]);
			Tch->SetMoney(a);
			ArrTch[numberOfTeachers] = Tch;
		}
		Department* Dep = new Department(2, ArrTch, "POIT");
		ArrDep[numberOfDeps] = Dep;
	}
	ArrDep[0]->Setname("IIT");
	Deckan s;
	Metodist met;
	string Fac = "FITU";
	Accounting account(30, 400, 110, 1000, 10000);
	Deanery Dean(ArrGr, j, Fac, &s, &met, &account, ArrDep, numberOfDeps);
	int arr[7] = { 2,3,4,2,3,1,0 };
	Dean.Transfer("Olivia", 221701, 221702);
	Dean.GetGroup(221701)->GetStud(4)->SetBudget(1);
	Dean.Signature(221701);
	met.GiveRef(Dean.GetGroup(221702)->GetStud("Olivia"));
	Dean.DeaneryCheck(221702, 1);
	Dean.GiveDorm(221702);
	Dean.GetGroup(221702)->GetStud("Emily")->SetFIO("Emily l");
	Dean.GetGroup(221702)->GetStud("Mia")->PayForDorm(&Dean);
	Dean.GetGroup(221701)->GetStud("Michael")->PayFee(&Dean);
	Dean.GiveSalary("Daniel", "IIT");
	Dean.TeacherDegree(Dean.GetDep("POIT")->GetTeacher(0), 1, "Senior");
	Dean.GiveScholarship("Michael", 221701);
	Dean.SetScheduleForGroup(arr, 221702);
	Dean.SetScheduleForTeacher(arr, "Samuel", "IIT");
	Dean.TransferBudget(221702, 1);
	EXPECT_EQ(1, 1);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
