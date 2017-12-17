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

int daysBetween(Date d1, Date d2) {
	if (d1.year == d2.year)
		return dayOfYear(d2) - dayOfYear(d1);
	else
	{
		int i = dayOfYear(d2) + 365 - dayOfYear(d1);
		if (isLeap(d1.year))
			i++;
		for (int n = d1.year + 1; n < d2.year; n++)
		{
			i += 365;
			if (isLeap(n))
				i++;
		}
		return i;
	}
}

int main(void) {
	 Date since,till;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> till.year >> till.month >> till.day;
	cout << daysBetween(since,till) << endl;
	system("pause");
	return 0;
}