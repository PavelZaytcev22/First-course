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
//��� ������� 
int hash_function(string n, int x) {
	int y = 0;
	for (int i = 0; n[i] != '\0'; i++) y++;
	return (y % x);
}

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
void add_inhash(Human**  hash, int size, Human* ff) {
	int index1 = hash_function(ff->add, size);//���������� ������� �� ��� ������� 
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

//������� ������ ����
void show_hash(Human** hash, int size) {
	cout << "��� �������:\n";
	for (int i = 0; i < size; i++) {
		int x = 1;
		cout << "\n(" << i << ")";
		if (hash[i] == NULL) {
			cout << "����� �����";
		}
		else {
			Human* buff=hash[i];//�������� ��������� �� ������ ���� ������ 
			while (buff->right != NULL) {
				cout << endl << x << "-�� �������";
				cout << "\n���:" << buff->fullname;
				cout << "\n����� ��������:" << buff->phone_number;
				cout << "\n������:" << buff->add;
				x++;
				buff=buff->right;//������ �� ��������� ���� 
			}
			cout << endl << x << "-�� �������";
			cout << "\n���:" << buff->fullname;
			cout << "\n����� ��������:" << buff->phone_number;
			cout << "\n������:" << buff->add;
		}
	}
}

//������� ���������� ������� 
void mas_random(Human* mas, int size){
	if (size < 1) {//�������� ������ ������� ������� 
		cout << "\nERROR\n";
		return;
	}
	for (int i = 0; i < size; i++) {
		mas[i] = random_human();
	}
}

//������� ��� ������ ������� � �������
void show_mas(Human* mas, int size) {
	if (size < 1) {//�������� ������ ������� ������� 
		cout << "\nERROR\n";
		return;
	}
	for (int i = 0; i < size; i++) {
		cout << endl << "\n������� " << i + 1 << "-�� ";
		cout << "\n���:" << mas[i].fullname;
		cout << "\n����� ��������:" << mas[i].phone_number;
		cout << "\n�����:" << mas[i].add;
	}
}

//������� ���������� ������� ������� ���� �� ������ 
void find(Human** hash, int size) {
	if (size < 1) {//�������� ������ ��� ������� 
		cout << "\nERROR\n";
		return;
	}
	string buff1;
	bool flag = 0;//���� 
	cout << "\n������� ������ ��� ������:";
	cin.get();
	getline(cin, buff1);
	int index1 = hash_function(buff1, size);//���������� ������� �� ��� ������� 
	Human* buff2 = hash[index1];
	if (buff2 == NULL) {//�������� ��������� �� ������� ��������� �� ���� ������ 
		cout << "\n������ �� ����������\n";
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
		cout << "\n�������� � ����� ������� ��� � ����";
	}
	else {
		cout << "\n�������� � ������� ������� ���������� � ������ �� �������:" << index1 << endl;
	}

}

//������� �������� ������ �������� �� ���� �� ������ 
Human* udalit1(Human ** hash, int size) {
	if (size < 1) {//�������� ������ ��� ������� 
		cout << "\nERROR\n";
		return NULL;
	}
	string buff1;
	bool flag = 0;
	cout << "\n������� ������ ��� ��������:";
	cin.get();
	getline(cin, buff1);
	int index1 = hash_function(buff1, size);//���������� ������� �� ��� ������� 
	Human* buff2 = hash[index1];
	if (buff2 == NULL) {//�������� ��������� �� ������� ������ �� ���� ������ 
		cout << "\n��� �������� � ����� �������\n";
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
				cout << "\n�������� � ������� ������� ���������� � ��� ������ � ������ �� �������:" << index1 << endl;
				return buff2;
			}
			if (buff2->left == NULL && buff2->right != NULL) {
				cc1 = buff2->right;
				cc1->left = NULL;
				hash[index1] = cc1;
				buff2->right = NULL;
				cout << "\n�������� � ������� ������� ���������� � ��� ������ � ������ �� �������:" << index1 << endl;
				return buff2;
			}
			if (buff2->right == NULL && buff2->left == NULL) {
				hash[index1] = NULL;
				cout << "\n�������� � ������� ������� ���������� � ��� ������ � ������ �� �������:" << index1 << endl;
				return buff2;
			}
			if (buff2->right != NULL && buff2->left != NULL) {
				cc1 = buff2->left;
				Human* cc2= buff2->right;
				cc1->right = cc2;
				cc2->left = cc1;
				buff2->left = NULL;
			    buff2->right = NULL;
				cout << "\n�������� � ������� ������� ���������� � ��� ������ � ������ �� �������:" << index1 << endl;
				return buff2;
			}
		}
		else {
			cout << "\n� ������ ��� �������� � ����� �������";
		}
	}
	
		
}

//������� ������ ��������� �������� ��������
void del_return(Human** hash, int size, Human* del) {
	if (size < 1) {//�������� ������ ��� ������� 
		cout << "\nERROR\n";
		return;
	}
	if (del==NULL ) {//�������� ������ ��� ������� 
		cout << "\n��� ������� � ��������� �������� ��������\n";
		return;
	}
	add_inhash(hash, size, del);
	del = NULL;
}

//������� ��� ������ ������� � ���� 
void file1(Human* mas, int size) {
	if (size < 1) {
		cout << "\nERROR\n";
		return;
	}
	ofstream file("123.txt");
	Human buff;//�������� ��������� ���������
	if (!file) {//�������� ������� �����
		cout << "��������� ������\n";
		exit(1);
	}
	for (int j = 0; j < size; j++) {
		buff = mas[j];//��������� ���������� ������� � �������� ���������� 
		file << buff.fullname << " " << buff.phone_number << ' ' << buff.add << " ";
		}
	file << " !";//������ ����� ����� 
	file.close();
}

//������� ��� ���������� ������� � ����� 
void file2(Human * mas , int size ) {
	if (size < 1) {//�������� ������ ��� ������� 
		cout << "\nERROR\n";
		exit(1);
	}
	ifstream file("123.txt");
	if (!file) {//�������� ������� �����
		cout << "��������� ������\n";
		exit(1);
	}
	string temp = "";
	Human buff;//�������� ��������� ���������
	int i = 0;
	while ((file >> temp) && (i< size) ) {
		if (temp == "!") break;//����� ������ ���� ��������� ����� ����� 
		buff.fullname = temp;
		file >> temp;
		buff.phone_number = temp;
		file >> temp;
		buff.add = temp;
		mas[i] = buff;
		i++;
	}
	file.close();//�������� ����� 
	return;
}

//������� �������� �������
void unich_mas(Human* mas, int  ss) {
	for (int i = 0; i < ss; i++) {
		mas[i].fullname = "NULL";
		mas[i].phone_number = "NULL";
		mas[i].add = "NULL";
	}
}

//������� �������� ��� ������� 
void make_hash(Human** hash, int ss,int mm, Human *mas) {
	if (ss < 1) {
		cout << "\nERROR\n";
		return;
	}
	for (int i = 0; i < ss; i++) {
		Human* point = &mas[i];//�������� ��������� �� ���� �������
		add_inhash(hash, mm , point);
	}
	cout << "\n��������� �������:(" << collusions << ") �� ������ �������:" << ss<<endl;
	collusions = 0;
}

int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int ss =100;//����������� ���������� �� ������ �������
	int mm=40;//����������� ���������� �� ������ ����
	Human* mas=new Human[ss];//������ �������� Human
	Human* del;//�������� ��������� �� ��������� ����
	del = NULL;
	Human* bb = NULL;//��������� �� ����������� ������� 
	Human** hash=new Human*[mm];//��� ������� 
	Human cc;
	for (int y = 0; y < mm; y++) {
		hash[y] = NULL; 
	}
	int x;
	while (true) {
		cout << endl << "\n������� � �������";
		cout << endl << "1)��������� ������ ���������� ������";
		cout << endl << "2)������� � ������� ���c�� ��������";
		cout << endl << "3)�������� ������";
		cout << endl << "4)��������� ������ � ����";
		cout << endl << "5)������� ������ � �����";
		cout << endl << "6)������� ��� �������";
		cout << endl << "7)������� � ������� ��� �������";
		cout << endl << "8)������� �� ������";
		cout << endl << "9)������ ��������� �������� �������� �� ������";
		cout << endl << "10)����� � ��� �������";
		cout << endl << "11)�������� ��������� ������� � ��� �������";
		cout << endl << "12)����� �� ���������";
		cout << endl << "�="; cin >> x;
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
			cc =  random_human();//������������� ��������� �� ��������� ��������� ���������
			bb = &cc;
			cout << endl <<"����� �������";
			cout << "\n���:" << bb->fullname;
			cout << "\n����� ��������:" << bb->phone_number;
			cout << "\n������:" << bb->add;
			add_inhash(hash, mm, bb);
			break;
		case 12: return 0;
		default: cout << endl << "������������ ����";
		}
	}
	return 0;
}