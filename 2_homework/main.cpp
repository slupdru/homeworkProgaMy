#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
class Employee {
	char *FIO, *sex, *placeofwork, *position;
	int age, experience, salary;
public:
	static int countofworkers;
	static void GetCountOfWorkers()
	{
		cout << endl;
		cout << countofworkers;
		cout << endl;
	}
	Employee() : age(0), experience(0), salary(0)
	{
		++countofworkers;
		FIO = (char* )malloc(45);
		sex = new char[15];
		placeofwork = new char[20];
		position = new char[20];
		cout << "����������� ��� ���������� �������\n";
	}
	~Employee()
	{
		--countofworkers;
		free(FIO);
		 delete sex, placeofwork, position;
		cout << "���������� �������\n";
	}
	void Salary()
	{
		int i;
		cout << "������� ����������� ��������: " << endl;;
		cin >> i;
		salary += i;
	}
	void SetPosition()
	{
		cout << "������� ���������: " << endl;;
		cin >> position;
	}
	void setData()
	{
		cout << "������� ���: " << endl;
		cin >> FIO;
		cout << "������� ���: " << endl;
		cin >> sex;
		cout << "������� �������: " << endl;
		cin >> age;
		cout << "������� ����� ������: " << endl;
		cin >> placeofwork;
		cout << "������� ����: " << endl;
		cin >> experience;
	}

	bool operator==(Employee s1)
	{
		if ((FIO == s1.FIO) && (sex == s1.sex) && (placeofwork == s1.placeofwork)
			&& (position == s1.position) && (age == s1.age)
			&& (experience == s1.experience) && (salary == s1.salary))
			return true;
		else
			return false;
	}
	void Show()
	{
		cout << "����� ������: " << placeofwork << endl;
		cout << "���������: " << position << endl;
		cout << "���� ������: " << experience << endl;
		cout << "���������� �����: " << salary << endl;
	}
	void ShowFIO()
	{
		cout << "���: " << FIO << endl;
		cout << "���: " << sex << endl;
		cout << "�������: " << age << endl;
	}
};
int Employee::countofworkers = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Employee team[2];
	team[0].setData();
	team[0].Salary();
	team[0].SetPosition();
	team[1].setData();
	team[1].Salary();
	team[1].SetPosition();

	team[1].Show();
	team[1].ShowFIO();
	team[1].GetCountOfWorkers();
	return 0;
}
