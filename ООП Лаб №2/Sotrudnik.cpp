#include "Sotrudnik.h"
#include <iostream>
#include <string>
using namespace std;
//���������� ��� ���������� 
Sotrudnik::Sotrudnik()
{
    name= "";
    dolgn = "";
    zp = 0;
    cout << "\nConstructor bez parametrov dlia objecta" << this << endl;
}
//���������� � �����������
Sotrudnik::Sotrudnik(string N, string K, int S) {
    name = N;
    dolgn = K;
    zp = S;
}
//���������� ����������� 
Sotrudnik::Sotrudnik(const Sotrudnik& t)
{
    name = t.name;
    dolgn = t.dolgn;
    zp = t.zp;
}
//����������
Sotrudnik::~Sotrudnik()
{
    cout << "Destructor dlia objecta" << this << endl;
}
//������������
string Sotrudnik::get_name() {
    return name;
}
//�����������
void Sotrudnik::set_name(string f) {
   name=f;
}
//������������
string Sotrudnik::get_dolgn() {
    return dolgn;
}
//�����������
void Sotrudnik::set_dolgn(string f) {
    dolgn= f;
}
//������������
int Sotrudnik::get_zp() {
    return zp;
}
//�����������
void Sotrudnik::set_zp(int f) {
    zp = f;
}

//����� ��� ��������� ���������
void Sotrudnik::show()
{

    cout << "name :" << name << endl;
    cout << "dolgnost :" << dolgn << endl;
    cout << "zp :" << zp << endl;
}