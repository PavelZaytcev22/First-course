#pragma once
#include <iostream>
using namespace std;

class plenty
{
public:

	void showelem();

	//����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
	//��������� k
	plenty(int a, ...);

	//����������� � �����������
	plenty(const plenty& a);

	//����������
	~plenty();

	//�������� ������������
	plenty& operator=(const plenty& a);

	//�������� ������� �� �������
	int& operator[](int index);

	bool operator<(const int n);

	//������������� �������� �����-������
	friend ostream& operator<<(ostream& out, const plenty& a);
	friend istream& operator>>(istream& in, plenty& a);

	//������������� �������� ����������� 
	friend bool operator!=(const plenty& c1, const plenty& c2);

	//������������� �������� ���������
	void operator++(); 

	//������������� �������� ���������
	void operator--();

	void operator+(const int n);

private:
	int size;//������ �������
	int* data;//�������� �� ������������ ������ �������� �������
	int* beg;//��������� �� ������ ������� �������
	int* end;//��������� �� ������� ��������� �� ���������
	int* elem;//��������� �� ������� ���� int
	int point;
};