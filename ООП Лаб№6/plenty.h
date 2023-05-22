#pragma once
#include<iostream>
using namespace std;


class Iterator
{
	friend class plenty;//������������� �����
public:
	Iterator() { elem = nullptr; }//����������� ��� ����������

	Iterator(const Iterator& it) { elem = it.elem; }//����������� �����������

	//������������� �������� ���������
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };

	//������������� �������� ���������
	void operator++() { ++elem; };

	//������������� �������� ���������
	void operator--() { --elem; }

	//������������� �������� �������������
	int& operator *() const { return*elem; }

	//�������� ������������ �������� �������� � ������ �� ������ �������
	int& operator+(const int n);

private:
	int* elem;//��������� �� ������� ���� int
};

class plenty
{
public:

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

	Iterator first() { return beg; }//���������� ��������� �� ������ �������
	Iterator last() { return end; }//���������� ��������� �� ������� ��������� ��



private:
	int size;//������ �������
	int* data;//�������� �� ������������ ������ �������� �������
	Iterator beg;//��������� �� ������ ������� �������
	Iterator end;//��������� �� ������� ��������� �� ���������
};