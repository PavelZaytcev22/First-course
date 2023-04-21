#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Triad:public Object {
	//�������� ������ 
protected:
	int first;
	int second;
	int third;
public:
	void Show();//������� ��� ��������� ��������� ������ � ������� ���������

	//������������ 
	Triad();
	Triad(int, int, int);
	Triad(const Triad&);

	//���������� 
	virtual ~Triad() {};

	//������������� 
	int get_first() { return first; }
	int get_second() { return second; }
	int get_third() { return third; };

	//������������ 
	void set_first(int m) { first = m; }
	void set_second(int s) { second = s; }
	void set_third(int x) { third = x; }
	//���������� ��������� ������������ 
	Triad& operator = (const Triad&);

	//���������� ���������� ��������� ����� ������ 
	friend istream& operator>>(istream& in, Triad& t);
	friend ostream& operator<<(ostream& out, const Triad& t);

	//���������� ���������� ��������� 
	friend bool operator ==(const Triad& c1, const Triad& c2);
	friend bool operator !=(const Triad& c1, const Triad& c2);
};
