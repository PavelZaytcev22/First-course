#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc); //������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int n;
	Money p;
	cout << "N?"; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;//���� ��������� ������� �� ������������ ������
		stream << p << "\n";//������ ������� � �������� �����
	}
	stream.close();//������� �����
	return n;//������� ���������� ���������� ��������
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	Money p; int i = 0;
	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_fromfile(const char* f_name, Money number)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int i = 0; 
	Money p;
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����
		if (stream.eof())break;
		i++;
		//���� ������ number �� ����� k, �� ���������� ��� �� �������������� ����
		if (p != number) { 
			temp << p; 
		}
		else {
			i--;
		}
	}
	//������� �����
	stream.close();
	temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}

int minus_150(const char* f_name, Money number)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int i = 0;
	Money p;
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����
		if (stream.eof())break;
		i++;
		//���� ������ number ����� p, �� �������� �� ���� 1�50 ��� � ���������� ��� �� �������������� ����
		if (p == number)
		{
			p - 1.50;
			temp << p;
		}
		else {
			temp << p;
		}
	}
	//������� �����
	stream.close();
	temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}

int dobav(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//������� ��� ������
	fstream stream(f_name, ios::in);//������� ��� ������
	if (!stream)return -1;//������ �������� �����
	int i = 0;
	Money p;//�������� ��������� ������ ��� ���������� � ���� ������ � �����  
	Money x;//�������� ��������� ������ ��� ������ ����� ��������� 
	int n=0;
	do {
		cout << "\n������� ����������� ����������� ������� �� ������ ��������:";
		cin >> n;
	} while (n <= 0);
	while (stream >> p)//���� ��� ����� ����� ��������� ������ �������
	{
		//���� �������� ������� ����� �����,�� ����� �� �����
		if (stream.eof())break;
		i++;
		//���� ������ number �� ����� k, �� ���������� ��� �� �������������� ����
		if (i == k) {
			temp << p;
			for (int c = 0; c < n; c++){
				cout << endl<< c+1 << "-�� ���������";
				cin >> x;//������������� ������ ���������� ������ 
				temp << x;//������ � ���� ������ ���������� ������ 
				i++;
			}
		}
		else {
			temp << p;
		}
	}

	//������� �����
	stream.close();
	temp.close();
	remove(f_name);//������� ������ ����
	rename("temp", f_name);// ������������� temp
	return i;//���������� �����������
}