#pragma once
#include <iostream>
#include <set> 
using namespace std;

//������������������� �����
template<class T>
class Vector
{
	set<T> v1; //��������� �������
	int len;
public:
	Vector(void); //����������� ��� ����������
	Vector(int n); //����������� � �����������
	void Print(); //������
	~Vector(void); //����������
	void del();//������� 4 
	void sredn();//������� 5 
};


//���������� �������
//����������� ��� ����������
template <class T>
Vector<T>::Vector()
{
	len = 0;
}

//����������
template <class T>
Vector<T>::~Vector(void)
{
}

//����������� c �����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v1.insert(a);
	}
	len = v1.size();
}

//����� ����������
template <class T>
void Vector<T>::Print()
{
	cout << endl;
		for ( T per:v1) {
			cout << per << " - ";
		}
	cout << endl;
}

template <class T>
void Vector<T>::del() {
	T b;
	cout << "\n������� �������:";
	cin >> b;
	v1.erase(b);
}

template <class T>
void Vector<T>::sredn() {
	T* mas = new T[v1.size()];
	T x;
	int i = v1.size();
	int i1 = 0;
	for (T b : v1) {
		mas[i1] = b;
		x = x + b;
		i1++;
	}
	x = (x / v1.size());//������� �������� ��������� ��������� 
	for (int m = 0; m < i; m++) {//�������� ���� ��������� �� ��������� 
		v1.erase(mas[m]);
	}
	for (int m = 0; m < i; m++) {
		v1.insert(mas[m] + x);
	}
}