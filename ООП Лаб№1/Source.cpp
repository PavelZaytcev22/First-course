#include <cmath>
#include <iostream>
using namespace std;
#include "fraction.h"

int main() {
	setlocale(LC_ALL, "rus");
	fraction h;
	h.Init(1.0, 1.0);
	h.Show();
	h.distance();
}