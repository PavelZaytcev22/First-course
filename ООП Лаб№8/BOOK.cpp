#include <iostream>
#include <string>
using namespace std;
#include "BOOK.h"

//����������� ��� ���������� 
BOOK::BOOK():PRINT() {
	pages = 0;
	publish = "";
}
//����������� � ����������� 
BOOK::BOOK(string s1, string s2, int x, string s3) :PRINT(s1, s2) {
	pages = x;
	publish = s3;
}
//����������� ����������� 
BOOK::BOOK(const BOOK& c) {
	autor = c.autor;
	name = c.name;
	pages = c.pages;
	publish = c.publish;

}

//���������� 
BOOK::~BOOK(){
}

//����� ��� ��������� ���������
void BOOK::Show() {
	cout << "\nAutor: " << autor;
	cout << "\nName: " << name;
	cout << "\nPages: " << pages;
	cout << "\nPublish: " << publish;
	cout << "\n";
}

//����� ��� ����� ��������� ������ 
void BOOK::Input() {
	cout << "\nAutor? "; cin >> autor;
	cout << "\nName? "; cin >> name;
	cout << "\nPages? "; cin>> pages;
	cout << "\nPublish? "; cin >> publish;
	cout << "\n";
}
//������������ 
void BOOK::Set_pages(int s2) {
	pages = s2;
}
void BOOK::Set_publish(string s1) {
	publish = s1;
}
//������������� �������� ������������ 
BOOK& BOOK::operator=(const BOOK& c)
{
	if (&c == this)return *this;
	autor = c.autor;
	name = c.name;
	pages = c.pages;
	publish = c.publish;
	return *this;
}