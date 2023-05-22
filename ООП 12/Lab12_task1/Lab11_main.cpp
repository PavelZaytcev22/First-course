#include <iostream>
#include <set>
using namespace std;

typedef set<int, less<int> > Tset;//���������� ��� ��� ������ �� ����������
typedef Tset::iterator it;//��������

//������� ��� �������� ��������� 
Tset make_set(int n)
{
	Tset m;//������ ��������� 
	int a;
	for (int i = 0; i < n; i++)
	{
		cout << "?";
		cin >> a;
		//������� ���� � ��������� �� � ���������
		m.insert(a);
	}
	return m;//���������� ������� ��� ��������� ������ �������
}

//������� ��� ������ ��������� 
void print_set(Tset m)
{
	cout << endl;
	for (int n : m)
		cout << " (" << n << ") ";
}

//������� 4
Tset del(Tset c1) {
	int b;
	cout << "\n������� �������:";
		cin >> b;
		c1.erase(b);
		return c1;
}
//������� 5
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
	x = (x / c1.size());//������� �������� ��������� ��������� 
	for (int m = 0; m < i; m++) {//�������� ���� ��������� �� ��������� 
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