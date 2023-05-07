#pragma once
#include <vector>
#include <iostream>
using namespace std;
//шаблон класса

template<class T>
class Vector
{
	vector <T> v;//последовательный контейнер для хранения элементов вектора
	int len;
public:
	Vector(void);//конструктор без параметра
	Vector(int n);//конструктор с параметром
	void Print();//печать
	~Vector(void);//деструктор
	void dobav();
	void del(T a1);
	void sredn();
};

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

//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}

//печать
template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << '(' << v[i] << ") ";
		cout << endl;
}

template <class T>
void Vector<T>::dobav()
{
	T a=v[0]; 
	for (int x = 0; x < v.size(); x++) {
		if (a < v[x]) {
			a = v[x];
		}
	}
	v.push_back(a);
}

template <class T>
void Vector<T>::del(T a1)
{
	for (int i = 0; i < v.size(); i++) {//перебор вектора
		if (v[i] == a1) {
			v.erase(v.begin() + i);
		}
	}
}


template <class T>
void Vector<T>::sredn() {
	T s;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s =s+v[i];//СУМИРОВАНИЕ ВСЕХ ЭЛЕМЕНТОВ ВЕКТОРА 
	int n = v.size();
	s = (s / n);//Среднее арифметическое 
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + s;
}