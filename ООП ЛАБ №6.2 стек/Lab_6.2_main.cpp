#include<iostream>
#include "plenty.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	int mas[5] = { 3,10,-5,6,44 };
	int bb[2] = { 3,5};
	plenty cc(5, mas);//Инициализация стека 
	cout << cc[0];//Доступ по индексу 
	plenty v(2, bb);//Инициализация стека 
	cout << "\n!!" <<(cc != v);//вызов оператора неравества  
	cout << "\n??" << (cc < 40);//вызов принадлежности константы стеку 
	Object* nn = cc + 2;//Перонос указателя на 2 элемента в право от начала стека 
	return 0;
}