#include <iostream>
#include <string>
#include "PRINT.h"
#include "Event.h"
using namespace std;
//Конструктор без параметров 
PRINT::PRINT() {
	autor = "";
	name = "";
}
//конструктор с параметрами 
PRINT::PRINT(string s1, string s2) {
	autor = s1;
	name = s2;
}
//конструктор копирования 
PRINT::PRINT(const PRINT&s1 ) {
	autor = s1.autor;
	name = s1.name;
}
//Деструктор 
PRINT::~PRINT()
{
}

//модификаторы 
void PRINT::Set_autor(string s2) {
	autor = s2;
}
void PRINT::Set_name(string s1) {
	name = s1;
}

//метод для просмотра атрибутов
void PRINT::Show() {
	cout << "\nAutor : " << autor;
	cout << "\nName : " << name;
	cout << "\n";
}
//метод для ввода значений атрибутов
void PRINT::Input() {
	cout << "\nAutor?";cin >> autor;
	cout << "\nName?"; cin >> name;
	cout << "\n";
}

PRINT& PRINT::operator=(const PRINT& c)
{
	if (&c == this)return *this;
	autor = c.autor;
	name = c.name;
	return *this;
}

void PRINT::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)//событие-сообщение
	{
		switch (e.command)
		{
		case cmGet:cout << "autor=" << Get_autor() << endl;
			break;
		}
	}
}

