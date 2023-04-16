#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <windows.h>
using namespace std;
int kol = 0;

struct spisok{
	int key;
	spisok* point;
};

spisok* make_point(int n) {
	spisok* p, * l, * m;
	l = new (spisok);
	l->point = NULL;
	l->key = 0;
	m = l;
	if (n > 1) {
		for (int i = 1; i < n; i++) {
			p = new(spisok);
			l->point = p;
			p->point = NULL;
			p->key = 0;
			l = p;
		}
	}
	return m;
}

void cout_spisok(spisok* jj) {
	spisok* mm = jj;//������������� ��������� �� ������ ���� ������
	spisok* cc = jj;
	int i = 1;//������������� �������� ��� ������ ������ ���� ������ 
	bool flag = true;
	if (jj == NULL) {//����� �� �������, ���� ���������� ��������� ��� ������ 
		cout << "\n������ �� ����������!!!\n";
	}
	else {
		while ((mm->point) != NULL) {//�������� ������ �� ������������� 
			if ((mm->key) != 0)flag = false;
			mm = mm->point;
		}
		if ( ((mm->point) == NULL) && ((mm->key) != 0)) {//�������� ������ �� �������������, ���� ������ ������� �� 1 ���� 
			flag = false;
		}
		if (flag == false) {//����� ������ 
			cout << "\n��� ������: ";
			while ((cc->point) != NULL) {
				cout << "(" << i << ")" << cc->key << " -> ";
				cc = cc->point;
				i++;
			}
			cout << "(" << i << ")" << cc->key << " <-> NULL\n";
		}
		else {
			cout << "\n������ ����!!!\n";
		}

	}
}

void vvod_spisok(spisok* jj) {
	int i = 1;//������������� �������� ��� ������ ������ ���� ������ 
	spisok* hh = jj;//������������� ��������� �� ������ ���� ������
	if (hh != NULL) {
		if ((hh->point != NULL)) {
			while ((hh->point) != NULL) {
				cout << "������� " << i << "-�� ������� ������:";
				cin >> hh->key;//���� ����� ������ 
				cout << endl;
				i++;
				hh = hh->point;//������� �� ��������� ���� ������ 
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

spisok* udalit(spisok* jj) {
	int hh, nn;
	spisok* kk = jj;//������������� ��������� �� ������ ���� ������
	spisok* y = jj;
	spisok* f, * G,*D;//������������� ���������� ��� ���������� ��������
	if (kk == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return kk;
	}
	if (((kk->point) == NULL)) {//�������� ����������� ����� 
		cout << "\n�������� ����������!!!!\n";
		return kk;
	}
	cout << endl;
	cout << "������� � ���� �� �������� ������ ������� ����� ��� ������� ���� (�� 2-" << kol << "):";
	cin >> hh;
	cout << "������� ���������� ����� ������� ������ ������� (�� 1-" << hh - 1 << "):";
	cin >> nn;
	kol -= nn;
	int x = 0;
	if (nn == hh - 1) {
		for (int i = 1; i < hh; i++) {//������� ������ �� ������ ������� K
			y = y->point;
		}
		for (int j = 1; j <= nn; j++) { //�������� ����� ����� ��������� K
			G = kk;
				kk = kk->point;
				delete G;
		}
		return y;
	}
	else {
		f = kk;
		for (int i = 1; i < hh; i++) {//������� ������ �� ������ ������� K
			y = y->point;
		}
		for (x = 0; x < hh-2-nn; x++) {//������� c ������ �� ������ ������� �� �������� ����� �������
			kk = kk->point;
		}
		G = kk->point;
		kk->point = y;
		for (int i = 1; i <= nn; i++) {
			D = G;
			G = G->point;
			delete D; 
		}
		return f;
	}
}

void dobav_spisok(spisok* jj) {
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
	spisok* t;//������������� ��������� 
	t = make_point(vv);//�������� ������ ������
	vvod_spisok(t);//��������� ������ ������
	spisok* ff = jj;//������������� ��������� �� ������ ���� ������������ ������
	while (ff->point != NULL) {//������� � ����� ������������ ������
		ff = ff->point;
	}
	ff->point = t;//���������� ������������ ������ � �����
}

spisok* unich(spisok* jj) {
	spisok* kk = jj;//������������� ��������� �� ������ ���� ������
	spisok* mm;//������������� ���������
	if (kk == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return kk;
	}
	while (kk->point != NULL) {//�������� ����� ������ �� ������ 
		mm = kk->point;
		delete kk;
		kk = mm;
	}
	delete kk;//�������� ���������� ���� ������ �� ������ 
	return NULL;
}

void file1(spisok* jj) {
	spisok* t = jj;//������������� ��������� �� ������ ���� ������
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
	while (t->point != NULL) {//������ ����� ������ � ����
		f = t->key;
		fwrite(&f, sizeof(int), 1, kk);
		t = t->point;
	}
	f = t->key;//������ ����������� ���� ������ � ����
	fwrite(&f, sizeof(int), 1, kk);
	fclose(kk);
}

spisok* file2() {
	kol = 0;
	spisok* p, * gol, * m;
	int  g;
	FILE* G;
	if ((G = fopen("123.txt", "r")) == NULL) {
		cout << "��������� ������\n";
		exit(1);
	}
	fread(&g, sizeof(int), 1, G);
	p = new(spisok);
	p->point = NULL;
	p->key = g;
	gol = p;
	kol++;
	while (fread(&g, sizeof(int), 1, G)) {
		m = new(spisok);
		p->point = m;
		m->point= NULL;
		m->key = g;
		p = m;
		kol++;
	}
	cout << "\nE��� �� 8-�� ������� �� �������� � ������ �������, �� �� ����� ������.\n";
	return gol;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	spisok* j = NULL;
	int n = 0;
	int h;
	while (true) {
		cout << "\n������� ����� ��������.\n1)C������ ������\n2)��������� ������\n3)������� ���c��\n4)������� � ���������\n5)�������� � ���������\n6)������� ������\n7)��������� ���c�� � ����\n8)������� ������ �� �����\n9)������� ���������\n �=";
		cin >> n;
		switch (n) {
		case 1:cout << "������� ���������� ��������� � ������:"; cin >> h; kol = h; j = make_point(h); break;
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