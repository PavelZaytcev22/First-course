#pragma once
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Money
{
	long rub;
	int kop;
public:
	Money() { rub = 0; kop = 0; };
	Money(long c, int m) { rub = c; kop = m; }
	Money(const Money& t) { rub = t.rub; kop = t.kop; }
	~Money() {};
	int get_rub() { return rub; }
	int get_kop() { return kop; }
	void set_rub(long m) { rub = m; }
	void set_kop(int s) { kop = s; }

	//������������� ��������
	Money& operator=(const Money&);
	Money& operator++();
	Money operator+(const Money&);
	Money operator-(const Money&);
	Money& operator-(double);//����������� ��������

	friend bool operator== (const Money& , const Money& );
	friend bool operator!= (const Money&, const Money& );

	//���������� ������� �����-������
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);

	//������� ��� ������ � ���� 
	friend fstream& operator>>(fstream& fin, Money& p);
	friend fstream& operator <<(fstream& fout, const Money& p);
};