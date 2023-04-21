#include "TIME.h"
#include <iostream>
using namespace std;

//Переопределенная виртуальная функция 
void TIME::Show() {
	cout << "\nhours= " << hour;
	cout << "\nminutes = " << minute;
	cout << "\nseconds= " << seconds;
}

//Конструктор без параметров 
TIME::TIME() :Triad() {
	hour = first;
	minute = second;
	seconds = third;
}
//Конструктор с параметрами 
TIME::TIME(int f, int s, int t) :Triad(f, s, t) {
	hour = first;
	minute = second;
	seconds = third;
}
//Конструктор с копирования 
TIME::TIME(const TIME& t) {
	hour = t.hour;
	minute = t.minute;
	seconds = t.seconds;
}


//Перегрузка потоковых операторов вводы и вывода 
istream& operator>>(istream& in, TIME& l)
{
	cout << "\nhour:"; in >> l.hour;
	cout << "\nminute:"; in >> l.minute;
	cout << "\nsecond:"; in >> l.seconds;
	return in;
}
ostream& operator<<(ostream& out, const TIME& l)
{
	out << l.hour << ":" << l.minute << ":" << l.seconds;
	return out;
}

//перегрузка оператора присваивания
TIME& TIME::operator=(const TIME& l) {
	if (&l == this) return *this;
	hour = l.hour;
	minute = l.minute;
	second = l.second;
	return *this;
}

//Перегрузка операторов сравнения 
bool operator==(const TIME& c1, const TIME& c2) {
	if ((c1.hour == c2.hour) && (c1.minute == c2.minute) && (c1.seconds == c2.seconds)) {
		return 1;
	}
	else return 0;
}
bool operator!=(const TIME& c1, const TIME& c2) {
	if ((c1.hour != c2.hour) || (c1.minute != c2.minute) || (c1.seconds != c2.seconds)) {
		return 1;
	}
	else return 0;
}
bool operator >(const TIME& c1, const TIME& c2) {
	if (c1.hour > c2.hour) {
		return 1;
	}
	if (c1.hour < c2.hour) {
		return 0;
	}
	if (c1.hour == c2.hour) {
		if (c1.minute > c2.minute) {
			return 1;
		}
		if (c1.minute < c2.minute) {
			return 0;
		}
		if (c1.minute == c2.minute) {
			if (c1.seconds > c2.seconds) {
				return 1;
			}
			if (c1.seconds < c2.seconds) {
				return 0;
			}
		}
	}
}
bool operator <(const TIME& c1, const TIME& c2) {
	if (c1.hour < c2.hour) {
		return 1;
	}
	if (c1.hour < c2.hour) {
		return 0;
	}
	if (c1.hour == c2.hour) {
		if (c1.minute < c2.minute) {
			return 1;
		}
		if (c1.minute > c2.minute) {
			return 0;
		}
		if (c1.minute == c2.minute) {
			if (c1.seconds < c2.seconds) {
				return 1;
			}
			if (c1.seconds > c2.seconds) {
				return 0;
			}
		}
	}
}
bool operator >=(const TIME& c1, const TIME& c2) {
	if (c1.hour > c2.hour) {
		return 1;
	}
	if (c1.hour < c2.hour) {
		return 0;
	}
	if (c1.hour == c2.hour) {
		if (c1.minute > c2.minute) {
			return 1;
		}
		if (c1.minute < c2.minute) {
			return 0;
		}
		if (c1.minute == c2.minute) {
			if (c1.seconds > c2.seconds) {
				return 1;
			}
			if (c1.seconds < c2.seconds) {
				return 0;
			}
			if (c1.seconds == c2.seconds) {
				return 1;
			}
		}
	}
}
bool operator <=(const TIME& c1, const TIME& c2) {
	if (c1.hour < c2.hour) {
		return 1;
	}
	if (c1.hour < c2.hour) {
		return 0;
	}
	if (c1.hour == c2.hour) {
		if (c1.minute < c2.minute) {
			return 1;
		}
		if (c1.minute > c2.minute) {
			return 0;
		}
		if (c1.minute == c2.minute) {
			if (c1.seconds < c2.seconds) {
				return 1;
			}
			if (c1.seconds > c2.seconds) {
				return 0;
			}
			if (c1.seconds == c2.seconds) {
				return 1;
			}
		}
	}
}
