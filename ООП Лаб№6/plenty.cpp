#include "plenty.h"
#include<iostream>
#include <stdio.h>
#include <stdarg.h>
using namespace std;

//конструктор с параметрами
plenty::plenty(int a, ...) {
	if (a == 0) {//Если длинна введена 0
		size = 0;
		data = 0;
	}
	else {
		int* var = new int(a + 1);//Буферный массив
		for (int i = 0; i < a; i++) {
			var[i] = 0;//Запонение буферного массива нулями 
		}
		va_list factor;
		va_start(factor, a);
		for (int i = 0; i < a; i++) {
			var[i] = va_arg(factor, int);//Запонение буферного массива числами из параметра конструктора 
		}
		va_end(factor);

		int cifr = 1;//счетчик цифр в массиве 

		if (a > 1) {
			int buff;
			for (int i = 0; i < a; i++) {//Сортировка массива пузырьком 
				for (int j = 0; j < a - i - 1; j++) {
					if (var[j] > var[j + 1]) {
						buff = var[j];
						var[j] = var[j + 1];
						var[j + 1] = buff;
					}
				}
			}
			buff = var[0];
			for (int i = 1; i < a; i++) {//Счет уникальных цифр 
				if (var[i] != buff) {
					cifr++;
					buff = var[i];
				}
			}
			size = cifr;
			data = new int(size);//Инициализация множества 
			buff = var[0];
			data[0] = buff;
			cifr = 1;
			while (size != cifr) {	//Заполнение множества 
				for (int j = 1; j < a; j++) {
					if (var[j] != buff) {
						buff = var[j];
						data[cifr] = buff;
						cifr++;
					}
				}
			}
			beg.elem = &data[0];
			end.elem = &data[size-1];
		}
		else {
			size = cifr;
			data = new int(size);//Инициализация множества 
			data[0] = var[0];
			beg.elem = &data[0];
			end.elem = &data[0];
		}
		delete var;
	}
}

//конструктор копирования
plenty::plenty(const plenty& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
}

//деструктор
plenty::~plenty()
{
	delete[]data;
	data = 0;

}

//операция присваивания
plenty& plenty::operator=(const plenty& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	beg = a.beg;
	end = a.end;
	return *this;
}

//операция доступа по индексу
int& plenty::operator[] (int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}

//операция принадлежности числа множеству
bool plenty::operator<(const int n) {
	for (int i = 0; i < size; i++) {
		if (data[i] == n) {
			return 1;
		}
	}
	return 0;
}

//операции для ввода-выода
ostream& operator<<(ostream& out, const plenty& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}
istream& operator>>(istream& in, plenty& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}

//Перегрузка оператора екравенства 
bool operator!=(const plenty& c1, const plenty& c2) {
	if (c1.size != c2.size) {
		return 1;
	}
	else {
		for (int i = 0; i < c2.size; i++) {
			if (c1.data[i] != c2.data[i]) {
				return 1;
			}
		}
		return 0;
	}

}

//Перегрузка оператора перехода по контейнеру в право 
int& Iterator:: operator+ (const int n) {
	for (int x = 0; x < n - 1; x++) {
		++elem;
	}
	return *elem;
}