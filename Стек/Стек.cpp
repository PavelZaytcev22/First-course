#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <windows.h>
using namespace std;
int kol = 0;//������� ���������� �����

struct stek {
	int key;
	stek* left;
	stek* right;
};

stek* kon = NULL;//���������� ��������� ����� ��������� ����� 


void make_stek(int n) {
	int t = 1;//������� ��������� �����
	stek* p = new(stek);//������������� ������� ���� ����� � �������� ��������
	p->left = NULL;
	p->right = NULL;
	cout << "\n������� " << t << "-�� ���� �����:";
	cin >> p->key;//���� ����� i-�� ������ 
	kon = p;
	t++;
	for (int i = n; i > 1; i--) {//������������� ��������� ����� �����
		stek * p = new(stek);
		cout << "\n������� " << t << "-�� ���� �����:";
		cin >> p->key;//���� ����� i-�� ������ 
		p->right = kon;
		p->left = NULL;
		kon->left = p;
		kon = p;
		t++;
	}
}

void cout_stek() {
	stek* mm = kon;//��������� �� ����� �����
	stek* jj = kon;//��������� �� ����� �����
	int i = 1;//������������� �������� ��� ������ ������ ���� ������ 
	bool flag = true;
	if (kon == NULL) {//����� �� �������, ���� ���������� ��������� ��� ������ 
		cout << "\n����� �� ����������!!!\n";
		return;
	}
	else {
		while ((mm->right) != NULL) {//�������� ������ �� ������������� 
			if ((mm->key) != 0)flag = false;
			mm = mm->right;
		}
		if (((mm->right) == NULL) && ((mm->left) == NULL) && ((mm->key) != 0)) {//�������� ������ �� �������������, ���� ������ ������� �� 1 ���� 
			flag = false;
		}
		if (flag == false) {//����� ������ 
			cout << "\n��� ����: NULL";
			while ((jj->right) != NULL) {
				cout << " <- " << jj->key;
				jj = jj->right;
				i++;
			}
			cout << " <- " << jj->key << " ]\n";
		}
		else {
			cout << "\n���� ����!!!\n";
		}

	}
}

void udalit() {
	int hh, nn;
	stek * kk = kon;//������������� ��������� �� ������ ���� ������

	stek * f, * G, * D;//������������� ���������� ��� ���������� ��������

	if (kk == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	if (((kk->right) == NULL)) {//�������� ����������� ����� 
		cout << "\n�������� ����������!!!!\n";
		return;

	}
	cout << endl;
	cout << "������� � ���� �� �������� ������ ������� ����� ��� ������� ���� (�� 2-" << kol << "):";
	cin >> hh;
	cout << "������� ���������� ����� ������� ������ ������� (�� 1-" << hh - 1 << "):";
	cin >> nn;
	int x = 0;
	if (nn == hh - 1) {
			f = new(stek);//�������� ������� ���� ������ ����� 
			f->left = NULL;
			f->right = NULL;
			f->key = kk->key; 
			G = f;
			kk = kk->right;
			for (int i = kol; i > hh; i--) {//�������� ��������� ����� ������ ����� 
				f = new(stek);
				f->left = NULL;
				f->right = G;
				f->key = kk->key;
				G = f;
				kk = kk->right;
		     }
			while (kk->right != NULL) {//�������� ����� �� ������� �����
				f = kk;
				kk=kk->right; 
				delete f; 
			}
			delete kk;
			if ((G->right != NULL) && (G->left == NULL)) {//������������� ����� ���������� �� �� ������ ���� 
				f = new(stek);//�������� ��������� �� ������ ���� ����� 
				f->left = NULL;
				f->right = NULL;
				f->key = G->key;
				kon = f;//���������������� ���������  ����� ����� 
				G = G->right;
				while (G->right != NULL) {
					f = new(stek);
					f->left = NULL;
					f->right = kon;
					f->key = G->key;
					kon = f;
					G = G->right;
			     }
				f = new(stek);
				f->left = NULL;
				f->right = kon;
				f->key = G->key;
				kon = f;
			}
			else {//������������� ����� ���������� �� ������ ���� 
				kon = G;
			}
	}
	else {
		f = new(stek);//�������� ������� ���� ������ ����� 
		f->left = NULL;
		f->right = NULL;
		f->key = kk->key;
		G = f;
		kk = kk->right;
		for (int i = kol; i > hh; i--) {//�������� ��������� ����� ������ ����� 
			f = new(stek);
			f->left = NULL;
			f->right = G;
			f->key = kk->key;
			G = f;
			kk = kk->right;
		}
		for (int y = 1; y <= nn; y++) {//�������� ����� �� ������� �����
			f = kk;
			kk = kk->right;
			delete f;
		}
		kon = kk;//���������������� ���������  ����� ����� 
		while (G->right != NULL) {//������������� ������ ����� � ������ 
			f = G;
			G = G->right;
			kon->left = f;
			f->right = kon;
			f->left = NULL;
			kon = f;
		}
		f = G;
		kon->left = f;
		f->right = kon;
		f->left = NULL;
		kon = f;
	}
	kol -= nn;
}

void dobav_stek() {
	if (kon == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	cout << "\n������� ���������� �����,������� �� ������ �������� � ����� �����:";
	int vv;
	int d = 1;
	cin >> vv;
	if (vv < 1) {
		cout << "������������ ����. ����� ��������� ��������\n";
		dobav_stek();//����������� ����� ������� ��� ������������ �����
	}
	kol += vv;
	for (int r = 0; r < vv; r++) {
		stek* hh = new(stek);
		cout << "\n������� " << d << "-�� ����������� ������� �������:";
		cin >> hh->key;//���� ����� i-�� ������ 
		hh->right = kon;
		hh->left = NULL;
		kon->left = hh;
		kon = hh;
		d++;
	}
}

void unich() {
	if (kon == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	while (kon->right != NULL) {//�������� ����� ������ �� ������ 
		stek* mm = kon->right;
		delete kon;
		kon = mm;
	}
	delete kon;//�������� ���������� ���� ������ �� ������ 
	kon = NULL;
	return;
}

void file1() {
	int f = 0;//�������� ���������� 
	FILE* kk;//������ �� ����
	stek* point = kon;
	if (kon == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	if ((kk = fopen("123.txt", "w")) == NULL) {//�������� ������� �����
		cout << "��������� ������\n";
		exit(1);
	}
	while (point->right != NULL) {//������ ����� ������� � ����
		f = point->key;
		fwrite(&f, sizeof(int), 1, kk);
		point = point->right;
	}
	f = point->key;//������ ����������� ���� ������ � ����
	fwrite(&f, sizeof(int), 1, kk);
	fclose(kk);
}

void file2() {
	kol = 0;
	int  g;//�������� ���������� ��� ������ ����� � �����
	FILE* G;
	if ((G = fopen("123.txt", "r")) == NULL) {
		cout << "��������� ������\n";
		exit(1);
	}
	fread(&g, sizeof(int), 1, G);
	stek* p = new(stek);//������� ��������� ��������� �� ������ ���� ����� 
	p->right = NULL;
	p->left = NULL;
	p->key = g;
	kon = p;
	kol++;

	while (fread(&g, sizeof(int), 1, G)) {
		stek* m = new(stek);//������� ��������� ��������� �� ����������� ���� ����� 
		m->right = NULL;
		m->left = p;
		m->key = g;
		p->right = m;
		p = m;
		kol++;
	}
	cout << "\nE��� �� 8-�� ������� �� �������� � ������ �������, �� �� ����� ������.\n";
	return;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	int h;
	while (true) {
		cout << "\n������� ����� ��������.\n1)C������ ����\n2)������� �������\n3)������� � ���������\n4)�������� � ���������\n5)������� ����\n6)��������� ���� � ����\n7)������� ���� �� �����\n8)������� ���������\n �=";
		cin >> n;
		switch (n) {
		case 1:cout << "\n������� ���������� ��������� � �����:"; cin >> h; kol = h; make_stek(h); break;
		case 2: cout_stek();  break;
		case 3: udalit(); ; break;
		case 4: dobav_stek(); break;
		case 5: unich(); break;
		case 6: file1(); cout << "7+\n"; break;
		case 7: file2(); break;
		case 8: return 0;
		default: cout << "\n!!������������ ����!!\n";
		}
	}
}