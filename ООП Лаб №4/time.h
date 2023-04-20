#pragma once
#include "Triad.h"
#include <iostream>
using namespace std;

class TIME : protected Triad 
{
	int hour;
	int minute; 
	int seconds;
public:
//конструкторы 
	TIME();
	TIME(int, int, int);
	TIME(const TIME&);
//диструктор 
	~TIME() {};
	//Селекторы
	int get_hours() { return hour; }
	int get_minutes() { return minute; }
	int get_seconds() { return seconds; }

	//Модификаторы 
	void set_hours(int m) { hour = m; }
	void set_minutes(int s) { minute = s; }
	void set_seconds(int x) { seconds = x; }

	TIME& operator=(const TIME&);//операция присваивания

	//Перегрузка потоковых операторов вводы и вывода 
	friend istream& operator>>(istream& in, TIME& l);//операция ввода
	friend ostream& operator<<(ostream& out, const TIME& l); //операция вывода
	
	//Перегрузка операторов сравнения 
	friend bool operator ==(const TIME& c1, const TIME& c2);
	friend bool operator !=(const TIME& c1, const TIME& c2);
	friend bool operator >(const TIME& c1, const TIME& c2);
	friend bool operator <(const TIME& c1, const TIME& c2);
	friend bool operator >=(const TIME& c1, const TIME& c2);
	friend bool operator <=(const TIME& c1, const TIME& c2);
};

 