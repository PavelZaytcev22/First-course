#include <iostream>
#include <set>
#include "C:\Users\������������\source\repos\Lab11_task2\Money.h"
#include "C:\Users\������������\source\repos\Lab11_task2\Money.cpp"
#include <algorithm>
#include <functional>
using namespace std;

typedef set<Money> Tset;//���������� ��� ��� ������ �� ����������
typedef Tset::iterator it;//��������


//������� ��� �������� ��������� 
Tset make_set(int n)
{
	Tset m;//������ ��������� 
	Money  a;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
		cin >> a;
		//������� ���� � ��������� �� � ���������
		m.insert(a);
	}
	return m;//���������� ������� ��� ��������� ������ �������
}

//������� ��� ������ ��������� 
void print_set(Tset m)
{
	cout << endl;
	for (Money n : m)
		cout << " (" << n << ") ";
}

Tset del(Tset nn) {
	Tset bb;
		Money  a;
		cout << "del?: ";
		cin >> a;
		bool c1 = 0;
		for (Money i : nn) {
			if (i == a) {
				c1 = 1;
			}
		}
		if (c1 == 1) {
			nn.erase(a);
		}
		else {
			cout << "\n��c�� �� �������";
		}
		return nn;
}

Tset sredn(Tset c1) {
	Money* mas = new Money[c1.size()];
	Money  x;
	int i = c1.size();
	int i1 = 0;
	for (Money  b : c1) {
		mas[i1] = b;
		x =x+ b;
		i1++;
	}
	x = (x / c1.size());//������� �������� ��������� ��������� 
	for (int m = 0; m < i; m++) {//�������� ���� ��������� �� ��������� 
		c1.erase(mas[m]);
	}
	for (int m = 0; m < i; m++) {
		c1.insert(mas[m] + x);
	}
	return c1;
}



void main() {
	setlocale(LC_ALL, "rus");
	Tset ss;
	ss = make_set(3);
	print_set(ss);
	ss=del(ss);
	print_set(ss);
	ss = sredn(ss);
	print_set(ss);

}