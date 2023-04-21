#include "Triad.h"
#include <iostream>
using namespace std;

//Переопределенная виртуальная функция 
void Triad::Show() {
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << "\nthird = " << third;
}

//Конструкторы 
Triad::Triad() {
	first = 0;
	second = 0;
	third = 0;
}
Triad::Triad(int m, int s, int x) {
	first = m;
	second = s;
	third = x;
}
Triad::Triad(const Triad& t) {
	first = t.first;
	second = t.second;
	third = t.third;
}

//Перегрузка операторов присваивания 
Triad& Triad::operator=(const Triad& c) {
	if (&c == this)return *this;
	first = c.first;
	second = c.second;
	third = c.third;
	return *this;
}

//Перегрузка потоковых операторов вводы и вывода 
istream& operator>>(istream& in, Triad& t) {
	cout << "\nfirst:"; in >> t.first;
	cout << "\nsecond:"; in >> t.second;
	cout << "\nthird:"; in >> t.third;
	return in;
}
ostream& operator<<(ostream& out, const Triad& t) {
	out << "\nfirst = " << t.first;
	out << "\nsecond = " << t.second;
	out << "\nthird = " << t.third;
	return out;
}

//Перегрузка операторов сравнения
bool operator==(const Triad& c1, const Triad& c2) {
	if ((c1.first == c2.first) && (c1.second == c2.second) && (c1.third == c2.third)) {
		return 1;
	}
	else return 0;
}
bool operator!=(const Triad& c1, const Triad& c2) {
	if ((c1.first != c2.first) || (c1.second != c2.second) || (c1.third != c2.third)) {
		return 1;
	}
	else return 0;
}