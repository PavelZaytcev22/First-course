#pragma once
#include <iostream>
#include <string>
using namespace std;
class Sotrudnik
{
    //��������
    string name;
    string dolgn;
    int zp;
public:
    Sotrudnik();//����������� ��� ����������
    Sotrudnik(string, string, int);//����������� � �����������
    Sotrudnik(const Sotrudnik&);//����������� �����������
    ~Sotrudnik();//����������
    string get_name();//��������
    void set_name(string);//�����������
    string get_dolgn();//��������
    void set_dolgn(string); //�����������
    int get_zp();//��������
    void set_zp(int); //�����������
    void show();//�������� ���������
};