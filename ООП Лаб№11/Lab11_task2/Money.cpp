#include "Money.h"
#include <iostream>
using namespace std;

//перегрузка операции присваивания
Money& Money::operator=(const Money& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	rub = t.rub;
	kop = t.kop;
	return *this;
}

//перегрузка префиксной операции инкремент
Money& Money::operator++()
{
	int temp = rub * 100 + kop;
	temp++;
	rub = temp / 100;
	kop = temp % 100;
	return *this;
}

//перегрузка постфиксной операции инкремент
Money Money::operator ++(int)
{
	int temp = rub * 100 + kop;
	temp++;
	Money t(rub, kop);
	rub = temp / 100;
	kop = temp % 100;
	return t;
}

//перегрузка бинарной операции сложения
Money Money::operator+(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 + temp2) / 100;
	p.kop = (temp1 + temp2) % 100;
	return p;
}

//перегрузка бинарной операции вычитания
Money Money::operator-(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;
	Money p;
	p.rub = (temp1 - temp2) / 100;
	p.kop = (temp1 - temp2) % 100;
	return p;
}

//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Money& t)
{
	cout << "\nРублей?"; in >> t.rub;
	cout << "\nКопеек?"; in >> t.kop;
	return in;
}

//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.rub << "," << t.kop);
}

//Перегрузка оператора равенства 
bool operator==(const Money& c1, const Money& c2) {
	if (c1.rub == c2.rub && c1.kop == c2.kop) {
		return 1;
	}
	else return 0;
}

//Перегрузка оператора неравенства 
bool operator!=(const Money& c1, const Money& c2) {
	if (c1.rub != c2.rub || c1.kop != c2.kop) {
		return 1;
	}
	else return 0;
}

//Перегрузка операции деления на экземпляр класса 
Money Money::operator/(const Money& c1 ) {
	int temp1 = rub * 100 + kop;
	int temp2 = c1.rub * 100 + c1.kop;
	temp1 = (temp1 / temp2);
	Money t ;
	t.rub = temp1 / 100;
	t.kop = temp1 % 100;
	return t;
}

//Перегрузка операции деления на константу
Money Money::operator/(const int & c1) {
	int temp1 = rub * 100 + kop;
	 temp1 = (temp1 / c1);
	Money t;
	t.rub = temp1 / 100;
	t.kop = temp1 % 100;
	return t;
}

//Перегрузка операции сравнения 
bool Money::operator >(const Money& c1) {
	int temp1 = rub * 100 + kop;
	int temp2 = c1.rub * 100 + c1.kop;
	if (temp1 > temp2) {
		return 1;
	}
	else {
		return 0;
	}
}

//Перегрузка операции сравнения 
bool Money::operator <(const Money& c1) {
	int temp1 = rub * 100 + kop;
	int temp2 = c1.rub * 100 + c1.kop;
	if (temp1 < temp2) {
		return 1;
	}
	else {
		return 0;
	}
}