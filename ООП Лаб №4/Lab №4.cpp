#include "Triad.h"
#include "time.h"
#include <iostream>
using namespace std;
void f1(Triad& c)
{
	c.set_first(22);
	cout << c;
}

Triad f2()
{
	TIME l( 1, 2, 3);
	int s = l.get_hours();
	int y= l.get_minutes();
	int j = l.get_seconds(); 
	Triad bb(s,y,j);
	return bb;
}

int main(){
	//������ � ������� TIME 
	TIME c (11,22,30); 
	TIME b(c);
	cout <<"\n���������=" << (b == c);
	cout << "\n�����������=" << (b != c);
	TIME vv(33, 22, 11);
	c = vv;
	cout << "\n������=" << (b > c);
	cout << "\n������=" << (b < c);
	cout << "\n������=" << (b >= c);
	cout << "\n������=" << (b <= c);
	//������ � ������� Triad
	Triad gg;
	f1(gg);
	cout << gg;
	gg = f2();
	cout << gg;
}