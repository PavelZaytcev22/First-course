#include <iostream>
#include <set>
#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.h"
#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.cpp"
#include <algorithm>
#include <functional>
using namespace std;

typedef set<Money> Tset;//определяем тип для работы со множеством
typedef Tset::iterator it;//итератор


//Функция для создания множества 
Tset make_set(int n)
{
	Tset m;//пустое множнство 
	Money  a;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
		cin >> a;
		//создаем пару и добавляем ее в множество
		m.insert(a);
	}
	return m;//возвращаем словарь как результат работы функции
}

//функция для печати множество 
void print_set(Tset m)
{
	cout << endl;
	for (Money n : m)
		cout << " (" << n << ") ";
}

Tset del(Tset nn) {
	Tset bb;
		Money  a;
		cout << "del?: ";
		cin >> a;
		bool c1 = 0;
		for (Money i : nn) {
			if (i == a) {
				c1 = 1;
			}
		}
		if (c1 == 1) {
			nn.erase(a);
		}
		else {
			cout << "\nЧиcло не найдено";
		}
		return nn;
}

Tset sredn(Tset c1) {
	Money* mas = new Money[c1.size()];
	Money  x;
	int i = c1.size();
	int i1 = 0;
	for (Money  b : c1) {
		mas[i1] = b;
		x =x+ b;
		i1++;
	}
	x = (x / c1.size());//СРЕДНЕЕ ЗНАЧЕНИЕ ЭЛЕМЕНТОВ МНОЖЕСТВА 
	for (int m = 0; m < i; m++) {//Удаление всех элементов из множества 
		c1.erase(mas[m]);
	}
	for (int m = 0; m < i; m++) {
		c1.insert(mas[m] + x);
	}
	return c1;
}



void main() {
	setlocale(LC_ALL, "rus");
	Tset ss;
	ss = make_set(3);
	print_set(ss);
	ss=del(ss);
	print_set(ss);
	ss = sredn(ss);
	print_set(ss);

}