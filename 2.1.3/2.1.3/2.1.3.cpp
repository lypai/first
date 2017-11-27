#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void)
{
	int sys;
	float m, ft, in;

	cout << "Please choose system of measurement: 0 for metric, 1 for imperial" << endl;
	cin >> sys;

	while (sys != 1 || sys != 0)
	{
		cout << "Please choose system of measurement that we actualy propose, dumbass: 0 for metric, 1 for imperial" << endl;
		cin >> sys;
	}
	if (sys = 0)
	{
		cout << "Enter value:" << endl;
		cin >> m;
		while ( m <= 0 )
		{
			cout << "Youre parents arent proud of you, are they? Anyway enter POSITIVE value that this program CAN convert:" << endl;
			cin >> m;
		}
	}
	else
	{

	}


	system("pause");
	return 0;
}