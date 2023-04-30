
#include "plenty.h"
#include<iostream>
#include <stdio.h>
#include <stdarg.h>
using namespace std;

//����������� � �����������
template<class T>
plenty<T>::plenty(int s, T k) {
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = k;
}

//����������� �����������
template<class T>
plenty<T>::plenty(const plenty& a)
{
	size = a.size;
	data = new T[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];

}

//����������
template<class T>
plenty<T>::~plenty()
{
	delete[]data;
	data = 0;
}

//�������� ������������
template<class T>
plenty<T>& plenty<T>::operator=(const plenty& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	return *this;
}

//�������� ������� �� �������
template<class T>
T& plenty<T>::operator[] (int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}

//�������� �������������� ����� ���������
template<class T>
bool plenty<T>::operator<( T n) {
	for (int i = 0; i < size; i++) {
		if (data[i] == n) {
			return 1;
		}
	}
	return 0;
}

//�������� ��� �����-�����
template<class T>
ostream& operator<<(ostream& out, const plenty<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}

template<class T>
istream& operator>>(istream& in, plenty<T>& a)
{
	for (int i = 0; i < a.size; ++i)
		in >> a.data[i];
	return in;
}

//���������� ��������� ����������� 
template<class T>
bool operator!=(const plenty<T>& c1, const plenty<T>& c2) {
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
