#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <windows.h>
using namespace std;
int kol = 0;//������� ���������� �����
/*
struct spisok {
	int key;
	spisok* point;
};
spisok* make_point(int n) {
	spisok* first, * p;
	first = NULL;
	for (int i = n; i >0; i--) {
		p = new(spisok);
		p->key = 0;
		p->point = first;
		first = p;
	}
	return first;
}
void cout_point(spisok*ll) {
	spisok* y = ll;
	while (y != NULL) {
		cout << y->key << " ";
		y = y->point;
	}
}

*/

//
struct spisok2 {
	int key;
	spisok2* left;
	spisok2* right;
};
spisok2* make_spisok(int n) {//������� �������� ������ 
	spisok2* p, * l, * m;
	l = new(spisok2);//���������� � ���������� ������� ���� 
	l->left = NULL;
	l->right = NULL;
	l->key = 0;
	m = l;//�������� ������� ��������
	if (n > 1) {//���������� ����������� �����
		for (int i = 1; i < n; i++) {
			p = new(spisok2);
			l->right = p;
			p->left = l;
			p->right = NULL;
			p->key = 0;
			l = p;
		}
	}
	return m;//������� ���������� ��������� �� ������ ����
}
void cout_spisok(spisok2* jj) {
	spisok2* mm = jj;//������������� ��������� �� ������ ���� ������
	spisok2* vv = jj;//������������� ��������� �� ������ ���� ������
	int i = 1;//������������� �������� ��� ������ ������ ���� ������ 
	bool flag = true;
	if (jj == NULL) {//����� �� �������, ���� ���������� ��������� ��� ������ 
		cout << "\n������ �� ����������!!!\n";
	}
	else {
		while ((vv->right) != NULL) {//�������� ������ �� ������������� 
			if ((vv->key) != 0)flag = false;
			vv = vv->right;
		}
		if (((vv->left) == NULL) && ((vv->right) == NULL) && ((vv->key) != 0)) {//�������� ������ �� �������������, ���� ������ ������� �� 1 ���� 
			flag = false;
		}
		if (flag == false) {//����� ������ 
			cout << "\n��� ������: NULL<-> ";
			while ((mm->right) != NULL) {
				cout << "(" << i << ")" << mm->key << " <-> ";
				mm = mm->right;
				i++;
			}
			cout << "(" << i << ")" << mm->key << " <-> NULL\n";
		}
		else {
			cout << "\n������ ����!!!\n";
		}

	}
}
void vvod_spisok(spisok2* jj) {
	int i = 1;//������������� �������� ��� ������ ������ ���� ������ 
	spisok2* hh = jj;//������������� ��������� �� ������ ���� ������
	if (hh != NULL) {
		if ((hh->right != NULL)) {
			while ((hh->right) != NULL) {
				cout << "������� " << i << "-�� ������� ������:";
				cin >> hh->key;//���� ����� ������ 
				cout << endl;
				i++;
				hh = hh->right;//������� �� ��������� ���� ������ 
			}
			cout << "������� " << i << "-�� ������� ������:";
			cin >> hh->key;//���� ����� ���������� ���� ������ 
		}
		else {//���� ����� ������������� ���� ������ 
			cout << "������� ���� ����:";
			cin >> hh->key;
			cout << "\n";
		}
	}
	else cout << "������ ������������\n";
}
spisok2* udalit(spisok2* jj) {
	int hh, nn;
	spisok2* k = jj;//������������� ��������� �� ������ ���� ������
	spisok2* y, * f, * G;//������������� ���������� ��� ���������� ��������

	if (k == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return k;
	}
	if (((k->left) == NULL) && ((k->right) == NULL)) {//�������� ����������� ����� 
		cout << "\n�������� ����������!!!!\n";
		return k;
	}
	cout << endl;
	cout << "������� � ���� �� �������� ������ ������� ����� ��� ������� ���� (�� 2-" << kol << "):";
	cin >> hh;
	cout << "������� ���������� ����� ������� ������ ������� (�� 1-" << hh - 1 << "):";
	cin >> nn;
	kol -= nn;

	for (int i = 1; i < hh; i++) {//������� ������ �� ������ ������� K
		k = k->right;
	}

	y = k->left;
	f = k;
	for (int r = 0; r < nn + 1; r++) {// C������� ������ 
		f = f->left;
	}
	k->left = f;
	if (nn < hh - 1) {
		f->right = k;
		while (k->left != NULL) { //������� ������ � ������ ������ 	
			k = k->left;
		}
	}

	for (int j = 1; j <= nn; j++) { //�������� ����� ����� ��������� K
		G = y;
		for (int k = 0; k < nn - j; k++) {
			G = G->left;
		}
		delete G;
	}
	return k;
}
void dobav_spisok(spisok2* jj) {
	if (jj == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	cout << "\n������� ���������� �����,������� �� ������ �������� � ����� ������:";
	int vv;
	int d = 1;
	cin >> vv;
	if (vv < 1) {
		cout << "������������ ����. ����� ��������� ��������\n";
		dobav_spisok(jj);//����������� ����� ������� ��� ������������ �����
	}
	kol += vv;
	spisok2* t;//������������� ��������� 
	t = make_spisok(vv);//�������� ������ ������
	vvod_spisok(t);//��������� ������ ������
	spisok2* ff = jj;//������������� ��������� �� ������ ���� ������������ ������
	while (ff->right != NULL) {//������� � ����� ������������ ������
		ff = ff->right;
	}
	ff->right = t;//���������� ������������ ������ � �����
	t->left = ff;//���������� ������ ������ � �����������
}
spisok2* unich(spisok2* jj) {
	spisok2* kk = jj;//������������� ��������� �� ������ ���� ������
	spisok2* mm;//������������� ���������
	if (kk == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return kk;
	}
	while (kk->right != NULL) {//�������� ����� ������ �� ������ 
		mm = kk->right;
		delete kk;
		kk = mm;
	}
	delete kk;//�������� ���������� ���� ������ �� ������ 
	return NULL;
}
void file1(spisok2* jj) {
	spisok2* t = jj;//������������� ��������� �� ������ ���� ������
	int f = 0;//�������� ���������� 
	FILE* kk;//������ �� ����
	if (jj == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	if ((kk = fopen("123.txt", "w")) == NULL) {//�������� ������� �����
		cout << "��������� ������\n";
		exit(1);
	}
	while (t->right != NULL) {//������ ����� ������ � ����
		f = t->key;
		fwrite(&f, sizeof(int), 1, kk);
		t = t->right;
	}
	f = t->key;//������ ����������� ���� ������ � ����
	fwrite(&f, sizeof(int), 1, kk);
	fclose(kk);
}
spisok2* file2() {
	kol = 0;
	spisok2* p, * gol, * m;
	int  g;
	FILE* G;
	if ((G = fopen("123.txt", "r")) == NULL) {
		cout << "��������� ������\n";
		exit(1);
	}
	fread(&g, sizeof(int), 1, G);
	p = new(spisok2);
	p->left = NULL;
	p->right = NULL;
	p->key = g;
	gol = p;
	kol++;
	while (fread(&g, sizeof(int), 1, G)) {
		m = new(spisok2);
		p->right = m;
		m->left = p;
		m->right = NULL;
		m->key = g;
		p = m;
		kol++;
	}
	cout << "\nE��� �� 8-�� ������� �� �������� � ������ �������, �� �� ����� ������.\n";
	return gol;
}
//
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	int h;
	spisok2* j = NULL;
	while (true) {
		cout << "\n������� ����� ��������.\n1)C������ ������\n2)��������� ������\n3)������� ���c��\n4)������� � ���������\n5)�������� � ���������\n6)������� ������\n7)��������� ���c�� � ����\n8)������� ������ �� �����\n9)������� ���������\n �=";
		cin >> n;
		switch (n) {
		case 1:cout << "������� ���������� ��������� � ������:"; cin >> h; kol = h; j = make_spisok(h); break;
		case 2: vvod_spisok(j);  break;
		case 3: cout_spisok(j);  break;
		case 4: j = udalit(j); ; break;
		case 5: dobav_spisok(j); break;
		case 6: j = unich(j); break;
		case 7: file1(j); cout << "7+\n"; break;
		case 8: j = file2(); break;
		case 9: return 0;
		default: cout << "\n!!������������ ����!!\n";
		}
	}
	return 0;
}