#include <iostream>
#include <string>
using namespace std;

struct Time
{
	int Hours, Minutes;
};

int main(void) {
	
	Time startTime, endTime, diffTime;
	startTime.Hours = 0;
	startTime.Minutes = 0;
	endTime.Hours = 0;
	endTime.Minutes = 0;
	diffTime.Hours = 0;
	diffTime.Minutes = 0;	
	cout << "Enter start time: ";
    scanf ("%i %i",&startTime.Hours, &startTime.Minutes);
	cout << "Enter end time: ";
	scanf ("%i %i",&endTime.Hours, &endTime.Minutes);
	int startMinutes = startTime.Minutes + startTime.Hours * 60;
	int endMinutes = endTime.Minutes + endTime.Hours * 60;
	int diffMins = endMinutes - startMinutes;
	diffTime.Hours = diffMins / 60;
	diffTime.Minutes = diffMins % 60;
	cout << diffTime.Hours << ":" << diffTime.Minutes << endl;
	system("pause");
	return 0;
}