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
		//Меню
		cout << "\n1. Создать файл ";
		cout << "\n2. Вывести файл";
		cout << "\n3. Удалить элементы с файла ";
		cout << "\n4. добавить К элементов";
		cout << "\n5. Вычесть 1,50 руб из заданных элементов файла";
		cout << "\n0. Выйти из программы\n";
		cin >> c;
		switch (c)
		{
		case 1: cout << "Имя файла?"; 
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0)cout << "Ошибка";
			break;
		case 2: cout << "Имя файла?"; cin >> file_name;
			k = print_file(file_name);
			if (k == 0)cout << "Файл пуст\n";
			if (k < 0)cout << "Файла не существует\n";

			break;

		case 3: cout << "Имя файла?"; cin >> file_name;
			cout << "ВВЕДИТЕ ЧИСЛО денег ? "; 
			cin >> buff;
			k = del_fromfile(file_name, buff);
			if (k < 0)cout << "Файла не существует";
			break;
		case 4: cout << "Имя файла?";
			cin >> file_name;
			do {
				cout << "ВВЕДИТЕ номер элемента, после которого хотите добавить?";
				cin >> k;
			} while (k<=0);
			k = dobav(file_name, k);
			if (k < 0) { cout << "Файла не существует"; break; };
			if (k == 0) { cout << "Can't read file"; break; };
			break;
		case 5: cout << "Имя файла?";
			cin >> file_name;
			cout << "ВВЕДИТЕ ЧИСЛО денег?"; 
			cin >> buff;
			k = minus_150(file_name, buff);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		}
	} while (c != 0);
}