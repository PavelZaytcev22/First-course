#include <iostream>
#include <deque>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef deque<int> deq;//���������� ��� ��� ������ � ��������������� ��������

deq make_deq(int n) {
	deq vv;
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 100 - 50;
		vv.push_back(a);//��������� � � ����� ������� 
	}
	return vv;//���������� �������  ��� �������� ������ �������
}
//������� ��� ������ �������
void print_deq(deq v)
{
	for (int i = 0; i < v.size(); i++)
		cout <<'(' << v[i] << ") <- ";
	cout << endl;
}

//������� ���������� �� ������� 3  
deq max_begin(deq v) {
	int s = v[0];
	//������� �������
	for (int i = 0; i < v.size(); i++) {
		if (s < v[i]) {
			s = v[i];
		}
	}	
	v.push_back(s);
	return v;
}

//������� ������� n
deq del(deq v, int n)
{
	for (int i = 0; i < v.size(); i++) {//������� �������
		if (v[i] == n) {
			v.erase(v.begin() + i);
			return v;
		}
	}
	throw 1;//������ ���� n ��� � �������
}

deq sredn(deq v) {
	int s = 0;
	//������� �������
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();
	s = (s / n);
	for (int i = 0; i < v.size(); i++)
		v[i]=v[i]+s;
	return v;
}

//�������� �������
void main()
{
	srand(time(NULL));
	try
	{
		deque <int> v;//������
		deque<int>::iterator vi = v.begin();//��������
		int n=5;
		v = make_deq(n);//������������ ������� 
		print_deq(v);//������ �������
		v = max_begin(v);//���������� ���� �������� � ����� ������� 
		print_deq(v);//������ �������
		cout << "N?"; cin >> n;
		v = del(v, n);//�������� �������� � ��������� ������ 
		print_deq(v);//������ �������
		v = sredn(v);//����������� �������� �������� �� ���� ��������� 
		print_deq(v);//������ �������
	}
	catch (int)//���� ��������� ������
	{
		cout << "error!";
	}
}