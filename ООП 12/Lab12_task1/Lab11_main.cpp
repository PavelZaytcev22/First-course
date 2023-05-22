#include <iostream>
#include <set>
using namespace std;

typedef set<int, less<int> > Tset;//определяем тип для работы со множеством
typedef Tset::iterator it;//итератор

//Функция для создания множества 
Tset make_set(int n)
{
	Tset m;//пустое множнство 
	int a;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
		cin >> a;
		//создаем пару и добавляем ее в множество
		m.insert(a);
	}
	return m;//возвращаем словарь как результат работы функции
}

//функция для печати множество 
void print_set(Tset m)
{
	cout << endl;
	for (int n : m)
		cout << " (" << n << ") ";
}

//Задание 4
Tset del(Tset c1) {
	int b;
	cout << "\nУдалить элемент:";
		cin >> b;
		c1.erase(b);
		return c1;
}
//Задание 5
Tset sredn(Tset c1) {
	int* mas=new int [c1.size()];
	int x = 0;
	int i = c1.size();
	int i1 = 0;
	for (int b : c1) {
		mas[i1] = b;
		x += b;
		i1++;
	}
	x = (x / c1.size());//СРЕДНЕЕ ЗНАЧЕНИЕ ЭЛЕМЕНТОВ МНОЖЕСТВА 
	for (int m = 0; m < i; m++) {//Удаление всех элементов из множества 
		c1.erase(mas[m]);
	}
	for (int m = 0; m <i; m++) {
		c1.insert(mas[m] + x);
	}
	return c1;
}


int main() {
	setlocale(LC_ALL, "rus");
	Tset ss;
	ss = make_set(4);
	print_set(ss);
	ss = del(ss);
	print_set(ss);
	ss = sredn(ss);
	print_set(ss);
	return 0;
}