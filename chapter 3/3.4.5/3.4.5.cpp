#include <iostream>
#include <ctime>
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

Date today(void) {
	Date todayDate;
	time_t t = time(NULL);
	tm tl = *localtime(&t);
	todayDate.year = tl.tm_year+1900;
	todayDate.month = tl.tm_mon+1;
	todayDate.day = tl.tm_mday;
	return todayDate;
}

int main(void) {
	Date t = today();
	cout << t.year << "-" << t.month << "-" << t.day << endl;
	system("pause");
	return 0;
}