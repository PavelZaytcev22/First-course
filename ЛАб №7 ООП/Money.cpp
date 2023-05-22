#include "Money.h"
#include <iostream>
using namespace std;

//���������� �������� ������������
Money& Money::operator=(const Money& t)
{
	//�������� �� ����������������
	if (&t == this) return *this;
	rub = t.rub;
	kop = t.kop;
	return *this;
}

//���������� ���������� �������-�������� �����
istream& operator>>(istream& in, Money& t)
{
	cout << "\n������?"; in >> t.rub;
	cout << "\n������?"; in >> t.kop;
	return in;
}

//���������� ���������� �������-�������� ������
ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.rub << "," << t.kop);
}

 bool operator > (const Money& c1, const Money& c2) {
	 if (c1.rub > c2.rub) {
		 return 1;
	 }
	 else {
		 if (c1.rub == c2.rub) {
			 if (c1.kop > c2.kop) {
				 return 1;
			 }
			 else {
				 return 0;
			 }
		 }
		 else {
			 return 0;
		 }
	 }
}

//���������� ��������� ����������� 
bool operator!= (const Money& c1, const Money& c2) {
	if (c1.rub != c2.rub || c1.kop != c2.kop) {
		return 1;
	}
	else return 0;
}

//���������� ��������� ��������� 
bool operator==(const Money& c1, const Money& c2) {
	if (c1.rub == c2.rub && c1.kop == c2.kop) {
		return 1;
	}
	else return 0;
}
