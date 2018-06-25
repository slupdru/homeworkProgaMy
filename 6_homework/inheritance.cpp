// inheritance.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Point2D
{
protected:
	int x, y;
public:
	Point2D(int x1, int y1): x(x1), y(y1)
	{}
};
class Z
{
protected:
	int z;
public:
	Z(int z1):z(z1)
	{}
};
class Point3D : public Point2D, public Z
{
public:
	Point3D(int x2, int y2, int z2): Point2D(x2,y2), Z(z2)
	{}
	void Con()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl;
	}
};
int main()
{
    return 0;
}

