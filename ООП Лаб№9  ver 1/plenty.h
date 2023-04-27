#pragma once
#include <iostream>
using namespace std;

class plenty
{
public:

	void showelem();

	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	plenty(int a, ...);

	//конструктор с параметрами
	plenty(const plenty& a);

	//деструктор
	~plenty();

	//оператор присваивания
	plenty& operator=(const plenty& a);

	//операция доступа по индексу
	int& operator[](int index);

	bool operator<(const int n);

	//перегруженные операции ввода-вывода
	friend ostream& operator<<(ostream& out, const plenty& a);
	friend istream& operator>>(istream& in, plenty& a);

	//Перегруженная операция неравенства 
	friend bool operator!=(const plenty& c1, const plenty& c2);

	//перегруженная операция инкремент
	void operator++(); 

	//перегруженная операция декремент
	void operator--();

	void operator+(const int n);

private:
	int size;//размер вектора
	int* data;//укзатель на динамический массив значений вектора
	int* beg;//указатель на первый элемент вектора
	int* end;//указатель на элемент следующий за последним
	int* elem;//указатель на элемент типа int
	int point;
};