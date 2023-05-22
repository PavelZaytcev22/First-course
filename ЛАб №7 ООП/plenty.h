#pragma once
#pragma once
#include<iostream>
using namespace std;

template<typename T>
class plenty
{
public:

	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	plenty(int , T );

	//конструктор с параметрами
	plenty(const plenty& a);

	//деструктор
	~plenty();

	//оператор присваивания
	plenty& operator=(const plenty& a);

	//операция доступа по индексу
	T& operator[](int index);

	bool operator<(const T n);

	//перегруженные операции ввода-вывода
	friend ostream& operator<<(ostream& out, const plenty& a);
	friend istream& operator>>(istream& in, plenty& a);

	//Перегруженная операция неравенства 
	friend bool operator!=(const plenty& c1, const plenty& c2);

private:
	int size;//размер вектора
	T* data;//укзатель на динамический массив значений множества
};
