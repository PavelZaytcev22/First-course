#include "Money.h"
#include "file_work.h"
#include <math.h>
#include <stdio.h>
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL,"rus");
	Money p, buff;
	int k, c,x;
	char file_name[30];
	do
	{
		//����
		cout << "\n1. ������� ���� ";
		cout << "\n2. ������� ����";
		cout << "\n3. ������� �������� � ����� ";
		cout << "\n4. �������� � ���������";
		cout << "\n5. ������� 1,50 ��� �� �������� ��������� �����";
		cout << "\n0. ����� �� ���������\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "��� �����?"; 
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "������";
			break;
		case 2: cout << "��� �����?"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "���� ����\n";
			if (k < 0)cout << "����� �� ����������\n";

			break;

		case 3: cout << "��� �����?"; cin >> file_name;
			cout << "������� ����� ����� ? "; 
			cin >> buff;
			k = del_fromfile(file_name, buff);
			if (k < 0)cout << "����� �� ����������";
			break;
		case 4: cout << "��� �����?";
			cin >> file_name;
			do {
				cout << "������� ����� ��������, ����� �������� ������ ��������?";
				cin >> k;
			} while (k<=0);
			k = dobav(file_name, k);
			if (k < 0) { cout << "����� �� ����������"; break; };
			if (k == 0) { cout << "Can't read file"; break; };
			break;
		case 5: cout << "��� �����?";
			cin >> file_name;
			cout << "������� ����� �����?"; 
			cin >> buff;
			k = minus_150(file_name, buff);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		}
	} while (c != 0);
}