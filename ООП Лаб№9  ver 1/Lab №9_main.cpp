#include "plenty.h"
#include<iostream>
#include <stdio.h>
#include <stdarg.h>
using namespace std;

int main() {

	//�������������� ����
	try
	{
		plenty x(2,10);//������ �� ���� ���������
		plenty y(15,10);//������ ������
		x[0] = 13;
		cout << y[-3];//����� �� ������� ��������� 
		++x;
		++x;//����� �� ������� ��������� 
		y + 20;//����� �� ������� ��������� 
		x.showelem();
	}

	//���������� ����������
	catch (int)
	{
		cout << "ERROR!!!" << endl;
	}//��������� �� ������
	return 0;
}
