#include <iostream>
#include <cmath>
using namespace std;
#include "fraction.h"

void fraction::Init(double F, double S)
{
	first = F; second = S;
}
void fraction::Read()
{
	cout << "\nfirst?"; cin >> first;
	cout << "\nsecond?"; cin >> second;
}
void fraction::Show()
{
	cout << "\nfirst=" << first;
	cout << "\nsecond=" << second;
	cout << "\n";
}

double fraction::Power()
{
	return pow(first, second);
}

void fraction:: distance() {
	cout << "Длинна вектора:" << sqrt(first * first + second * second);
}