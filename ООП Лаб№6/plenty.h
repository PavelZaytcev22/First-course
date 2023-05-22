#pragma once
#include<iostream>
using namespace std;


class Iterator
{
	friend class plenty;//дружественный класс
public:
	Iterator() { elem = nullptr; }//конструктор без параметров

	Iterator(const Iterator& it) { elem = it.elem; }//конструктор копирования

	//перегруженные операции сравнения
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };

	//перегруженная операция инкремент
	void operator++() { ++elem; };

	//перегруженная операция декремент
	void operator--() { --elem; }

	//перегруженная операция разыменования
	int& operator *() const { return*elem; }

	//Оператор перегруженой операции перехода в вправо на нужный элемент
	int& operator+(const int n);

private:
	int* elem;//указатель на элемент типа int
};

class plenty
{
public:

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

	Iterator first() { return beg; }//возвращает указатель на первый элемент
	Iterator last() { return end; }//возвращает указатель на элемент следующий за



private:
	int size;//размер вектора
	int* data;//укзатель на динамический массив значений вектора
	Iterator beg;//указатель на первый элемент вектора
	Iterator end;//указатель на элемент следующий за последним
};