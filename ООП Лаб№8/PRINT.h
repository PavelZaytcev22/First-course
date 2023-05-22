#pragma once
#include <iostream>
#include <string>
#include "Event.h"
#include "Object.h"
using namespace std;

class PRINT :public Object 
{
	protected:
		string autor;
		string name;
    public:
	void HandleEvent(const TEvent& e);//Чисто виртуальная функция 
	PRINT();//конструктор без параметров
	virtual ~PRINT();//деструктор
	void Show();//функция для просмотра атрибутов класса с помощью указателя
	void Input();//функция для ввода значений атрибутов
	PRINT(string, string);//конструктор с параметрами
	PRINT(const PRINT&);//конструктор копирования
	//селекторы
	string Get_autor() { return autor; }
	string Get_name() { return name; }
	//модификаторы
	void Set_autor(string);
	void Set_name(string);
	PRINT& operator=(const PRINT&);//перегрузка операции присваивания
};

