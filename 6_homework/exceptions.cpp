// exceptions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
class file
{
	ifstream fouth;
public:
	void openfile(const char* m)
	{
		fouth.open(m);
		cout << "�������� ������� ����..." << endl;
		if (!fouth.is_open())
			throw "���� ������ �������";
		else
			throw "���� ������";
	}
	void closefile()
	{
		cout << "��������� ����" << endl;
		fouth.close();
	}
};

int main()
{
	setlocale(0, "");
	file g;
	try
	{
		g.openfile("D:\docs\file.txt");
	}
	catch(const char* m)
	{
		cout << m << endl;
		if (m == "���� ������")
			g.closefile();
	}
    return 0;
}

