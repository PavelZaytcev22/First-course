#include <iostream>
#include <ctime>
using namespace std;
#include "plenty.h"
#include "plenty.cpp"
#include "Money.h"

int main() {
	Money p(11,20);
	Money m(15,20);
	plenty <Money> B(10,m);//�������� ��������� �� Money
	cout << B;//����� ��������� 
	cout << (B<p);//�������������� ���������� Money ��������� 
}