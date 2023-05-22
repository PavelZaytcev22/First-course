#pragma once
#include <iostream>
using namespace std;

class Money
{
	long rub;
	int kop;
public:
	Money() { rub = 0; kop = 0; };
	Money(long c, int m) { rub = c; kop = m; }
	Money(const Money& t) { rub = t.rub; kop = t.kop; }
	~Money() {};
	int get_rub() { return rub; }
	int get_kop() { return kop; }
	void set_rub(long m) { rub = m; }
	void set_kop(int s) { kop = s; }

	//перегруженные операции
	Money& operator=(const Money&);
	Money& operator++();
	Money operator++(int);//постфиксная операция
	Money operator+(const Money&);
	Money operator-(const Money&);
	Money operator/(const Money&);
	Money operator/(const int&);
	bool operator >(const Money&);
	bool operator <(const Money&);

	friend bool operator== (const Money& c1, const Money& c2);
	friend bool operator!= (const Money& c1, const Money& c2);


	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};
