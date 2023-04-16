#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string> 
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include <fstream>
using namespace std;

string name[10] = { "Владимир","Александр","Михал","Павел","Алексей","Тихон","Денис","Мирослав","Вячеслав","Богдан" };
string secname[10] = { "Дмитриевич", "Алексеевич","Олегович","Алесандрович","Купидонович","Игоревич","Валерьевич","Максимович","Богданович","Михайлович" };
string surname[10] = { "Зайцев","Коуров","Иванов","Смирнов","Сидоров","Макаров","Фокин","Голубочкин","Ципленков","Яблочков" };
string number[10] = { "88005353535","86532896565","87563569569","88954562596","87891592591","81233319663","83579512565","81533512552","87596845654","87293811937" };
string adres[10] = { "ул.Пушкина","ул.Деветаева","ул.Заречная","ул.ВасилияТатищева","ул.Ленина","ул.Поздеева","ул.Пенкина","ул.Яшина","ул.Кречкина","ул.Сталина" };

int collusions = 0;//Счетчик колизий 

int hash_function(string n, int x) {
	int y = 0;
	for (int i = 0; n[i] != '\0'; i++) y++;
	return (y % x);
}
//Стуктура объекта

struct Human {
	Human() {
		fullname = "NULL";
		phone_number = "NULL";
		add = "NULL";
	}
	string fullname;
	string phone_number;
	string add;
};
/*
struct hash_table {
	Human* table;
	hash_table(int size) {
		table = new Human[size];
	}
	~hash_table() {
		delete[] table;
	}
	void add(Human temp, int size);
	void find(string temp, int size);
	void pop(Human temp, int size);
};

void hash_table::find(string temp, int size) {
	int index1 = hash_function(temp, size);
	int index2 = index1;
	while (table[index2].add != temp && index2 < size) {
		index2++;
	}
	if (index2 >= size) {
		index2 = 0;
		while (table[index2].add != temp && index2 < index1) {
			index2++;
		}
	}
	if (index2 > index1) {
		cout << "\nЧеловека с таким адресом нет";
	}
	else {
		cout << "\nЧеловека с  адресом " << temp << " свстретился по индексу";
	}
}

void hash_table::add(Human temp, int size) {
	int index1 = hash_function(temp.add, size);
	int index2 = index1;
	int collusions = 0;
	if (table[index2].fullname == "NULL") {
		table[index2] = temp;
	}
	else {
		while (index2 < size) {
			if (table[index2].fullname == "NULL") {
				table[index2] = temp;
			}
			collusions++;
			index1++;
		}
		if (index2 >= size) {
			index2 = 0;
			while (table[index2].fullname != "NULL" && index2 < index1) {
				if (table[index2].fullname == "NULL") {
					table[index2] = temp;
				}
				collusions++;
				index1++;
			}
		}
	}
}
*/

//Функция генерации случайного числа
int rand_numb() {
	return rand() % 10;;
}

//Получение заполненного экзэмпляра структуры Human
Human random_human() {
	Human buff;
	buff.fullname = surname[rand_numb()] + name[rand_numb()] + secname[rand_numb()];
	buff.phone_number = number[rand_numb()];
	buff.add = adres[rand_numb()];
	return buff;
}

//Функция добавления элемента в хэш
void add_inhash(Human  hash[], int size, Human ff) {
	int index1 = hash_function(ff.add, size);//Нахождение индекса по хэш функции 
	int index2 = index1;
	if (hash[index2].add == "NULL") {//Проверка на заполненность узла хэш таблицы 
		hash[index2] = ff;//Занесение элемента в хэш таблицу 
	}
	else {
		while (index2 < size) {//Движение до конца таблицы 
			if (hash[index2].add == "NULL") {//Проверка на заполненность узла хэш таблицы 
				hash[index2] = ff;//Занесение элемента в хэш таблицу 
				return;
			}
			collusions++;//Счетсик колизий 
			index2++;//Переход на следующий индекс 
		}
		if (index2 >= size) {
			index2 = 0;//Переход в начало хэш таблицы 
			while (index2 < index1) {
				if (hash[index2].add == "NULL") {//Проверка на заполненность узла хэш таблицы 
					hash[index2] = ff;//Занесение элемента в хэш таблицу 
					return;
				}
				collusions++;//Счетсик колизий 
				index2++;//Переход на следующий индекс
			}
		}
		cout << "В таблице нет места";
	}
}

//Функция вывода хэша в консоль
void show_hash(Human  m[], int n) {
	for (int i = 0; i < n; i++) {
		cout << endl << "\nЭлемент " << i + 1 << "-ый ";
		cout << "\nФИО:" << m[i].fullname;
		cout << "\nНомер телефона:" << m[i].phone_number;
		cout << "\nАдрес:" << m[i].add;
	}
}

//Функция для записи массива в файл 
void file1(Human* m, int n) {
	if (n < 1) {
		cout << "\nERROR\n";
		return;
	}
	ofstream file("123.txt");
	Human buff;//Буферный экземпляр структуры
	if (!file) {//Проверка наличия файла
		cout << "Произошла ошибка\n";
		exit(1);
	}
	for (int j = 0; j < n; j++) {
		buff = m[j];//Занесение экземпляра структуры в буферную переменную 
		file << buff.fullname << ' ' << buff.phone_number << ' ' << buff.add << ' ';
	}
	file << " !";//Маячок конца файла 
	file.close();
}

//Функция cчитывание массива с файла
Human* file2(int n) {
	if (n < 1) {//Проверка длинны хэш таблицы 
		cout << "\nERROR\n";
		exit(1);
	}
	ifstream file("123.txt");
	if (!file) {//Проверка наличия файла
		cout << "Произошла ошибка\n";
		exit(1);
	}
	string temp="";
	Human buff;//Буферный экземпляр структуры
	int j = 0;
	Human* mas = new Human[n];//Создание новой хэш таблицы 
	while (file>>temp) {
		if (temp == "!") break;//Конец чтения если достигнут конец файла 
		buff.fullname = temp;
		file >> temp;
		buff.phone_number = temp;
		file >> temp;
		buff.add = temp;
		j++;
		add_inhash(mas, n, buff);//Занесение элемента в хэш
	}
	file.close();//Закрытие файла 
	return mas;
}

//Функция заполнения хэша случайными элементами 
void fillall_hash(Human* m, int n) {
	if (m==NULL) {
		cout << "\nERROR\n";
		return;
	}
	if (n < 1) {
		cout << "\nERROR\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		Human buff = random_human();//Создание случайного заполненного узла хэш таблицы 
		add_inhash(m, n, buff);//Занесение элемента в хэш
	}
	cout << "\nКоличеств колизий=" << collusions << endl;
	collusions = 0;
}

//Функция добавления одного элемента в хэш
void filloneelement_hash(Human* m, int n) {
	Human buff;
	if (m == NULL) {//Проверка инициализации хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	if (n < 1) {//Проверка длинны хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	cout << "\nФИО:"; cin.get(); getline(cin, buff.fullname);
	cout << "№ТЕЛЕФОНА:"; getline(cin, buff.phone_number);
	cout << "АДРЕС:"; getline(cin, buff.add);
	add_inhash(m, n, buff);//Занесение элемента в хэш
	cout << "\nКоличеств колизий=" << collusions << endl;
	collusions = 0;
}

//Функция нахождения индекса элемена хэша по адресу 
void find(Human  m[], int size) {
	if (m == NULL) {//Проверка инициализации хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	if (size < 1) {//Проверка длинны хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	string buff;
	bool flag = 0;//Флаг 
	cout << "\nВведите адресс для поиска:";
	cin.get();
	getline(cin, buff);
	int index1 = hash_function(buff, size);//Нахождение индекса по хэш функции 
	int index2 = index1;
	if (m[index2].add == buff) {//Проверка на совпадение полей 
		flag = 1;
	}
	while (flag == 0 && index2 < size) {
		index2++;//Переход на следующий узел хэш таблицы 
		if (m[index2].add == buff) {//Проверка на совпадение полей 
			flag = 1;
		}
	}
	if (index2 >= size) {
		index2 = 0;//Перевод в начало хэш таблицы 
		if (m[index2].add == buff) {//Проверка на совпадение полей 
			flag = 1;
		}
		while (flag == 0 && index2 < index1) {
			index2++;
			if (m[index2].add == buff) {//Проверка на совпадение полей 
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		cout << "\nЧеловека с таким адресом нет";
	}
	else {
		cout << "\nЧеловека с похожим адресом встретился по индексу:" << index2 << endl;
	}

}

//Функция удаления элемена хэша по адресу 
void udalit1(Human  m[], int size) {
	string buff;
	bool flag = 0;
	if (m == NULL) {//Проверка инициализации хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	if (size < 1) {//Проверка длинны хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	cout << "\nВведите адресс для удаления:";
	cin.get();
	getline(cin, buff);
	int index1 = hash_function(buff, size);//Нахождение индекса по хэш функции 
	int index2 = index1;
	if (m[index2].add == buff) {//Проверка на совпадение полей 
		flag = 1;
	}
	while (flag == 0 && index2 < size) {
		index2++;//Переход на следующий узел хэш таблицы 
		if (m[index2].add == buff) {//Проверка на совпадение полей 
			flag = 1;
		}
	}
	if (index2 >= size) {
		index2 = 0;//Перевод в начало хэш таблицы 
		if (m[index2].add == buff) {//Проверка на совпадение полей 
			flag = 1;
		}
		while (flag == 0 && index2 < index1) {
			index2++;//Переход на следующий узел хэш таблицы 
			if (m[index2].add == buff) {//Проверка на совпадение полей 
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		cout << "\nЧеловека с таким адресом нет";
	}
	else {
		cout << "\nЧеловек с похожим адресом встретился ибыл удален по индексу:" << index2 << endl;
		string temp="";
		m[index2].fullname = "NULL";
		m[index2].phone_number = "NULL";
		m[index2].add = "NULL";
	}

}

//Функция удаления всех элементов хэша по адресу 
void unich(Human  m[], int size) {
	if (m == NULL) {//Проверка инициализации хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	if (size < 1) {//Проверка длинны хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	for (int i = 0; i < size; i++) {
		m[i].fullname = "NULL";
		m[i].phone_number = "NULL";
		m[i].add = "NULL";
	}
}

int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Human* hash= NULL;//Хэш таблица
	int c=0;//Переменная для работы программы 
	int x=0;//Переменная для работы программы 
	while (true) {
		cout << endl << "\nВВедите № команды";
		cout << endl << "1)Создать хэш таблицу";
		cout << endl << "2)Вывести хэш в консоль";
		cout << endl << "3)Заполнить хэш таблицу случайными узлами";
		cout << endl << "4)Вставить 1 элемент в хэш таблицу";
		cout << endl << "5)Найти индекс элемента по адресу";
		cout << endl << "6)Удалить 1 узел по адресу";
		cout << endl << "7)Очистьть хэш таблицу";
		cout << endl << "8)Сохранить хэш таблицу в файл";
		cout << endl << "9)Достать хэш таблицу из файла";
		cout << endl << "10)Закрыть программу";
		cout <<endl<< "№="; cin >> x;
		switch (x) {
		case 1: 
			cout << "\nВведите длинну хэш таблицы:";
			cin >> c;
			if (c < 1) {
				cout << "\nНеправильный ввод";
				break;
			}
			hash = new Human[c];
			break;
		case 2:show_hash(hash, c); break;
		case 3:fillall_hash(hash, c); break;
		case 4:filloneelement_hash(hash, c); break;
		case 5:find(hash, c); break;
		case 6:udalit1(hash, c); break;
		case 7:unich(hash, c); break;
		case 8:file1(hash, c); break;
		case 9:
			cout << "\nВведите длинну новой хэш таблицы:";
			cin >> c;
			if (c < 1) {
				cout << "\nНеправильный ввод";
				break;
			}
			hash = file2(c);
			break;
		case 10: return 0;
		default:cout << endl << "Неправильный ввод";
		}
	}
	return 0;
}