#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.h"
#include "C:\Users\Пользователь\source\repos\Lab11_task2\Money.cpp"
#include <iostream>
#include <deque>
#include < stack>
using namespace std;

typedef deque<Money> deq;//стек
typedef stack <Money> stk;//вектор

//Функция вывода стека 
void print_stack(stk s ) {
	stk k = s;
	Money b;
	cout << endl;
	while (!k.empty()) {
		b = k.top();
		cout << b << " -> ";
		k.pop();
	}
	cout << ']';
}

//Создание стека 
stk make_stack(int n)
{
	stk s;
	Money  t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;//ввод переменной
		s.push(t);//добавление ее в стек
	}
	return s;//вернуть стек как результат функции
}

//копирует стек в очередь
deq copy_stack_to_deque(stk s)
{
	deq v;
	while (!s.empty())//пока стек не пустой
	{
		//добавить в очередь элемент из вершиы стека
		v.push_back(s.top());
		s.pop();
	}
	return v; //вернуть вектор как результат функции
}

//копирует очередь в стек
stk copy_deque_to_stack(deq v)
{
	stk s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);//добавить в стек элемент вектора
	}
	return s; //вернуть стек как результат функции
}

//Задание 3 
stk max(stk  s)
{
	deq v = copy_stack_to_deque(s);//копируем стек в очередь
	int n = 1;
	Money max1 = s.top();//начальное значениедля суммы
	s.pop();//удалить первый элемент из вектора
	while (!s.empty())//пока стек не пустой
	{
		if (max1 < s.top()) {
			max1 = s.top();
		}
		s.pop();//удалить элемент
		n++;
	}
	v.push_back(max1);
	s = copy_deque_to_stack(v);//скопировать вектор в стек
	return s;//Возвращаем стек 
}

//Задание 4 
stk del(stk vv, const Money cc) {
	stk buff1;//Буферный стек 
	Money s1;//Буферный экземпляр класса  
	bool flag = 0;
	while (!vv.empty())//пока стек не пустой
	{
		s1 = vv.top();//Считавание элемента 
		if (cc!=s1) {
			buff1.push(s1);
		}
		vv.pop();//удалить элемент
		
	}
	while (!buff1.empty())//пока стек не пустой
	{
		s1 = buff1.top();
		vv.push(s1);
		buff1.pop();//удалить элемент
	}
	return vv;
}

//Задание 5 
stk dobav(stk  nn) {
	Money s;
	deq v;
	v = copy_stack_to_deque(nn);
	//перебор вектора
	for (int i = 0; i < v.size(); i++) {
		s = s + v[i];//СУМИРОВАНИЕ ВСЕХ ЭЛЕМЕНТОВ ВЕКТОРА 
		nn.pop();
	}
	int n = v.size();
	s = (s / n);//Среднее арифметическое 
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] + s;
	nn = copy_deque_to_stack(v);
	return nn;
}

int main() {
	setlocale(LC_ALL, "rus");
	stk m1; 
	m1 = make_stack(3);
	print_stack(m1);
	m1 = max(m1);
	print_stack(m1);
	m1 = del(m1, Money(11, 22));
	print_stack(m1);
	m1 = dobav(m1);
	print_stack(m1);
}