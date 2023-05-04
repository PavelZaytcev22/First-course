#pragma once
#include<iostream>
using namespace std;

struct Object {
	int cc; 
	Object* next;
};

class plenty
{
public:

	//����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
	//��������� k
	plenty(int size, int a[]);

	//����������� � �����������
	plenty(const plenty& a);

	//����������
	~plenty();

	//�������� ������������
	plenty& operator=(const plenty& a);

	//�������� ������� �� �������
	int& operator[](int index);

	//�������� �������������� ����� ��������� 
	bool operator<(const int n);

	//������������� �������� �����-������
	friend ostream& operator<<(ostream& out, const plenty& a);
	friend istream& operator>>(istream& in, const plenty& a);

	//������������� �������� ����������� 
	friend bool operator!=(const plenty& c1, const plenty& c2);

	//������������� ����������� ������� n �������� 
	Object* operator+(const int);

private:
	int size;//������ �����
	 Object * head;//�������� �� ����
};