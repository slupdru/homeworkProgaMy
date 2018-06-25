// exceptions.cpp: –æ–ø—Ä–µ–¥–µ–ª—è–µ—Ç —Ç–æ—á–∫—É –≤—Ö–æ–¥–∞ –¥–ª—è –∫–æ–Ω—Å–æ–ª—å–Ω–æ–≥–æ –ø—Ä–∏–ª–æ–∂–µ–Ω–∏—è.
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
		cout << "œ˚Ú‡ÂÏÒˇ ÓÚÍ˚Ú¸ Ù‡ÈÎ..." << endl;
		if (!fouth.is_open())
			throw "‘‡ÈÎ ÌÂÎ¸Áˇ ÓÚÍ˚Ú¸";
		else
			throw "‘‡ÈÎ ÓÚÍ˚Ú";
	}
	void closefile()
	{
		cout << "«‡Í˚‚‡ÂÏ Ù‡ÈÎ" << endl;
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
		if (m == "‘‡ÈÎ ÓÚÍ˚Ú")
			g.closefile();
	}
    return 0;
}

