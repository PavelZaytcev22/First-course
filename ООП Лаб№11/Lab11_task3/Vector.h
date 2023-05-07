#pragma once
#include <vector>
#include <iostream>
using namespace std;
//������ ������

template<class T>
class Vector
{
	vector <T> v;//���������������� ��������� ��� �������� ��������� �������
	int len;
public:
	Vector(void);//����������� ��� ���������
	Vector(int n);//����������� � ����������
	void Print();//������
	~Vector(void);//����������
	void dobav();
	void del(T a1);
	void sredn();
};

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

//����������� � ����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}

//������
template <class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
		cout << '(' << v[i] << ") ";
		cout << endl;
}

template <class T>
void Vector<T>::dobav()
{
	T a=v[0]; 
	for (int x = 0; x < v.size(); x++) {
		if (a < v[x]) {
			a = v[x];
		}
	}
	v.push_back(a);
}

template <class T>
void Vector<T>::del(T a1)
{
	for (int i = 0; i < v.size(); i++) {//������� �������
		if (v[i] == a1) {
			v.erase(v.begin() + i);
		}
	}
}


template <class T>
void Vector<T>::sredn() {
	T s;
	//������� �������
	for (int i = 0; i < v.size(); i++)
		s =s+v[i];//����������� ���� ��������� ������� 
	int n = v.size();
	s = (s / n);//������� �������������� 
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + s;
}