#pragma once
#include <cmath>
#include <iostream>
using namespace std; 

class fraction
{
public:
	double first;
	double second;
	void Init(double, double);//метод для инициализации полей
	void Read();//метод для чтения значений полей
	void Show();//метод для вывода значений полей
	double Power();//вычисление степени
	void distance();//Вычисление расстояния до точки 
};
