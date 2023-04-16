#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string> 
#include <windows.h>
#include <ctime>
#include <stdlib.h>
#include <fstream>
using namespace std;

string name[10] = { "��������","���������","�����","�����","�������","�����","�����","��������","��������","������" };
string secname[10] = { "����������", "����������","��������","������������","�����������","��������","����������","����������","����������","����������" };
string surname[10] = { "������","������","������","�������","�������","�������","�����","����������","���������","��������" };
string number[10] = { "88005353535","86532896565","87563569569","88954562596","87891592591","81233319663","83579512565","81533512552","87596845654","87293811937" };
string adres[10] = { "��.�������","��.���������","��.��������","��.���������������","��.������","��.��������","��.�������","��.�����","��.��������","��.�������" };

int collusions = 0;//������� ������� 

int hash_function(string n, int x) {
	int y = 0;
	for (int i = 0; n[i] != '\0'; i++) y++;
	return (y % x);
}
//�������� �������

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
		cout << "\n�������� � ����� ������� ���";
	}
	else {
		cout << "\n�������� �  ������� " << temp << " ����������� �� �������";
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

//������� ��������� ���������� �����
int rand_numb() {
	return rand() % 10;;
}

//��������� ������������ ���������� ��������� Human
Human random_human() {
	Human buff;
	buff.fullname = surname[rand_numb()] + name[rand_numb()] + secname[rand_numb()];
	buff.phone_number = number[rand_numb()];
	buff.add = adres[rand_numb()];
	return buff;
}

//������� ���������� �������� � ���
void add_inhash(Human  hash[], int size, Human ff) {
	int index1 = hash_function(ff.add, size);//���������� ������� �� ��� ������� 
	int index2 = index1;
	if (hash[index2].add == "NULL") {//�������� �� ������������� ���� ��� ������� 
		hash[index2] = ff;//��������� �������� � ��� ������� 
	}
	else {
		while (index2 < size) {//�������� �� ����� ������� 
			if (hash[index2].add == "NULL") {//�������� �� ������������� ���� ��� ������� 
				hash[index2] = ff;//��������� �������� � ��� ������� 
				return;
			}
			collusions++;//������� ������� 
			index2++;//������� �� ��������� ������ 
		}
		if (index2 >= size) {
			index2 = 0;//������� � ������ ��� ������� 
			while (index2 < index1) {
				if (hash[index2].add == "NULL") {//�������� �� ������������� ���� ��� ������� 
					hash[index2] = ff;//��������� �������� � ��� ������� 
					return;
				}
				collusions++;//������� ������� 
				index2++;//������� �� ��������� ������
			}
		}
		cout << "� ������� ��� �����";
	}
}

//������� ������ ���� � �������
void show_hash(Human  m[], int n) {
	for (int i = 0; i < n; i++) {
		cout << endl << "\n������� " << i + 1 << "-�� ";
		cout << "\n���:" << m[i].fullname;
		cout << "\n����� ��������:" << m[i].phone_number;
		cout << "\n�����:" << m[i].add;
	}
}

//������� ��� ������ ������� � ���� 
void file1(Human* m, int n) {
	if (n < 1) {
		cout << "\nERROR\n";
		return;
	}
	ofstream file("123.txt");
	Human buff;//�������� ��������� ���������
	if (!file) {//�������� ������� �����
		cout << "��������� ������\n";
		exit(1);
	}
	for (int j = 0; j < n; j++) {
		buff = m[j];//��������� ���������� ��������� � �������� ���������� 
		file << buff.fullname << ' ' << buff.phone_number << ' ' << buff.add << ' ';
	}
	file << " !";//������ ����� ����� 
	file.close();
}

//������� c��������� ������� � �����
Human* file2(int n) {
	if (n < 1) {//�������� ������ ��� ������� 
		cout << "\nERROR\n";
		exit(1);
	}
	ifstream file("123.txt");
	if (!file) {//�������� ������� �����
		cout << "��������� ������\n";
		exit(1);
	}
	string temp="";
	Human buff;//�������� ��������� ���������
	int j = 0;
	Human* mas = new Human[n];//�������� ����� ��� ������� 
	while (file>>temp) {
		if (temp == "!") break;//����� ������ ���� ��������� ����� ����� 
		buff.fullname = temp;
		file >> temp;
		buff.phone_number = temp;
		file >> temp;
		buff.add = temp;
		j++;
		add_inhash(mas, n, buff);//��������� �������� � ���
	}
	file.close();//�������� ����� 
	return mas;
}

//������� ���������� ���� ���������� ���������� 
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
		Human buff = random_human();//�������� ���������� ������������ ���� ��� ������� 
		add_inhash(m, n, buff);//��������� �������� � ���
	}
	cout << "\n��������� �������=" << collusions << endl;
	collusions = 0;
}

//������� ���������� ������ �������� � ���
void filloneelement_hash(Human* m, int n) {
	Human buff;
	if (m == NULL) {//�������� ������������� ��� ������� 
		cout << "\nERROR\n";
		return;
	}
	if (n < 1) {//�������� ������ ��� ������� 
		cout << "\nERROR\n";
		return;
	}
	cout << "\n���:"; cin.get(); getline(cin, buff.fullname);
	cout << "���������:"; getline(cin, buff.phone_number);
	cout << "�����:"; getline(cin, buff.add);
	add_inhash(m, n, buff);//��������� �������� � ���
	cout << "\n��������� �������=" << collusions << endl;
	collusions = 0;
}

//������� ���������� ������� ������� ���� �� ������ 
void find(Human  m[], int size) {
	if (m == NULL) {//�������� ������������� ��� ������� 
		cout << "\nERROR\n";
		return;
	}
	if (size < 1) {//�������� ������ ��� ������� 
		cout << "\nERROR\n";
		return;
	}
	string buff;
	bool flag = 0;//���� 
	cout << "\n������� ������ ��� ������:";
	cin.get();
	getline(cin, buff);
	int index1 = hash_function(buff, size);//���������� ������� �� ��� ������� 
	int index2 = index1;
	if (m[index2].add == buff) {//�������� �� ���������� ����� 
		flag = 1;
	}
	while (flag == 0 && index2 < size) {
		index2++;//������� �� ��������� ���� ��� ������� 
		if (m[index2].add == buff) {//�������� �� ���������� ����� 
			flag = 1;
		}
	}
	if (index2 >= size) {
		index2 = 0;//������� � ������ ��� ������� 
		if (m[index2].add == buff) {//�������� �� ���������� ����� 
			flag = 1;
		}
		while (flag == 0 && index2 < index1) {
			index2++;
			if (m[index2].add == buff) {//�������� �� ���������� ����� 
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		cout << "\n�������� � ����� ������� ���";
	}
	else {
		cout << "\n�������� � ������� ������� ���������� �� �������:" << index2 << endl;
	}

}

//������� �������� ������� ���� �� ������ 
void udalit1(Human  m[], int size) {
	string buff;
	bool flag = 0;
	if (m == NULL) {//�������� ������������� ��� ������� 
		cout << "\nERROR\n";
		return;
	}
	if (size < 1) {//�������� ������ ��� ������� 
		cout << "\nERROR\n";
		return;
	}
	cout << "\n������� ������ ��� ��������:";
	cin.get();
	getline(cin, buff);
	int index1 = hash_function(buff, size);//���������� ������� �� ��� ������� 
	int index2 = index1;
	if (m[index2].add == buff) {//�������� �� ���������� ����� 
		flag = 1;
	}
	while (flag == 0 && index2 < size) {
		index2++;//������� �� ��������� ���� ��� ������� 
		if (m[index2].add == buff) {//�������� �� ���������� ����� 
			flag = 1;
		}
	}
	if (index2 >= size) {
		index2 = 0;//������� � ������ ��� ������� 
		if (m[index2].add == buff) {//�������� �� ���������� ����� 
			flag = 1;
		}
		while (flag == 0 && index2 < index1) {
			index2++;//������� �� ��������� ���� ��� ������� 
			if (m[index2].add == buff) {//�������� �� ���������� ����� 
				flag = 1;
			}
		}
	}
	if (flag == 0) {
		cout << "\n�������� � ����� ������� ���";
	}
	else {
		cout << "\n������� � ������� ������� ���������� ���� ������ �� �������:" << index2 << endl;
		string temp="";
		m[index2].fullname = "NULL";
		m[index2].phone_number = "NULL";
		m[index2].add = "NULL";
	}

}

//������� �������� ���� ��������� ���� �� ������ 
void unich(Human  m[], int size) {
	if (m == NULL) {//�������� ������������� ��� ������� 
		cout << "\nERROR\n";
		return;
	}
	if (size < 1) {//�������� ������ ��� ������� 
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
	Human* hash= NULL;//��� �������
	int c=0;//���������� ��� ������ ��������� 
	int x=0;//���������� ��� ������ ��������� 
	while (true) {
		cout << endl << "\n������� � �������";
		cout << endl << "1)������� ��� �������";
		cout << endl << "2)������� ��� � �������";
		cout << endl << "3)��������� ��� ������� ���������� ������";
		cout << endl << "4)�������� 1 ������� � ��� �������";
		cout << endl << "5)����� ������ �������� �� ������";
		cout << endl << "6)������� 1 ���� �� ������";
		cout << endl << "7)�������� ��� �������";
		cout << endl << "8)��������� ��� ������� � ����";
		cout << endl << "9)������� ��� ������� �� �����";
		cout << endl << "10)������� ���������";
		cout <<endl<< "�="; cin >> x;
		switch (x) {
		case 1: 
			cout << "\n������� ������ ��� �������:";
			cin >> c;
			if (c < 1) {
				cout << "\n������������ ����";
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
			cout << "\n������� ������ ����� ��� �������:";
			cin >> c;
			if (c < 1) {
				cout << "\n������������ ����";
				break;
			}
			hash = file2(c);
			break;
		case 10: return 0;
		default:cout << endl << "������������ ����";
		}
	}
	return 0;
}