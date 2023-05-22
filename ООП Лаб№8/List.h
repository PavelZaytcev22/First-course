#pragma once
#include "Object.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

class List
{
public:
	List(int);//����������� � �����������
	List();
public:
	virtual void HandleEvent(const TEvent& e);
	~List(void);//����������
	void Add();//���������� �������� � ������
	void Del();
	void Show();
	int operator()();//������ �������
protected:
	Object** beg;//��������� �� ������ ������� �������
	int size;//������
	int cur;//������� �������
};

