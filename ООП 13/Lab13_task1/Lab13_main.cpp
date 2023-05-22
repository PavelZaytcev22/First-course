#include "C:\Users\������������\source\repos\Lab11_task2\Money.h"
#include "C:\Users\������������\source\repos\Lab11_task2\Money.cpp"
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

typedef deque < Money> Tdeq;
Money s;

//������������ �������
Tdeq make_deq(int n)
{
	Money a;
	Tdeq v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}


//������ �������
void print_deq(Tdeq v)
{
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " <- ";
}

struct Greater_s //������, ��� s
{
	bool operator()(Money t)
	{
		if (t > s) return true; else return false;
	}
};

Money srednee(Tdeq v)
{
	Money s = v[0];
	//������� �������
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();//���������� ��������� � �������
	return s / n;
}

struct Comp_less // ��� ���������� �� ��������

{
public:
	bool operator()(Money t1, Money t2)
	{
		if (t1 > t2)return true;
		else return false;
	}
};

struct Equal_s
{
	bool operator()(Money t)
	{
		return t == s;
	}
};

void del(Money& t)
{
	t = t / s;
}

void sredn(Money& t)
{
	t = t + s;
}

void main()
{
	setlocale(LC_ALL, "rus");
	int n;
	cout << "N?";
	cin >> n;
	Tdeq v;
	v = make_deq(n);
	print_deq(v);

	Tdeq::iterator i;
	//��������� �������� i �� ������������ �������
	i = max_element(v.begin(), v.end());
	cout << "\nmax=" << *(i) << endl;
	Money  m = *(i);
	s = *i;
	v.erase(i);
	v.push_back(m);
	cout << "\n���������� MAX � �����";
	print_deq(v);

	//�� ��������
	cout << "\nSortirovka po ubivaniu:" << endl;
	sort(v.begin(), v.end(), Comp_less());
	print_deq(v);
	//�� �����������
	cout << "\nSortirovka po vozrasaniu:" << endl;
	sort(v.begin(), v.end());
	print_deq(v);

	cout << "\nPOISK s udaleniem" << endl;
	cin >> s;
	//����� ���������, ��������������� ������� ���������
	i = find_if(v.begin(), v.end(), Equal_s());
	if (i != v.end())//���� ��� ����� �������
	{
		cout << "Deleted: " << *(i) << endl;
		v.erase(i);
	}
	else
		cout << "Not such element!" << endl;
	print_deq(v);

	cout << "\n||Plus sredn||" << endl;
	s = srednee(v);//����� ������� �������������� �������
	cout << "\nsred=" << s << endl;
	for_each(v.begin(), v.end(), sredn);
	print_deq(v);

	cout << "\nDELENIE" << endl;
	i = max_element(v.begin(), v.end());
	s = *i;
	//��� ������� �������� ������� ���������� ������� del
	for_each(v.begin(), v.end(), del);
	print_deq(v);
}