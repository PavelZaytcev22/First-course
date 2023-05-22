#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.h"
#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.cpp"
#include "Vector.h"
#include <vector>
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "RUS");
	Vector <Money> vec(3);//создать вектор из 5 элементов
	vec.Print();
	vec.dobav();
	vec.Print();
	Money bb(11, 22);
	vec.del(bb);
	vec.Print();
	vec.sredn();
	vec.Print();
	return ;
}