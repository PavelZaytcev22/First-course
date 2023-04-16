#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <windows.h>
using namespace std;
int kol = 0;//������� ���������� �����

struct och{
	int key;
	och* left;
	och* right;
};

och* nach = NULL;//���������� ��������� ������ � ����� ������� 
och * kon = NULL;

void make_och(int n) {
	nach = new(och);//�������� ������� �������� ������� 
	nach->left = NULL;
	nach->right = NULL;
	nach->key = 0;
	kon = nach;
	for (int i = n; i > 1; i--) {//�������� ����������� ��������� �������
		och*p = new(och);
		p->key = 0;
		p->right = kon;
		p->left = NULL;
		kon->left=p;
		kon = p;
	}
}

void vvod_och() {
	int i = 1;//������������� �������� ��� ������ ������ ���� ������ 
	och* hh = nach;
	if (kon != NULL) {
		if ((kon->right != NULL)) {
			while ((hh->left) != NULL) {
				cout << "������� " << i << "-�� ���� �������:";
				cin >> hh->key;//���� ����� i-�� ������ 
				cout << endl;
				i++;
				hh = hh->left;//������� �� ��������� ���� ������ 
			}
			cout << "������� " << i << "-�� ���� ������:";
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

void cout_och() {
	och* mm = nach;//������������� ��������� �� ������ ���� ������
	och* jj = kon;
	int i = 1;//������������� �������� ��� ������ ������ ���� ������ 
	bool flag = true;
	if (mm == NULL) {//����� �� �������, ���� ���������� ��������� ��� ������ 
		cout << "\n������ �� ����������!!!\n";
		return;
	}
	else {
		while ((mm->left) != NULL) {//�������� ������ �� ������������� 
			if ((mm->key) != 0)flag = false;
			mm = mm->left;
		}
		if (((mm->right) == NULL) &&((mm->left) == NULL) && ((mm->key) != 0)) {//�������� ������ �� �������������, ���� ������ ������� �� 1 ���� 
			flag = false;
		}
		if (flag == false) {//����� ������ 
			cout << "\n���� �������: ";
			while ((jj->right) != NULL) {
				cout  << jj->key << " -> ";
				jj= jj->right;
				i++;
			}
			cout << jj->key << " -> NULL\n";
		}
		else {
			cout << "\n������ ����!!!\n";
		}

	}
}

void shag() {
	if (kon == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	if (nach->left != NULL) {//������� ������� �������� ������� � ��� ����� 
		och* bb = nach->left;//��������� �� ��������� ������� �������
		nach->left = NULL;
		nach->right = kon;
		kon->left = nach;
		bb->right = NULL;
		kon = nach;
		nach = bb;
	}
}

void izoch() {
	if (kon == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	if (nach->left != NULL) {//�������� ������� �������� �������
		och* nn = nach->left;//��������� �� ��������� ������� �������
		nn->right = NULL;
		nach->left = NULL;
		nach->right = NULL;
		delete nach;//�������� ���� 
		nach = nn;//������� ��������� ����� ������� 
	}
}
 
void udalit() {
	int hh, nn;
	och* kk = kon;//������������� ��������� �� ������ ���� ������

	och* f, * G, * D;//������������� ���������� ��� ���������� ��������

	if (kk == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
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
		for (int i = 1; i < hh; i++) {//�������� ��������� �� ������ ������� 
			izoch();//����� ������� �������� �������� �������
		}
	}
	else {
		for (int h = 1; h <=(hh - 1 - nn); h++) {//������� ��������� � ����� �������
			shag();//����� ������� �������� ������� �������� ������� � �� ����� 
		}
		for (int x = 0; x < nn; x++) {//������� ��������� �� �������
			izoch();//����� ������� �������� �������� �������
		}
	}
	kol -= nn;
}

void dobav_och() {
	if (kon == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	cout << "\n������� ���������� �����,������� �� ������ �������� � ����� �������:";
	int vv;
	int d = 1;//������� ����� ������ 
	cin >> vv;
	if (vv < 1) {
		cout << "������������ ����. ����� ��������� ��������\n";
		dobav_och();//����������� ����� ������� ��� ������������ �����
	}
	kol += vv;
	for (int r = 0; r < vv; r++) {
		och* hh = new(och);
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
	while (kon->right!= NULL) {//�������� ����� ������ �� ������ 
		och* mm = kon->right;//�������� ���� ���������� �������� �������
		delete kon;//�������� ����
		kon = mm;//������� ���� �� ��������� ������� �������
	}
	delete kon;//�������� ���������� ���� ������ �� ������ 
	kon = NULL; 
	nach = NULL;
	return;
}

void file1() {
	int f = 0;//�������� ���������� 
	FILE* kk;//������ �� ����
	och* point = nach;
	if (kon == NULL) {//�������� �� ������������� ������������� ���������
		cout << "\n!!!������!!!\n";
		return;
	}
	if ((kk = fopen("123.txt", "w")) == NULL) {//�������� ������� �����
		cout << "��������� ������\n";
		exit(1);
	}
	while (point->left!= NULL) {//������ ����� ������� � ����
		f = point->key;
		fwrite(&f, sizeof(int), 1, kk);
		point = point->left;
	}
	f = point->key;//������ ����������� ���� ������ � ����
	fwrite(&f, sizeof(int), 1, kk);
	fclose(kk);
}

void file2() {
	kol = 0;
	int  g;//�������� ���������� ��� ������ ����� � �����
	FILE* G;//���������� ������ �� ����
	if ((G = fopen("123.txt", "r")) == NULL){ //�������� ������� ����� � �������� ��� ��� ������ 
		cout << "��������� ������\n";
		exit(1);
	}
	fread(&g, sizeof(int), 1, G);//���������� ���� � ����� 
	och* p = new(och);//�������� ��������� �� ������ ���� �������
	p->right = NULL;
	p->left = NULL;
	p->key = g;
	 nach= p;
	 kon = p;
	 kol ++;
	while (fread(&g, sizeof(int), 1, G)) {//���� ���������� ������ ��������� �����, ��������� ����� ���� 
		och *m = new(och);
		m->right = kon;
		m->left = NULL;
		m->key = g;
		kon->left = m;
		kon = m;
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
		cout << "\n������� ����� ��������.\n1)C������ �������\n2)��������� �������\n3)������� �������\n4)������� � ���������\n5)�������� � ���������\n6)������� �������\n7)��������� ������� � ����\n8)������� ������� �� �����\n9)����������� ������� \n10)������� ���������\n �=";
		cin >> n;
		switch (n) {
		case 1:cout << "\n������� ���������� ��������� � �������:"; cin >> h; kol = h; make_och(h); break;
		case 2: vvod_och();  break;
		case 3: cout_och();  break;
		case 4: udalit(); ; break;
		case 5: dobav_och(); break;
		case 6: unich(); break;
		case 7: file1(); cout << "7+\n"; break;
		case 8: file2(); break;
		case 9: cout << "\n������� ���������� ����������� �� �����:"; cin >> h; for (int y = 0; y < h; y++)shag(); break;
		case 10: return 0;
		default: cout << "\n!!������������ ����!!\n";
		}
	}
}