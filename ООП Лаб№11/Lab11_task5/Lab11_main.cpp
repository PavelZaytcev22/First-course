#include "C:\Users\������������\source\repos\Lab11_task2\Money.h"
#include "C:\Users\������������\source\repos\Lab11_task2\Money.cpp"
#include <iostream>
#include <stack>
#include <vector>
#include "Vector.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	Vector<Money> v(3);
	v.Print();
	cout << "\n ���������� � ����� ������� �������� ��������";
	v.max();
	v.Print();
	cout << "\n �������� ���������� Money(11,22)";
	v.del(Money(11, 22));
	v.Print();
	cout << "\n ����������� �������� �������� ������� �� ���� ���������";
	v.sredn();
	v.Print();
}