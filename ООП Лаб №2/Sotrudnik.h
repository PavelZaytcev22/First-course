#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sotrudnik
{
    //атрибуты
    string name;
    string dolgn;
    int zp;
public:
    Sotrudnik();//конструктор без параметров
    Sotrudnik(string, string, int);//конструктор с параметрами
    Sotrudnik(const Sotrudnik&);//конструктор копирования
    ~Sotrudnik();//деструктор
    string get_name();//селектор
    void set_name(string);//модификатор
    string get_dolgn();//селектор
    void set_dolgn(string); //модификатор
    int get_zp();//селектор
    void set_zp(int); //модификатор
    void show();//просмотр атрибутов
};