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

 bool operator > (const Money& c1, const Money& c2) {
	 if (c1.rub > c2.rub) {
		 return 1;
	 }
	 else {
		 if (c1.rub == c2.rub) {
			 if (c1.kop > c2.kop) {
				 return 1;
			 }
			 else {
				 return 0;
			 }
		 }
		 else {
			 return 0;
		 }
	 }
}

//Перегрузка оператора неравенства 
bool operator!= (const Money& c1, const Money& c2) {
	if (c1.rub != c2.rub || c1.kop != c2.kop) {
		return 1;
	}
	else return 0;
}

//Перегрузка оператора равенства 
bool operator==(const Money& c1, const Money& c2) {
	if (c1.rub == c2.rub && c1.kop == c2.kop) {
		return 1;
	}
	else return 0;
}
