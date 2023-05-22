#include "plenty.h"
#include "Error.h"
#include <stdio.h>
#include <stdarg.h>
#include<iostream>
using namespace std;

//������� ������ ��������������� ���������
void plenty::showelem() {
	cout << endl << '(' << *elem << ')';
}


//����������� � �����������
plenty::plenty(int a, ...) {
	if (a == 0) {//���� ������ ������� 0
		size = 0;
		data = 0;
	}
	else {
		int* var = new int(a + 1);//�������� ������
		for (int i = 0; i < a; i++) {
			var[i] = 0;//��������� ��������� ������� ������ 
		}
		va_list factor;
		va_start(factor, a);
		for (int i = 0; i < a; i++) {
			var[i] = va_arg(factor, int);//��������� ��������� ������� ������� �� ��������� ������������ 
		}
		va_end(factor);

		int cifr = 1;//������� ���� � ������� 

		if (a > 1) {
			int buff;
			for (int i = 0; i < a; i++) {//���������� ������� ��������� 
				for (int j = 0; j < a - i - 1; j++) {
					if (var[j] > var[j + 1]) {
						buff = var[j];
						var[j] = var[j + 1];
						var[j + 1] = buff;
					}
				}
			}
			buff = var[0];
			for (int i = 1; i < a; i++) {//���� ���������� ���� 
				if (var[i] != buff) {
					cifr++;
					buff = var[i];
				}
			}
			size = cifr;
			data = new int(size);//������������� ��������� 
			buff = var[0];
			data[0] = buff;
			cifr = 1;
			while (size != cifr) {	//���������� ��������� 
				for (int j = 1; j < a; j++) {
					if (var[j] != buff) {
						buff = var[j];
						data[cifr] = buff;
						cifr++;
					}
				}
			}
			beg = &data[0];
			elem = beg;
			end = &data[size - 1];
		}
		else {
			size = cifr;
			data = new int(size);//������������� ��������� 
			data[0] = var[0];
			beg = &data[0];
			elem = beg;
			end = &data[0];
		}
		delete var;
	}
}

//����������� �����������
plenty::plenty(const plenty& a)
{
	size = a.size;
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	beg = a.beg;
	elem = beg;
	point = 0;
	end = a.end;
}

//����������
plenty::~plenty()
{
	delete[]data;
	data = nullptr;
	beg = nullptr;
	elem = nullptr;
	end = nullptr;
}

//�������� ������������
plenty& plenty::operator=(const plenty& a)
{
	if (this == &a)return *this;
	size = a.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
	beg = a.beg;
	elem = beg;
	end = a.end;
	return *this;
}

//�������� ������� �� �������
int& plenty::operator[] (int index)
{
	if (index < 0) throw IndexError1() ;//���� ������ �������������, �� ������������ ����������
	//���� ������ ������ ������ �������, �� ������������ ����������
	if (index >= size) throw IndexError2();
	return data[index];
}

//�������� �������������� ����� ���������
bool plenty::operator<(const int n) {
	for (int i = 0; i < size; i++) {
		if (data[i] == n) {
			return 1;
		}
	}
	return 0;
}

//�������� ��� �����-�����
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

//���������� ��������� ����������� 
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

//���������� ��������� �������� �� ���������� � ����� 
void plenty:: operator+ (const int n) {
	if (point + n > size - 1) throw 1;
	else {
		for (int x = 0; x < n; x++) {
			++elem;
		}
	}
}

//������������� �������� ���������
void plenty:: operator++() {
	if (point == size - 1) throw IndexError2() ;
	else {
		++elem;
		point++;
	}
}

//������������� �������� ���������
void plenty:: operator--() {
	if (point == 0) throw IndexError1(); 
	else {
		--elem;
		point--;
	}
}