#include "Sotrudnik.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(0, "ru");
	Sotrudnik t;
	t.show();
	cout << endl;
	Sotrudnik v("C������", "���������", 321651);
	cout << endl;
	v.show();
	Sotrudnik c =v;
	c.show();
	cout << endl;
	c.set_name("�������");
	string h = c.get_name();
	cout << h << endl;
	c.set_dolgn("C��������");
	int vv = c.get_zp();
	cout << vv << "!!";
}