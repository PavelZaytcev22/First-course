#pragma once
#include<iostream>
using namespace std;

struct Object {
	int cc; 
	Object* next;
};

class plenty
{
public:

	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	plenty(int size, int a[]);

	//конструктор с параметрами
	plenty(const plenty& a);

	//деструктор
	~plenty();

	//оператор присваивания
	plenty& operator=(const plenty& a);

	//операция доступа по индексу
	int& operator[](int index);

	//операция принадлежности числа множуству 
	bool operator<(const int n);

	//перегруженные операции ввода-вывода
	friend ostream& operator<<(ostream& out, const plenty& a);
	friend istream& operator>>(istream& in, const plenty& a);

	//Перегруженная операция неравенства 
	friend bool operator!=(const plenty& c1, const plenty& c2);

	//Перегруженная возвращения нужного n элемента 
	Object* operator+(const int);

private:
	int size;//размер стека
	 Object * head;//укзатель на стек
};