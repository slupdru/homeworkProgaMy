#pragma once
#include <vector>
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

struct primitive {
	int type;
	void* object;
	primitive(int, void*);
};
class canvas {
	vector <primitive> a1;
public:
	void addprimitive(int t, void* obj);
	void delprimitive();
	void dellall();
	void drow();
};

class point {

public:
	int x, y;
	point();
	point(int x1, int y1);
};

class line {

public:
	int x, y;
	line(int x1, int y1);
	line(line &l1);
};

class ellips {

public:
	point p1, p2;
	bool a;//поле для идентификатора закрашено(1)/незакрашено(0) 
	ellips(int x1, int x2, int y1, int y2, bool a1);
	ellips(ellips &e1);

};

class rectangle {

public:
	point p1, p2;
	bool a;//поле для идентификатора закрашено(1)/незакрашено(0)
	rectangle(int x1, int x2, int y1, int y2, bool a2);
	rectangle(rectangle &r1);

};
class poligon {
public:
	POINT *p;
	int size;
	bool a;
	poligon(POINT *, bool a1, int s);
	poligon(poligon &p1);
};

