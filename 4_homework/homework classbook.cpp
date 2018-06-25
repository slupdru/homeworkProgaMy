// classworkbook.cpp: РѕРїСЂРµРґРµР»СЏРµС‚ С‚РѕС‡РєСѓ РІС…РѕРґР° РґР»СЏ РєРѕРЅСЃРѕР»СЊРЅРѕРіРѕ РїСЂРёР»РѕР¶РµРЅРёСЏ.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <cstring>
using namespace std;
class date //класс для работы с датами
{
	int day;
	int month;
	int year;
public:
	void put()
	{
		cout << "Введите день: ";
		cin >> day;
		cout << "Введите месяц: ";
		cin >> month;
		cout << "Введите год: ";
		cin >> year;
	}
	void get()    // вывод данных о дате
	{
		cout << day << '.' << month << '.' << year;
	}
	int operator-(date a1)   // описание операции для считывание интервала между датами в днях 
	{
		return((year - a1.year) * 365 + (month - a1.month) + day - a1.day);
	}
};
///////////////////////////////////////////////////////////
struct link   // один элемент списка
{
	char* reader;   // некоторые данные о читателе
	date d; // дата выдачи книги
	link* next; // указатель на следующую структуру
};
///////////////////////////////////////////////////////////
class linklist // список, описывающий читателей
{
private:
	link* first;
	link* last;
public:
	linklist()            // конструктор без параметров
	{
		first = NULL;
		last = NULL;
	}
	void additem(char* r, date d);    // добавление элемента
	linklist(linklist & l)
	{
		first = NULL;
		link * _first = l.first;
		do {
			additem(_first->reader, _first->d);
			_first = _first->next;
		} while (_first);
	}
	void delitem(char* r1);     //удаление элемента
	void delall();      //удаление всего списка
	void display();     //вывод всех данных
	void display(date d1);       // показ данных в зависимости от даты
};
void linklist::delall()
{

	link* current = first;
	while (current)
	{
		link *next = current->next;
		delete current;
		current = next;
	}
}
void linklist::display()
{
	link* current = first;           // начинаем с первого элемента
	while (current)                   // пока есть данные
	{
		cout << current->reader << endl; // печатаем данные
		current = current->next;      // двигаемся к следующему элементу
	}
}
void linklist::delitem(char* r1)
{
		link* current = first;
		link* pref = NULL;
		while (current)                   // пока есть данные
		{
			if (current->reader == r1)   // если название книги совпадает с названием элемента из списка 
			{
				if (!pref)
				{
					first = current->next;
					delete current;
				}
				else
				{
					pref->next = current->next;// удаление из списка элемента
					delete current;
				}
			}
			else
			{
				pref = current; // определяем предыдущий элемент
				current = current->next; // двигаемся к следующему элементу
			}
		}
}
void linklist::additem(char* r, date d)    // добавление элемента
{
	link* newlink = new link; // выделяем память
	newlink->reader = new char[30];
	strcpy_s(newlink->reader, strlen(r) + 1, r);          // запоминаем данные о читателе
	newlink->d = d;             // запоминаем значение даты выдачи
	newlink->next = NULL;
	if (!first)
	{
		first = newlink;
		last = first;
		first->next = last;
	}
	else if (first == last)
	{
		last = newlink;
		first->next = last;
	}
	else
	{
		last->next = newlink;
		last = newlink;
	}
}
void linklist::display(date d1)
{
	link* current = first;           // начинаем с первого элемента
	while (current)                   // пока есть данные
	{
		if ((d1 - current->d) >= 365)
			cout << current->reader << endl; // печатаем данные
		current = current->next;      // двигаемся к следующему элементу
	}
}
///////////////////////////////////////////////////////////
class book
{
protected:
	char* name;// название книги
	char* readers;// авторы книги
	int yp;// год издания
	char* publ;// название издательства
	int amp;// количество страниц
	int id;
public:
	book() :yp(0), amp(0), id(0)
	{
		name = new char[20];
		publ = new char[20];
		readers = new char[50];
	}
	book(book &);
	void put()
	{
		cout << "Введите название книги:";
		cin >> name;
		cout << "Введите авторов книги:";
		cin >> readers;
		cout << "Введите год издания:";
		cin >> yp;
		cout << "Введите название издательства:";
		cin >> publ;
		cout << "Введите количество страниц:";
		cin >> amp;
	}
	~book()
	{
		delete[]name;
		delete[]publ;
		delete[]readers;
	}
};
book::book(book & b1) : yp(b1.yp), amp(b1.amp), id(b1.id)
{
	name = new char[20];
	publ = new char[20];
	readers = new char[50];
	strcpy_s(name, strlen(b1.name) + 1, b1.name);
	strcpy_s(publ, strlen(b1.publ) + 1, b1.publ);
	strcpy_s(readers, strlen(b1.readers) + 1, b1.readers);
}
///////////////////////////////////////////////////////////
class direct : public book
{
	int ambook;// количество экземпляров
	int ambinst;// amount of books in stock 
	linklist l2;// список читателей
public:
	direct() : book(), ambook(0), ambinst(0)
	{}
	direct(direct & d2) : book(d2), ambook(d2.ambook), ambinst(d2.ambinst), l2(d2.l2)
	{}
	~direct()
	{
		//book::~book();
		l2.delall();
	}
	void put()  // ввод данных о книге
	{
		book::put();
		cout << "Введите количество экземпляров: ";
		cin >> ambook;
		cout << "Введите количество экземпляров в наличии: ";
		cin >> ambinst;
	}
	char* outr()
	{
		return readers;
	}
	char* outn()
	{
		return name;
	}
	int outid()
	{
		return id;
	}
	void getread()
	{
		l2.display();
	}
	void getting(); // добавление читателей 
	void del();  // удаление данных о книге
	void dellist() //удаление списка читателей
	{
		l2.delall();
		ambinst = ambook;
	}
	void show(date); // вывод списка читателей, которые взяли книгу более 1 года назад, включая только тех, кто не сдал книгу
};
//////////////////////////////////////////////////////////
void direct::getting()
{
	char * r = new char[30];
	date* d2 = new date;
	cout << "Введите имя читателя:";
	cin >> r;
	cout << "Введите дату выдачи" << endl;
	d2->put();
	l2.additem(r, *d2);
	--ambinst;
}
void direct::del()
{
	char * r;
	r = new char[30];
	cout << "Введите имя читателя:";
	cin >> r;
	l2.delitem(r);
	++ambinst;
	delete[] r;
}
void direct::show(date d1)
{
	l2.display(d1);
}
///////////////////////////////////////////////////////////
struct linkdir   // один элемент списка
{
	direct* d1;   // некоторые данные о каталоге
	linkdir* next; // указатель на следующую структуру
};
///////////////////////////////////////////////////////////
class linkfordirect // список
{
private:
	linkdir* first;
	linkdir* last;
public:
	linkfordirect()            // конструктор без параметров
	{
		first = NULL;
		last = NULL;
	}   // первого элемента пока нет
	void additem(direct d)//добаление книги в каталог
	{
		linkdir* newlink = new linkdir; // выделяем память
		newlink->d1 = new direct(d);
		newlink->next = NULL;
		if (!first)
		{
			first = newlink;
			last = first;
			first->next = last;
		}
		else if (first == last)
		{
			last = newlink;
			first->next = last;
		}
		else
		{
			last->next = newlink;
			last = newlink;
		}
	}
	void display();     // показ данных
	void display(int ID);
	void display(date d1);
	void display(char* r, char* n);
	void delitem(char*);// удаление элемента из списака
};
void linkfordirect::display(date d1)//выводит читателей, которые не отдали книги в течение года
{
	linkdir* current = first;
	while (current)
	{
		current->d1->show(d1);
		current = current->next;
	}
}
void linkfordirect::display()//функция выводит названия книг с читателями
{
	linkdir* current = first;           // начинаем с первого элемента
	cout << "Вывод всего каталога: ";
	while (current)                   // пока есть данные
	{
		cout << "Название книги: " << current->d1->outn() << endl; // печатаем данные
		cout << "Список читателей: ";
		current->d1->getread();
		cout << endl << endl;
		current = current->next;       // двигаемся к следующему элементу
	}
}
void linkfordirect::display(int ID)//Вывод информации по книге и читателям взявшим книгу по идентификатору
{
	linkdir* current = first;           // начинаем с первого элемента
	while (current)                   // пока есть данные
	{
		if (current->d1->outid() == ID)
		{
			cout << "Название книги: " << current->d1->outn() << endl; // печатаем данные о книге
			cout << "Список читателей:";
			current->d1->getread();
		}
		current = current->next;       // двигаемся к следующему элементу
	}
}
void linkfordirect::display(char* r, char* n)//Поиск книги в каталоге по названию и по автору с выдачей идентификатора
{
	linkdir* current = first;           // начинаем с первого элемента
	while (current)                   // пока есть данные
	{
		if ((current->d1->outn() == n) && (current->d1->outr() == r))
		{
			cout << "Индефекатор: " << current->d1->outid() << endl; // печатаем данные о книге
		}
		current = current->next;       // двигаемся к следующему элементу
	}
}
void linkfordirect::delitem(char* n)//удаление книги из каталога
{
	linkdir* current = first;
	linkdir* pref;
	while (current)                   // пока есть данные
	{
		pref = current;               // запоминаем данные предыдущего элемента
		current = current->next;      // двигаемся к следующему элементу
		if (current->d1->outn() == n)   // если название книги совпадает с названием элемента из списка 
		{
			pref->next = current->next;// удаление из списка элемента
		}
	}
}
///////////////////////////////////////////////////////////
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	linkfordirect l1;
	direct* d1 = new direct;
	d1->put();
	d1->getting();
	d1->getting();
	l1.additem(*d1);
	direct* d2 = new direct;
	d2->put();
	d2->getting();
	d2->getting();
	l1.additem(*d2);
	cout << endl << endl << endl;
	l1.display();
	date x;
	x.put();
	l1.display(x);
	return 0;
}

