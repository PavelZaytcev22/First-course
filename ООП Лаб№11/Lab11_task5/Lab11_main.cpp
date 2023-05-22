#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.h"
#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.cpp"
#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	Vector<Money> v(3);
	v.Print();
	cout << "\n Дабавление в конец вектора большего элемента";
	v.max();
	v.Print();
	cout << "\n Удаление экземпляра Money(11,22)";
	v.del(Money(11, 22));
	v.Print();
	cout << "\n Прибавление среднего значения вектора ко всем элементам";
	v.sredn();
	v.Print();
}