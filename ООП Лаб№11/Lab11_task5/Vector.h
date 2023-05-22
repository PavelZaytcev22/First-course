#pragma once
#include <iostream>
#include <stack>
#include <vector>
using namespace std; 



template<class T>
class Vector
{
	stack <T> s;//���������
	int len;//������ ����������
public:
	Vector();//����������� ��� ����������
	Vector(int n);//����������� � �����������
	Vector(const Vector<T>&);//����������� �����������
	void Print();
	void max();
	void del(const T&);
    void sredn(); 
};


//����������� ����� � ������
template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;

	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

//����������� ������� � ����
template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

//����������� ��� ����������
template <class T>
Vector<T>::Vector()
{
	len = 0;
}


//����������� � ����������
template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);//�������� � ���� ������� �
	}
	len = s.size();
}


//����������� �����������
template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;
	//�������� �������� ����� Vec.s � ������ v
	vector <T> v = copy_stack_to_vector(Vec.s);
	//�������� ������ v � ���� s
	s = copy_vector_to_stack(v);
}

//������ ������ 
template <class T>
void Vector<T>::Print()
{
	//�������� ���� � ������
	vector<T> v = copy_stack_to_vector(s);
	cout << endl; 
	while (!s.empty())//���� ���� �� ������
	{
		cout <<"("<< s.top() << ") ";//����� �������� � ������� �����
		s.pop();//������� ������� �� �������
	}
	//�������� ������ � ����
	s = copy_vector_to_stack(v);
}

//������� 3 
template <class T>
void Vector <T>::max() {
	vector<T> v = copy_stack_to_vector(s);
	T a = v[0];
	for (int x = 0; x < v.size(); x++) {//���������� ������������� �������� 
		if (a < v[x]) {
			a = v[x];
		}
	}
	v.push_back(a);
	s = copy_vector_to_stack(v);
}

//������� 4
template <class T>
void Vector <T>::del(const T& a1) {
	vector<T> v = copy_stack_to_vector(s);
	for (int i = 0; i < v.size(); i++) {//������� �������
		if (v[i] == a1) {
			v.erase(v.begin() + i);
		}
	}
	s = copy_vector_to_stack(v);
}

//������� 5
template <class T>
void Vector <T>::sredn() {
	vector<T> v = copy_stack_to_vector(s);
	T s1;
	//������� �������
	for (int i = 0; i < v.size(); i++)
		s1 = s1 + v[i];//����������� ���� ��������� ������� 
	int n = v.size();
	s1 = (s1 / n);//������� �������������� 
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + s1;
	s = copy_vector_to_stack(v);
}