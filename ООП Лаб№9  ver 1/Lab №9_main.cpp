#include "plenty.h"
#include<iostream>
#include <stdio.h>
#include <stdarg.h>
using namespace std;

int main() {

	//контролируемый блок
	try
	{
		plenty x(2,10);//вектор из двух элементов
		plenty y(15,10);//пустой вектор
		x[0] = 13;
		cout << y[-3];//Выход за границу множества 
		++x;
		++x;//Выход за границу множества 
		y + 20;//Выход за границу множества 
		x.showelem();
	}

	//обработчик исключения
	catch (int)
	{
		cout << "ERROR!!!" << endl;
	}//сообщение об ошибке
	return 0;
}
