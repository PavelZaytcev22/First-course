#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc); //открыть дл€ записи
	if (!stream)return -1;//ошибка открыти€ файла
	int n;
	Money p;
	cout << "N?"; 
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;//ввод атрибутов объекта из стандартного потока
		stream << p << "\n";//запись объекта в файловый поток
	}
	stream.close();//закрыть поток
	return n;//вернуть количество записанных объектов
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);//открыть дл€ чтени€
	if (!stream)return -1;//ошибка открыти€ файла
	Money p; int i = 0;
	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_fromfile(const char* f_name, Money number)
{
	fstream temp("temp", ios::out);//открыть дл€ записи
	fstream stream(f_name, ios::in);//открыть дл€ чтени€
	if (!stream)return -1;//ошибка открыти€ файла
	int i = 0; 
	Money p;
	while (stream >> p)//пока нет конца файла выполн€ем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
		if (stream.eof())break;
		i++;
		//если объект number не равен k, то записываем его во вспомогательый файл
		if (p != number) { 
			temp << p; 
		}
		else {
			i--;
		}
	}
	//закрыть файлы
	stream.close();
	temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}

int minus_150(const char* f_name, Money number)
{
	fstream temp("temp", ios::out);//открыть дл€ записи
	fstream stream(f_name, ios::in);//открыть дл€ чтени€
	if (!stream)return -1;//ошибка открыти€ файла
	int i = 0;
	Money p;
	while (stream >> p)//пока нет конца файла выполн€ем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
		if (stream.eof())break;
		i++;
		//если объект number равен p, то отнимаем от него 1ю50 руб и записываем его во вспомогательый файл
		if (p == number)
		{
			p - 1.50;
			temp << p;
		}
		else {
			temp << p;
		}
	}
	//закрыть файлы
	stream.close();
	temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}

int dobav(const char* f_name, int k)
{
	fstream temp("temp", ios::out);//открыть дл€ записи
	fstream stream(f_name, ios::in);//открыть дл€ чтени€
	if (!stream)return -1;//ошибка открыти€ файла
	int i = 0;
	Money p;//Ѕуферный экземпл€р класса дл€ считывани€ в него данных с файла  
	Money x;//Ѕуферный экземпл€р класса дл€ записи новых элементов 
	int n=0;
	do {
		cout << "\n¬ведите колличество экземпл€ров которое вы хотите вставить:";
		cin >> n;
	} while (n <= 0);
	while (stream >> p)//пока нет конца файла выполн€ем чтение объекта
	{
		//если прочитан признак конца файла,то выход из цикла
		if (stream.eof())break;
		i++;
		//если объект number не равен k, то записываем его во вспомогательый файл
		if (i == k) {
			temp << p;
			for (int c = 0; c < n; c++){
				cout << endl<< c+1 << "-ый экземпл€р";
				cin >> x;//»нициализаци€ нового экземпл€ра класса 
				temp << x;//«апись в файл нового экземпл€ра класса 
				i++;
			}
		}
		else {
			temp << p;
		}
	}

	//закрыть файлы
	stream.close();
	temp.close();
	remove(f_name);//удалить старый файл
	rename("temp", f_name);// переименовать temp
	return i;//количество прочитанных
}