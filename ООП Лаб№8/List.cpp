#include "PRINT.h"
#include "BOOK.h"
#include "List.h"
#include <iostream>
#include <string>
using namespace std;

//деструктор
List::~List(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}

List::List()
{
	beg = 0;
	cur = 0;
	size = 0;
}
//конструктор с параметрами
List::List(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}
//добавление объекта, на который указывает указатель p в вектор
void List::Add()
{
	Object* p;
	//выбор из объектов двух возможных классов
	cout << "1.PRINT" << endl;
	cout << "2.BOOK" << endl;
	int y;
	cin >> y;
	if (y == 1)//добавление объекта класса Car
	{
		PRINT* a = new (PRINT);
		a->Input();//ввод значений атрибутов
		p = a;
		if (cur < size)
		{
			beg[cur] = p;//добавление в вектор
			cur++;
		}
	}
	else
		if (y == 2) //добавление объекта класса Lorry
		{
			BOOK* b = new (BOOK);
			b->Input();
			p = b;
			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else return;

}
//просмотр вектора

void List::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = beg;//указатель на указатель типа Object
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();//вызов метода Show() (позднее связывание)
		p++;//передвигаем указатель на следующий объект
	}

}
//операция, которая возвращает размер вектора
int List::operator ()()
{
	return cur;
}
//удаление элемента из вектора, память не освобождается!
void List::Del()
{
	if (cur == 0)return;//пустой
	cur--;
}

void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);//вызов метода (позднее связывание)
			p++;//передвигаем указатель на следующий объект
		}
	}
}