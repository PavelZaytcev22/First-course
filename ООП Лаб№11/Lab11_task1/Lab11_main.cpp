#include <iostream>
#include <deque>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef deque<int> deq;//определяем тип для работы с двунаправленной очередью

deq make_deq(int n) {
	deq vv;
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 100 - 50;
		vv.push_back(a);//добавляем а в конец очереди 
	}
	return vv;//возвращаем очередь  как результа работы функции
}
//функция для печати вектора
void print_deq(deq v)
{
	for (int i = 0; i < v.size(); i++)
		cout <<'(' << v[i] << ") <- ";
	cout << endl;
}

//Функция добавления по заданию 3  
deq max_begin(deq v) {
	int s = v[0];
	//перебор вектора
	for (int i = 0; i < v.size(); i++) {
		if (s < v[i]) {
			s = v[i];
		}
	}	
	v.push_back(s);
	return v;
}

//удалить элемент n
deq del(deq v, int n)
{
	for (int i = 0; i < v.size(); i++) {//перебор вектора
		if (v[i] == n) {
			v.erase(v.begin() + i);
			return v;
		}
	}
	throw 1;//Ошибка если n нет в очереди
}

deq sredn(deq v) {
	int s = 0;
	//перебор вектора
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();
	s = (s / n);
	for (int i = 0; i < v.size(); i++)
		v[i]=v[i]+s;
	return v;
}

//основная функция
void main()
{
	srand(time(NULL));
	try
	{
		deque <int> v;//вектор
		deque<int>::iterator vi = v.begin();//итератор
		int n=5;
		v = make_deq(n);//формирование очереди 
		print_deq(v);//печать очереди
		v = max_begin(v);//добавление макс элемента в конец очереди 
		print_deq(v);//печать очереди
		cout << "N?"; cin >> n;
		v = del(v, n);//Удаление элемента с введенным ключем 
		print_deq(v);//печать очереди
		v = sredn(v);//Прибавление среднего значения ко всем элементам 
		print_deq(v);//печать очереди
	}
	catch (int)//блок обработки ошибок
	{
		cout << "error!";
	}
}