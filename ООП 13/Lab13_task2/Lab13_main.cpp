#include <algorithm>
#include <functional>
#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.h"
#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.cpp"
#include <iostream>
using namespace std;

/*
template <class T>
T s;

template <class T>
struct Greater_s //больше, чем s
{
	bool operator()(Money t)
	{
		if (t > s) return true; else return false;
	}
};



template <class T>
struct Equal_s
{
	bool operator()(Money t)
	{
		return t == s;
	}
};

*/


template <class T>
struct Comp_less // для сортировки по убыванию

{
public:
	bool operator()(T t1, T t2)
	{
		if (t1 > t2)return true;
		else return false;
	}
};



template <class T> //T - параметр шаблона
class Vector
{
public:
	//конструктор с параметрами: выделяет память под s элементов и заполняет их
	//значением k
	Vector(int s);
	//конструктор с параметрами
	Vector(const Vector<T>& a);
	//деструктор
	~Vector();
	//оператор присваивания
	Vector& operator=(const Vector<T>& a);
	//операция доступа по индексу
	T& operator[](int index);
	//операция для добавление константы
	Vector operator+(const T k);
	//операция, возвращающая длину вектора
	int operator()();
	//перегруженные операции ввода-вывода
	// <> - указывают на то, что функция является шаблоном
	friend ostream& operator << (ostream& out, const Vector<T>& a);
	friend istream& operator >> (istream& in, Vector<T>& a);
//функции по заданиям 
	void povozr();
	void poubiv();
	void print();
	T* end();
	T* begin();
	void maxend();
	void del();
	void sredn();
private:
	int size;//размер вектора
	T* data;//укзатель на динамический массив значений вектора
	T* iterator;
};

//опрeделение функций


template <class T>
T* Vector <T> :: end(){
	return &data[size - 1];
}

template <class T>
T* Vector <T> ::begin() {
	return &data[0];
}


//конструктор с параметрами
template <class T>
Vector<T>::Vector(int s)
{
	T k;
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		cin >> k;
		data[i] = k;
	}
	iterator = &data[0];
}

//конструктор копирования
template <class T>
Vector<T>::Vector(const Vector& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	iterator = &data[0];
}

//деструктор
template <class T>
Vector<T>::~Vector()

{
	delete[]data;
	data = 0;
}

//операция присваивания
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = a.data[i];
	return *this;
}

//операция доступа по индексу
template <class T>
T& Vector<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}

//операция для добавления константы
template <class T>
Vector<T> Vector<T>::operator+(const T k)//+k
{
	Vector<T> temp(size, k);//инициализируем временный вектор любым значением
	for (int i = 0; i < size; ++i)
		temp.data[i] = data[i] + k;
	return temp;
}

//операция для получения длины вектора
template <class T>
int Vector<T>::operator ()()
{
	return size;
}

//операции для ввода-вывода
template <class T>
ostream& operator<< (ostream& out, const Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
template <class T>
istream& operator>> (istream& in, Vector<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}

//Сортировка по убыванию
template <class T>
void Vector<T> ::poubiv(){	
	sort(data, data + size, greater<T>{});
}

//Сортировка по возрастанию
template <class T>
void Vector<T> ::povozr() {
	sort(data, data + size);
}

//Функция вывода 
template <class T>
void Vector<T> ::print() {
	cout << endl;
	for (int i = 0; i < size; ++i)
		cout <<data[i] << "--";
}

//Функция помещения максимального элемента в конец вектора 
template <class T>
void Vector<T> ::maxend() {
	iterator = max_element(data, data + size);
	T buff = *iterator;
	*iterator = data[size - 1];
	data[size - 1] = buff;
}
//Функция удаления элемента
template <class T>
void Vector<T> ::del() {
	cout << "\nDelete";
	T* bb = new T[size - 1];
	T a; 
	cin >> a;
	bool c1 = 0;
	for (int i = 0; i < size; i++) {
		if (data[i] == a) {
			c1 = 1;
		}
	}
	if (c1 == 1) {
		iterator = remove_copy(data, data + size, bb, a);
		size--;
		data = bb;
	}
	else {
		cout << "\nЧиcло не найдено";
	}
}

//Функция прибаления среднего значения
template <class T>
void Vector<T> ::sredn() {
	T s;
	T* bb = new T[size];
	for (int i = 0; i < size; i++)
		s = s + data[i];
	s = (s / size);
	for (int i = 0; i < size; i++)
		bb[i] = s;
	cout << "sredn=" << s << endl;
	transform(data, data + size, bb, bb+size, plus<T>());//не работает 
	for (int i = 0; i < size; i++)
		data[i] = data[i] + s;
		
}

void main() {
	setlocale(LC_ALL,"rus");
	Vector <Money> v1(3);
	v1.print();
	v1.maxend();
	v1.print();
	v1.del();
	v1.print();
	v1.sredn();
	v1.print();
}