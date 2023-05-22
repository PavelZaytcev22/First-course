#pragma once
#include <iostream>
using namespace std;
#include "List.h"
#include "Event.h"

class Dialog :
	public List
{
public:
	Dialog( );//����������
public:
	virtual ~Dialog(void);//����������
	virtual void GetEvent(TEvent & event);//�������� �������
	virtual int Execute();//������� ���� ��������� �������
	virtual void HandleEvent(TEvent& event); //����������
	virtual void ClearEvent(TEvent& event);//�������� �������
	int Valid();//�������� �������� EndState
	void EndExec();//��������� ������� ������ �������
protected:
	int EndState;
};