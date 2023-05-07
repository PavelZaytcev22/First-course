#pragma once
#include <iostream>
#include <stack>
#include <vector>
using namespace std; 



template<class T>
class Vector
{
	stack <T> s;//контейнер
	int len;//размер контейнера
public:
	Vector();//конструктор без параметров
	Vector(int n);//конструктор с параметрами
	Vector(const Vector<T>&);//конструктор копирования
	void Print();
	void max();
	void del(const T&);
    void sredn(); 
};


//копирование стека в вектор
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;

	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

//копирование вектора в стек
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

//конструктор без параметров
template <class T>
Vector<T>::Vector()
{
	len = 0;
}


//конструктор с параметром
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//добавить в стек элемент а
	}
	len = s.size();
}


//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;
	//копируем значения стека Vec.s в вектор v
	vector <T> v = copy_stack_to_vector(Vec.s);
	//копируем вектор v в стек s
	s = copy_vector_to_stack(v);
}

//печать ветора 
template <class T>
void Vector<T>::Print()
{
	//копируем стек в вектор
	vector<T> v = copy_stack_to_vector(s);
	cout << endl; 
	while (!s.empty())//пока стек не пустой
	{
		cout <<"("<< s.top() << ") ";//вывод элемента в вершине стека
		s.pop();//удаляем элемент из вершины
	}
	//копируем вектор в стек
	s = copy_vector_to_stack(v);
}

//Задание 3 
template <class T>
void Vector <T>::max() {
	vector<T> v = copy_stack_to_vector(s);
	T a = v[0];
	for (int x = 0; x < v.size(); x++) {//Нахлждение максимального элемента 
		if (a < v[x]) {
			a = v[x];
		}
	}
	v.push_back(a);
	s = copy_vector_to_stack(v);
}

//Задание 4
template <class T>
void Vector <T>::del(const T& a1) {
	vector<T> v = copy_stack_to_vector(s);
	for (int i = 0; i < v.size(); i++) {//перебор вектора
		if (v[i] == a1) {
			v.erase(v.begin() + i);
		}
	}
	s = copy_vector_to_stack(v);
}

//Задание 5
template <class T>
void Vector <T>::sredn() {
	vector<T> v = copy_stack_to_vector(s);
	T s1;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s1 = s1 + v[i];//СУМИРОВАНИЕ ВСЕХ ЭЛЕМЕНТОВ ВЕКТОРА 
	int n = v.size();
	s1 = (s1 / n);//Среднее арифметическое 
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + s1;
	s = copy_vector_to_stack(v);
}