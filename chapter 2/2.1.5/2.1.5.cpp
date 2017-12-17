#include <iostream>
using namespace std;

int main(void)
{
	int year, day;
	cout << "Enter year: ";
	cin >> year;
	int a, b , c, d, e;
	a = year % 19;
	b = year % 4;
	c = year % 7;
	d = (a * 19 + 24) % 30;
	e = (2*b + 4*c + 6*d + 5) % 7;
	if((d + e) < 10)
	{
		day = d + e + 22;
		cout << "March " << day << endl;
	}
	else 
	{
		day = (d + e - 9);
		cout << "April " << day << endl;
	}
	return 0;
}
