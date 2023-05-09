#pragma once
#include <iostream>
#include <set> 
using namespace std;

//параметризированный класс
template<class T>
class Vector
{
	set<T> v1; //контейнер словарь
	int len;
public:
	Vector(void); //конструктор без параметров
	Vector(int n); //конструктор с параметрами
	void Print(); //печать
	~Vector(void); //деструктор
	void del();//Задание 4 
	void sredn();//Задание 5 
};


//реализация методов
//конструктор без параметров
template <class T>
Vector<T>::Vector()
{
	len = 0;
}

//деструктор
template <class T>
Vector<T>::~Vector(void)
{
}

//конструктор c параметрами
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v1.insert(a);
	}
	len = v1.size();
}

//вывод контейнера
template <class T>
void Vector<T>::Print()
{
	cout << endl;
		for ( T per:v1) {
			cout << per << " - ";
		}
	cout << endl;
}

template <class T>
void Vector<T>::del() {
	T b;
	cout << "\nУдалить элемент:";
	cin >> b;
	v1.erase(b);
}

template <class T>
void Vector<T>::sredn() {
	T* mas = new T[v1.size()];
	T x;
	int i = v1.size();
	int i1 = 0;
	for (T b : v1) {
		mas[i1] = b;
		x = x + b;
		i1++;
	}
	x = (x / v1.size());//СРЕДНЕЕ ЗНАЧЕНИЕ ЭЛЕМЕНТОВ МНОЖЕСТВА 
	for (int m = 0; m < i; m++) {//Удаление всех элементов из множества 
		v1.erase(mas[m]);
	}
	for (int m = 0; m < i; m++) {
		v1.insert(mas[m] + x);
	}
}