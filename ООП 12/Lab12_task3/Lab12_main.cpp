#include "C:\Users\������������\source\repos\Lab11_task2\Money.h"
#include "C:\Users\������������\source\repos\Lab11_task2\Money.cpp"
#include "Container.h"
#include <iostream>
#include <set>
using namespace std;



void main()
{
	setlocale(LC_ALL, "rus");
	int n; //���������� ��������� � ����������
	cout << "N?"; cin >> n;
	Vector <Money> v(n);//������� ��������
	v.Print();//���������� ���������
	v.del();//������� ������� 
	v.Print();//���������� ���������
	v.sredn();//��������� ������� �������� 
	v.Print();//���������� ���������
}