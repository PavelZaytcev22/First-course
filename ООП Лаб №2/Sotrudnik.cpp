#include "Sotrudnik.h"
#include <iostream>
#include <string>
using namespace std;
//Коструктор без параметров 
Sotrudnik::Sotrudnik()
{
    name= "";
    dolgn = "";
    zp = 0;
    cout << "\nConstructor bez parametrov dlia objecta" << this << endl;
}
//Коструктор с параметрами
Sotrudnik::Sotrudnik(string N, string K, int S) {
    name = N;
    dolgn = K;
    zp = S;
}
//Коструктор копирования 
Sotrudnik::Sotrudnik(const Sotrudnik& t)
{
    name = t.name;
    dolgn = t.dolgn;
    zp = t.zp;
}
//Деструктор
Sotrudnik::~Sotrudnik()
{
    cout << "Destructor dlia objecta" << this << endl;
}
//Спецификатор
string Sotrudnik::get_name() {
    return name;
}
//модификатор
void Sotrudnik::set_name(string f) {
   name=f;
}
//Спецификатор
string Sotrudnik::get_dolgn() {
    return dolgn;
}
//модификатор
void Sotrudnik::set_dolgn(string f) {
    dolgn= f;
}
//Спецификатор
int Sotrudnik::get_zp() {
    return zp;
}
//модификатор
void Sotrudnik::set_zp(int f) {
    zp = f;
}

//метод для просмотра атрибутов
void Sotrudnik::show()
{

    cout << "name :" << name << endl;
    cout << "dolgnost :" << dolgn << endl;
    cout << "zp :" << zp << endl;
}