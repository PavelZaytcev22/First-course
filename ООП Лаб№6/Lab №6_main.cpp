#include "plenty.h"
#include<iostream>
using namespace std;

int main() {
	plenty v1(5, 10,20,11,-5,6);
	v1[2] = 15;//������ �� �������� 
	cout << v1;
	plenty v2(2, 19,1);
	cout << "! =" << (v1 !=v2);//�������� �� �����������
	cout << "!? =" << (v1 <40);//�������� �� ������� �������� ��������� � ����������
	Iterator v3 = v1.first();
	v1[1] = 14;
	v3 + 2;//������ ��������� �� 5 �������� ������ 
	cout << *v3;
	return 0;
}