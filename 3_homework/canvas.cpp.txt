#include "stdafx.h"
#include "canvas.h"
#include <conio.h>
using namespace std;
point::point()
{
	x = 0;
	y = 0;
}
line::line(line & l1)
{
	x = l1.x;
	y = l1.y;
}
ellips::ellips(ellips & e1)
{
	p1.x = e1.p1.x;
	p1.y = e1.p1.y;
	p2.x = e1.p2.x;
	p2.y = e1.p2.y;
	a = e1.a;
}
rectangle::rectangle(rectangle & r1)
{
	p1.x = r1.p1.x;
	p1.y = r1.p1.y;
	p2.x = r1.p2.x;
	p2.y = r1.p2.y;
	a = r1.a;
}
poligon::poligon(poligon & p1)
{
	size = p1.size;
	a = p1.a;
	POINT* p = new POINT[size];
	for (int i = 0; i < size; i++) p[i] = p1.p[i];
}

primitive::primitive(int t, void* obj)
{
	type = t;
	object = obj;
}
void canvas::addprimitive(int t, void* obj)
{
	struct primitive* p1 = new primitive(t, obj);
	a1.push_back(*p1);
}
void canvas::delprimitive()
{
	a1.pop_back();
}
void canvas::dellall()
{
	a1.~vector();
}
void canvas::drow() {
	HWND hWnd = GetConsoleWindow(); // ссылка на окно
	HDC hdc = GetDC(hWnd);		// ссылка на контекст устройства графического вывода
	SelectObject(hdc, CreatePen(PS_SOLID, 5, 0x00ff0000));
	for (int i = 0; i < a1.size(); i++)
	{
		switch (a1.at(i).type)
		{
		case 1: {
			point* pp = (point*)a1.at(i).object;
			SetPixel(hdc, pp->x, pp->y, 0x00ff0000);
		}
				break;
		case 2: {
			line* ll = (line*)a1.at(i).object;
			LineTo(hdc, ll->x, ll->y);
		}
				break;
		case 3: {
			ellips* el = (ellips*)a1.at(i).object;
			if (el->a)
			{
				SelectObject(hdc, CreateSolidBrush(0x00ff0000));
				Ellipse(hdc, el->p1.x, el->p1.y, el->p2.x, el->p2.y);
			}
			else
			{
				SelectObject(hdc, CreateSolidBrush(0x00000000));
				Ellipse(hdc, el->p1.x, el->p1.y, el->p2.x, el->p2.y);
			}
		}
				break;
		case 4: {
			rectangle* rec = (rectangle*)a1.at(i).object;
			if (rec->a)
			{
				SelectObject(hdc, CreateSolidBrush(0x00ff0000));
				Rectangle(hdc, rec->p1.x, rec->p1.y, rec->p2.x, rec->p2.y);
			}
			else
			{
				SelectObject(hdc, CreateSolidBrush(0x00000000));
				Rectangle(hdc, rec->p1.x, rec->p1.y, rec->p2.x, rec->p2.y);
			}
		}
		case 5: {
			poligon* pol = (poligon*)a1.at(i).object;
			if (pol->a)
			{
				SelectObject(hdc, CreateSolidBrush(0x00ff0000));
				Polygon(hdc, pol->p, pol->size);
			}
			else
			{
				SelectObject(hdc, CreateSolidBrush(0x00000000));
				Polygon(hdc, pol->p, pol->size);
			}
		}
				break;
		}
		// вывод прямоугольника цветом пера
		_getch();
		system("cls");
	}
	ReleaseDC(hWnd, hdc);

}



point::point(int x1, int y1) {
	x = x1;
	y = y1;
}
line::line(int x1, int y1)
{
	x = x1;
	y = y1;
}
ellips::ellips(int x1, int x2, int y1, int y2, bool a1) {
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
	a = a1;
}
rectangle::rectangle(int x1, int x2, int y1, int y2, bool a2) {
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
	a = a2;
}
poligon::poligon(POINT* p1, bool a1, int s) {
	p = p1;
	a = a1;
	size = s;
}