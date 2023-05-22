#pragma once
#pragma once
#include <iostream>
#include <fstream>
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
	Money operator+(const Money&);
	Money operator-(const Money&);
	Money& operator-(double);//постфиксная операция

	friend bool operator== (const Money& , const Money& );
	friend bool operator!= (const Money&, const Money& );

	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);

	//Функции для записи в файл 
	friend fstream& operator>>(fstream& fin, Money& p);
	friend fstream& operator <<(fstream& fout, const Money& p);
};