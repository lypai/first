#include <iostream>
using namespace std;

struct Time
{
	int Hours, Minutes;
};

int main(void)
{
	Time current, next;
	cout << "Enter hours: ";
	cin >> current.Hours;
	cout << "Enter minutes: ";
	cin >> current.Minutes;
	int addedMinutes;
	cout << "Add minutes: ";
	cin >> addedMinutes;
	int minutes = current.Minutes + current.Hours*60 + addedMinutes;
	next.Hours = (minutes / 60) % 24;
	next.Minutes = minutes % 60;
	cout << next.Hours << ":" << next.Minutes << endl;
	system("pause");
	return 0;
}