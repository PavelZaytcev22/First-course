#pragma once
#include <cmath>
#include <iostream>
using namespace std; 

class fraction
{
public:
	double first;
	double second;
	void Init(double, double);//����� ��� ������������� �����
	void Read();//����� ��� ������ �������� �����
	void Show();//����� ��� ������ �������� �����
	double Power();//���������� �������
	void distance();//���������� ���������� �� ����� 
};
