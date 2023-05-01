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
	void HandleEvent(const TEvent& e);//����� ����������� ������� 
	PRINT();//����������� ��� ����������
	virtual ~PRINT();//����������
	void Show();//������� ��� ��������� ��������� ������ � ������� ���������
	void Input();//������� ��� ����� �������� ���������
	PRINT(string, string);//����������� � �����������
	PRINT(const PRINT&);//����������� �����������
	//���������
	string Get_autor() { return autor; }
	string Get_name() { return name; }
	//������������
	void Set_autor(string);
	void Set_name(string);
	PRINT& operator=(const PRINT&);//���������� �������� ������������
};

