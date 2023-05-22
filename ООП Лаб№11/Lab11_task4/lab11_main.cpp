#include "C:\Users\������������\source\repos\Lab11_task2\Money.h"
#include "C:\Users\������������\source\repos\Lab11_task2\Money.cpp"
#include <iostream>
#include <deque>
#include < stack>
using namespace std;

typedef deque<Money> deq;//����
typedef stack <Money> stk;//������

//������� ������ ����� 
void print_stack(stk s ) {
	stk k = s;
	Money b;
	cout << endl;
	while (!k.empty()) {
		b = k.top();
		cout << b << " -> ";
		k.pop();
	}
	cout << ']';
}

//�������� ����� 
stk make_stack(int n)
{
	stk s;
	Money  t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//���� ����������
		s.push(t);//���������� �� � ����
	}
	return s;//������� ���� ��� ��������� �������
}

//�������� ���� � �������
deq copy_stack_to_deque(stk s)
{
	deq v;
	while (!s.empty())//���� ���� �� ������
	{
		//�������� � ������� ������� �� ������ �����
		v.push_back(s.top());
		s.pop();
	}
	return v; //������� ������ ��� ��������� �������
}

//�������� ������� � ����
stk copy_deque_to_stack(deq v)
{
	stk s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//�������� � ���� ������� �������
	}
	return s; //������� ���� ��� ��������� �������
}

//������� 3 
stk max(stk  s)
{
	deq v = copy_stack_to_deque(s);//�������� ���� � �������
	int n = 1;
	Money max1 = s.top();//��������� ����������� �����
	s.pop();//������� ������ ������� �� �������
	while (!s.empty())//���� ���� �� ������
	{
		if (max1 < s.top()) {
			max1 = s.top();
		}
		s.pop();//������� �������
		n++;
	}
	v.push_back(max1);
	s = copy_deque_to_stack(v);//����������� ������ � ����
	return s;//���������� ���� 
}

//������� 4 
stk del(stk vv, const Money cc) {
	stk buff1;//�������� ���� 
	Money s1;//�������� ��������� ������  
	bool flag = 0;
	while (!vv.empty())//���� ���� �� ������
	{
		s1 = vv.top();//���������� �������� 
		if (cc!=s1) {
			buff1.push(s1);
		}
		vv.pop();//������� �������
		
	}
	while (!buff1.empty())//���� ���� �� ������
	{
		s1 = buff1.top();
		vv.push(s1);
		buff1.pop();//������� �������
	}
	return vv;
}

//������� 5 
stk dobav(stk  nn) {
	Money s;
	deq v;
	v = copy_stack_to_deque(nn);
	//������� �������
	for (int i = 0; i < v.size(); i++) {
		s = s + v[i];//����������� ���� ��������� ������� 
		nn.pop();
	}
	int n = v.size();
	s = (s / n);//������� �������������� 
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + s;
	nn = copy_deque_to_stack(v);
	return nn;
}

int main() {
	setlocale(LC_ALL, "rus");
	stk m1; 
	m1 = make_stack(3);
	print_stack(m1);
	m1 = max(m1);
	print_stack(m1);
	m1 = del(m1, Money(11, 22));
	print_stack(m1);
	m1 = dobav(m1);
	print_stack(m1);
}