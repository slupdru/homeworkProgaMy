// DrawwithSlaik.cpp: РѕРїСЂРµРґРµР»СЏРµС‚ С‚РѕС‡РєСѓ РІС…РѕРґР° РґР»СЏ РєРѕРЅСЃРѕР»СЊРЅРѕРіРѕ РїСЂРёР»РѕР¶РµРЅРёСЏ.
//

#include "stdafx.h"
#include "canvas.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	canvas* c1 = new canvas;
	POINT* p = new POINT[5];
	p[0].x = 10;
	p[0].y = 10;
	p[1].x = 200;
	p[1].y = 100;
	p[2].x = 300;
	p[2].y = 180;
	p[3].x = 400;
	p[3].y = 200;
	p[4].x = 270;
	p[4].y = 10;
	c1->addprimitive(1, new point(50, 70));
	c1->addprimitive(2, new line(50, 90));
	c1->addprimitive(3, new ellips(50, 100, 200, 300, 0));
	c1->addprimitive(4, new rectangle(100, 200, 300, 400, 1));
	c1->addprimitive(5, new poligon(p, 0, 5));
	c1->drow();
	return 0;
}


