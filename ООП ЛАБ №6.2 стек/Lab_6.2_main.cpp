#include<iostream>
#include "plenty.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	int mas[5] = { 3,10,-5,6,44 };
	int bb[2] = { 3,5};
	plenty cc(5, mas);//������������� ����� 
	cout << cc[0];//������ �� ������� 
	plenty v(2, bb);//������������� ����� 
	cout << "\n!!" <<(cc != v);//����� ��������� ����������  
	cout << "\n??" << (cc < 40);//����� �������������� ��������� ����� 
	Object* nn = cc + 2;//������� ��������� �� 2 �������� � ����� �� ������ ����� 
	return 0;
}