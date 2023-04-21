#include "Object.h"
#include "Triad.h"
#include "TIME.h"
#include "Vector.h"
#include <iostream>

using namespace std;
void main()
{
	Triad a;
	cin >> a;
	cout << a << endl;//вывод с помощью перегруженной операции
	Object * p = &a;
	p->Show();//вывод с помощью метода Show() и указателя
		Vector v(5);//вектор из 5 элементов
		Triad a;//объект класса Car
		cin >> a;
		TIME b;// объект класса Lorry
		cin >> b;
		Object* p = &a;//ставим указатель на объект класса Car
		v.Add(p);//добавляем объект в вектор
		p = &b;//ставим указатель на объект класса Lorry
		v.Add(p); //добавляем объект в вектор
		cout << v;//вывод вектора
	
}