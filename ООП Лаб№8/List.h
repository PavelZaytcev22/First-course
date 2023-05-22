#pragma once
#include "Object.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

class List
{
public:
	List(int);//конструктор с параметрами
	List();
public:
	virtual void HandleEvent(const TEvent& e);
	~List(void);//деструктор
	void Add();//добавление элемента в вектор
	void Del();
	void Show();
	int operator()();//размер вектора
protected:
	Object** beg;//указатель на первый элемент вектора
	int size;//размер
	int cur;//текущая позиция
};

