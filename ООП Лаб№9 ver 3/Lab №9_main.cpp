#include "plenty.h"
#include "Error.h"
#include<iostream>
#include <stdio.h>
#include <stdarg.h>
using namespace std;

int main() {
		try
		{
			plenty x(2);
			plenty y(10,25);
			cout << x;
			cout <<"\nx=" << x[1] << endl;
			cout <<endl<< y;
			--x;
			--x;//Выход за границы множества 
			cout << x;
			y + 20;//Выход за границы множества 
		}
		catch (Error& e)
		{
			e.what();
		}
		return 0;
	}