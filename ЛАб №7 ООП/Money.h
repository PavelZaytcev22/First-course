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
//Селекторы 
	int get_rub() { return rub; }
	int get_kop() { return kop; }
	//Модификаторы 
	void set_rub(long m) { rub = m; }
	void set_kop(int s) { kop = s; }

	Money& operator=(const Money&);
	friend bool operator== (const Money& c1, const Money& c2);
	friend bool operator !=(const Money& , const Money& );
	friend bool operator > (const Money&, const Money&);

	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};