#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.h"
#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.cpp"
#include "Container.h"
#include <iostream>
#include <set>
using namespace std;



void main()
{
	setlocale(LC_ALL, "rus");
	int n; //количество элементов в контейнере
	cout << "N?"; cin >> n;
	Vector <Money> v(n);//создать контенер
	v.Print();//напечатать контейнер
	v.del();//Удалить элемент 
	v.Print();//напечатать контейнер
	v.sredn();//Прибавить среднее значение 
	v.Print();//напечатать контейнер
}