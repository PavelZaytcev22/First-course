#include<iostream>
#include "plenty.h"
using namespace std;

//Конструктор с параметрами
plenty::plenty(int n, int a[]) {
	if (n == 1){
		Object* c = new(Object);
		c->next = NULL;
		c->cc = a[0];
		head = c;
		size = 1;
	}
	else{
		Object* c = new(Object);
		c->next = NULL;
		c->cc = a[0];
		head = c;
		for (int i = 1; i < n; i++) {
			Object* c = new(Object);
			c->next = head;
			c->cc = a[i];
			head = c;
		}
		size = n;
    }
}

//Конструктор копирования 
plenty::plenty(const plenty& a) {
	size = a.size;
	head = a.head;
}

//Деструктор 
plenty::~plenty() {

}

//перегрузка операции присваивания
plenty& plenty::operator=(const plenty& a) {
	if (this == &a) return *this;
	size = a.size;
	head = a.head;
	return *this;
}

//перегруженная операция доступа по индексу 
int& plenty::operator[](int index) {
	if (index >= size) {
	
	}	
	else {
		Object* c = head;
		for (int v = 0; v < index; v++) {
			c = c->next;
		}
		return c->cc;
	}
}

//перегруженная операция пренадлежности константы стеку 
bool plenty::operator<(const int n) {
	Object* c = head;
	if (c->cc == n) return true;
	for (int v = 1; v < size; v++) {
		c = c->next;
		if (c->cc == n) return true;
	}
	return false;
}

//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const plenty& a) {
	Object* c = a.head;
	out << " (" << c->cc<<")";
	for (int i = 1; i < a.size; i++) {
		c=c->next;
		out << "<- (" << c->cc<<')';
	}
	return out;
}

//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, const plenty& a) {
	Object* c = a.head;
	cout << "\nВведите число:"; in>>  c->cc;
	for (int i = 1; i < a.size; i++) {
		c = c->next;
		cout << "Введите число:";
       in >> c->cc;
	}
	return in;
}

//перегрузка некравенства 
bool operator!=(const plenty& c1, const plenty& c2) {
	if (c1.size != c2.size) {
		return 1;
	}
	else {
		Object* b1 = c1.head;
		Object* b2 = c2.head;
		for (int i = 0; i < c2.size; i++) {
			if ((b1->cc) != (b2->cc)) {
				return 1;
			}
			b1 = b1->next;
			b2 = b2->next;
		}
		return 0;
	}
}

Object* plenty::operator+(const int n) {
	Object* c = head;
	if (size <= n) return NULL;
	for (int v = 1; v < size; v++) {
		c = c->next;
	}
	return c;
}