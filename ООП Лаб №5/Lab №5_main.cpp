#include "Object.h"
#include "Triad.h"
#include "TIME.h"
#include "Vector.h"
#include <iostream>

using namespace std;
void main()
{
	Triad a;
	cin >> a;
	cout << a << endl;//����� � ������� ������������� ��������
	Object * p = &a;
	p->Show();//����� � ������� ������ Show() � ���������
		Vector v(5);//������ �� 5 ���������
		Triad a;//������ ������ Car
		cin >> a;
		TIME b;// ������ ������ Lorry
		cin >> b;
		Object* p = &a;//������ ��������� �� ������ ������ Car
		v.Add(p);//��������� ������ � ������
		p = &b;//������ ��������� �� ������ ������ Lorry
		v.Add(p); //��������� ������ � ������
		cout << v;//����� �������
	
}