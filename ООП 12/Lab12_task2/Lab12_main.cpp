#include "C:\Users\������������\source\repos\Lab11_task2\Money.h"
#include "C:\Users\������������\source\repos\Lab11_task2\Money.cpp"
#include <set>
#include <iostream>
using namespace std;

typedef set<Money> Tset;//���������� ��� ��� ������ � ���������� 
typedef Tset::iterator it;//�������� 

//������� �������� ���������
Tset make_set(int n)
{
	Tset m;//������ ��������� 
	Money a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(a);
	}
	return m;//���������� ������ ��� �������� ������ �������
}

//������� ������
void print_set(Tset c1) {
	cout << endl;
	for (Money y : c1) {
		cout << "(" << y << ") ";
	}
}

//������� 4
Tset del(Tset c1) {
	Money b;
	cout << "\n������� �������:";
	cin >> b;
	c1.erase(b);
	return c1;
}

//������� 5
Tset sredn(Tset c1) {
	Money* mas = new Money[c1.size()];
	Money x(0,0);
	int i = c1.size();
	int i1 = 0;
	for (Money b : c1) {
		mas[i1] = b;
		x =x+b;
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

int main() {
	setlocale(LC_ALL, "rus");
	Tset ss;
	ss = make_set(4);
	print_set(ss);
	ss = del(ss);
	print_set(ss);
	ss = sredn(ss);
	print_set(ss);
}

