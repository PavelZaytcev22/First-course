#pragma once
#pragma once
#include<iostream>
using namespace std;

template<typename T>
class plenty
{
public:

	//����������� � �����������: �������� ������ ��� s ��������� � ��������� ��
	//��������� k
	plenty(int , T );

	//����������� � �����������
	plenty(const plenty& a);

	//����������
	~plenty();

	//�������� ������������
	plenty& operator=(const plenty& a);

	//�������� ������� �� �������
	T& operator[](int index);

	bool operator<(const T n);

	//������������� �������� �����-������
	friend ostream& operator<<(ostream& out, const plenty& a);
	friend istream& operator>>(istream& in, plenty& a);

	//������������� �������� ����������� 
	friend bool operator!=(const plenty& c1, const plenty& c2);

private:
	int size;//������ �������
	T* data;//�������� �� ������������ ������ �������� ���������
};
