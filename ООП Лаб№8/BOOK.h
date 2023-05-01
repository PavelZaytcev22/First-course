#pragma once
#include <iostream>
#include <string>
#include "Event.h"
using namespace std;
#include "PRINT.h"

class BOOK :public PRINT 
{
protected:
	int pages;
	string publish;
public:
	BOOK();
	~BOOK();
	void Show();
	void Input();
	BOOK(string, string, int, string);
	BOOK(const BOOK&);
	int Get_pages() { return pages; }
	string  Get_publish() { return publish; }
	void Set_pages(int);
	void Set_publish(string);
	BOOK& operator=(const BOOK&);
};