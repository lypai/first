#include <iostream>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

bool isLeap(int year) {
	if(year % 4 != 0) return false;
	else if(year % 100 != 0) return true;
	else if(year % 400 != 0) return false;
	return true;
}

int monthLength(int year, int month)
{
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeap(year))
		return 29;
	else return days[month - 1];
}

int dayOfYear(Date date) {
	int day = 0;
	for(int i = 1; i < (date.month); i++)
	{
		day += monthLength(date.year, i);
	}
	day += date.day;
	return day;
}

int main(void) {
	Date d;
	cout << "Enter year month day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;
	system("pause");
	return 0;
}