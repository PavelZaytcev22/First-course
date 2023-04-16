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

struct Human {
	Human() {
		fullname = "NULL";
		phone_number = "NULL";
		add = "NULL";
		left = NULL;
		right = NULL;
	}
	Human* left;
	Human* right;
	string fullname;
	string phone_number;
	string add;
};
//Хэш функция 
int hash_function(string n, int x) {
	int y = 0;
	for (int i = 0; n[i] != '\0'; i++) y++;
	return (y % x);
}

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
void add_inhash(Human**  hash, int size, Human* ff) {
	int index1 = hash_function(ff->add, size);//Нахождение индекса по хэш функции 
	Human* point=ff;
			if (hash[index1] == NULL) {
				hash[index1]=ff;
			}
			else {
				hash[index1]->left = ff;
				ff->right = hash[index1];
				hash[index1] = ff;
				collusions++;
			}	
}

//Функция вывода хэша
void show_hash(Human** hash, int size) {
	cout << "ХЭШ Таблица:\n";
	for (int i = 0; i < size; i++) {
		int x = 1;
		cout << "\n(" << i << ")";
		if (hash[i] == NULL) {
			cout << "Ячека пуста";
		}
		else {
			Human* buff=hash[i];//Буферный указатель на первый узел списка 
			while (buff->right != NULL) {
				cout << endl << x << "-ый элемент";
				cout << "\nИмя:" << buff->fullname;
				cout << "\nНомер телефона:" << buff->phone_number;
				cout << "\nАдресс:" << buff->add;
				x++;
				buff=buff->right;//Преход на следубщий узел 
			}
			cout << endl << x << "-ый элемент";
			cout << "\nИмя:" << buff->fullname;
			cout << "\nНомер телефона:" << buff->phone_number;
			cout << "\nАдресс:" << buff->add;
		}
	}
}

//Функция заполнения массива 
void mas_random(Human* mas, int size){
	if (size < 1) {//Проверка длинны массива таблицы 
		cout << "\nERROR\n";
		return;
	}
	for (int i = 0; i < size; i++) {
		mas[i] = random_human();
	}
}

//Функция для вывода массива в консоль
void show_mas(Human* mas, int size) {
	if (size < 1) {//Проверка длинны массива таблицы 
		cout << "\nERROR\n";
		return;
	}
	for (int i = 0; i < size; i++) {
		cout << endl << "\nЭлемент " << i + 1 << "-ый ";
		cout << "\nФИО:" << mas[i].fullname;
		cout << "\nНомер телефона:" << mas[i].phone_number;
		cout << "\nАдрес:" << mas[i].add;
	}
}

//Функция нахождения индекса элемена хэша по адресу 
void find(Human** hash, int size) {
	if (size < 1) {//Проверка длинны хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	string buff1;
	bool flag = 0;//Флаг 
	cout << "\nВведите адресс для поиска:";
	cin.get();
	getline(cin, buff1);
	int index1 = hash_function(buff1, size);//Нахождение индекса по хэш функции 
	Human* buff2 = hash[index1];
	if (buff2 == NULL) {//Проверка указателя на наличие указателя на узел списка 
		cout << "\nСписка не существует\n";
		return;
	}
	else {
		while (buff2->add != buff1 && buff2->right != NULL) {
			buff2=buff2->right;
		}
		if (buff2->add == buff1) { 
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "\nЧеловека с таким адресом нет в хэше";
	}
	else {
		cout << "\nЧеловека с похожим адресом встретился в списке по индексу:" << index1 << endl;
	}

}

//Функция удаления одного элемента из хэша по адресу 
Human* udalit1(Human ** hash, int size) {
	if (size < 1) {//Проверка длинны хэш таблицы 
		cout << "\nERROR\n";
		return NULL;
	}
	string buff1;
	bool flag = 0;
	cout << "\nВведите адресс для удаления:";
	cin.get();
	getline(cin, buff1);
	int index1 = hash_function(buff1, size);//Нахождение индекса по хэш функции 
	Human* buff2 = hash[index1];
	if (buff2 == NULL) {//Проверка указателя на наличие ссылки на узел списка 
		cout << "\nНет человека с таким адресом\n";
		return NULL;
	}
	else {
		while (buff2->add != buff1 && buff2->right != NULL) {
			buff2 = buff2->right;
		}
		if (buff2->add == buff1) {
			Human* cc1;
			flag = 1;
			if (buff2->right == NULL && buff2->left != NULL){
				cc1 = buff2->left;
				cc1->right = NULL;
				buff2->left = NULL;
				cout << "\nЧеловека с похожим адресом встретился и был удален в списке по индексу:" << index1 << endl;
				return buff2;
			}
			if (buff2->left == NULL && buff2->right != NULL) {
				cc1 = buff2->right;
				cc1->left = NULL;
				hash[index1] = cc1;
				buff2->right = NULL;
				cout << "\nЧеловека с похожим адресом встретился и был удален в списке по индексу:" << index1 << endl;
				return buff2;
			}
			if (buff2->right == NULL && buff2->left == NULL) {
				hash[index1] = NULL;
				cout << "\nЧеловека с похожим адресом встретился и был удален в списке по индексу:" << index1 << endl;
				return buff2;
			}
			if (buff2->right != NULL && buff2->left != NULL) {
				cc1 = buff2->left;
				Human* cc2= buff2->right;
				cc1->right = cc2;
				cc2->left = cc1;
				buff2->left = NULL;
			    buff2->right = NULL;
				cout << "\nЧеловека с похожим адресом встретился и был удален в списке по индексу:" << index1 << endl;
				return buff2;
			}
		}
		else {
			cout << "\nВ списке нет человека с таким адресом";
		}
	}
	
		
}

//Функция отмкны последней операции удаления
void del_return(Human** hash, int size, Human* del) {
	if (size < 1) {//Проверка длинны хэш таблицы 
		cout << "\nERROR\n";
		return;
	}
	if (del==NULL ) {//Проверка длинны хэш таблицы 
		cout << "\nНет доступа к последней операции удаления\n";
		return;
	}
	add_inhash(hash, size, del);
	del = NULL;
}

//Функция для записи массива в файл 
void file1(Human* mas, int size) {
	if (size < 1) {
		cout << "\nERROR\n";
		return;
	}
	ofstream file("123.txt");
	Human buff;//Буферный экземпляр структуры
	if (!file) {//Проверка наличия файла
		cout << "Произошла ошибка\n";
		exit(1);
	}
	for (int j = 0; j < size; j++) {
		buff = mas[j];//Занесение экземпляра массива в буферную переменную 
		file << buff.fullname << " " << buff.phone_number << ' ' << buff.add << " ";
		}
	file << " !";//Маячок конца файла 
	file.close();
}

//Функция для считывания масиива с файла 
void file2(Human * mas , int size ) {
	if (size < 1) {//Проверка длинны хэш таблицы 
		cout << "\nERROR\n";
		exit(1);
	}
	ifstream file("123.txt");
	if (!file) {//Проверка наличия файла
		cout << "Произошла ошибка\n";
		exit(1);
	}
	string temp = "";
	Human buff;//Буферный экземпляр структуры
	int i = 0;
	while ((file >> temp) && (i< size) ) {
		if (temp == "!") break;//Конец чтения если достигнут конец файла 
		buff.fullname = temp;
		file >> temp;
		buff.phone_number = temp;
		file >> temp;
		buff.add = temp;
		mas[i] = buff;
		i++;
	}
	file.close();//Закрытие файла 
	return;
}

//Функция очищения массива
void unich_mas(Human* mas, int  ss) {
	for (int i = 0; i < ss; i++) {
		mas[i].fullname = "NULL";
		mas[i].phone_number = "NULL";
		mas[i].add = "NULL";
	}
}

//Функция создания хэш таблицы 
void make_hash(Human** hash, int ss,int mm, Human *mas) {
	if (ss < 1) {
		cout << "\nERROR\n";
		return;
	}
	for (int i = 0; i < ss; i++) {
		Human* point = &mas[i];//Буферный указатель на узел массива
		add_inhash(hash, mm , point);
	}
	cout << "\nКоличесво колизий:(" << collusions << ") на длинну массива:" << ss<<endl;
	collusions = 0;
}

int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int ss =100;//Переменнная отвечающая за длинну массива
	int mm=40;//Переменнная отвечающая за длинну хэша
	Human* mas=new Human[ss];//Массив структур Human
	Human* del;//Буферный указатель на удаляемый узел
	del = NULL;
	Human* bb = NULL;//Указатель на добавляемый элемент 
	Human** hash=new Human*[mm];//Хэш таблица 
	Human cc;
	for (int y = 0; y < mm; y++) {
		hash[y] = NULL; 
	}
	int x;
	while (true) {
		cout << endl << "\nВВедите № команды";
		cout << endl << "1)Заполнить массив случайными узлами";
		cout << endl << "2)Вывести в консоль масcив структур";
		cout << endl << "3)Очистить массив";
		cout << endl << "4)Сохранить массив в файл";
		cout << endl << "5)Считать массив с файла";
		cout << endl << "6)Создать хэш таблицу";
		cout << endl << "7)Вывести в консоль хэш таблицу";
		cout << endl << "8)Удалить по адресу";
		cout << endl << "9)Отмена последней операции удаления по адресу";
		cout << endl << "10)Поиск в хэш таблице";
		cout << endl << "11)Добавить случайный элемент в хэш таблицу";
		cout << endl << "12)Выход из программы";
		cout << endl << "№="; cin >> x;
		switch (x) {
		case 1:mas_random(mas, ss); break;
		case 2:show_mas(mas,ss); break;
		case 3:unich_mas(mas, ss); break;
		case 4:file1(mas, ss); break;
		case 5:file2(mas, ss); break;
		case 6:make_hash(hash, ss, mm,mas);  break;
		case 7:show_hash(hash,ss); break;
		case 8: del = NULL; del = udalit1(hash, mm); break;
		case 9:del_return(hash, mm, del); del = NULL; break;
		case 10: find(hash, mm); break;
		case 11: 
			cc =  random_human();//Инициализация указателя на случайный экземпляр структуры
			bb = &cc;
			cout << endl <<"Новый элемент";
			cout << "\nИмя:" << bb->fullname;
			cout << "\nНомер телефона:" << bb->phone_number;
			cout << "\nАдресс:" << bb->add;
			add_inhash(hash, mm, bb);
			break;
		case 12: return 0;
		default: cout << endl << "Неправильный ввод";
		}
	}
	return 0;
}