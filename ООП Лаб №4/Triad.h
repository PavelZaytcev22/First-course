#pragma once
#include <iostream>
using namespace std;

class Triad {
	//Атрибуты класса 
protected:
	int first;
	int second;
	int third;

	public:
		//Конструкторы 
	Triad();
	Triad(int, int, int);
	Triad(const Triad&);
	//Диструктор 
	~Triad() {};
	//Спецификаторы 
	int get_first() { return first; }
	int get_second() { return second;}
	int get_third() { return third; };
	//Модификаторы 
	void set_first(int m) { first = m; }
	void set_second(int s) { second = s; }
	void set_third(int x) { third = x; }
	//Перенрузка оператора присваивания 
	Triad& operator = (const Triad&);

	//Перегрузка операторов потоковых ввода вывода 
	friend istream& operator>>(istream& in, Triad& t);
	friend ostream& operator<<(ostream& out, const Triad& t);

	//Перегрузка операторов сравнения 
	friend bool operator ==(const Triad& c1, const Triad& c2);
	friend bool operator !=(const Triad& c1, const Triad& c2);
};
