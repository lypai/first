#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void)
{
	int sys;
	float m, ft, in;
	const float FOOTS_IN_METER = 3.2808398950131;
	const float INCHES_IN_FOOT = 12;
	cout << "Please choose system of measurement: 0 for metric, 1 for imperial" << endl;
	cin >> sys;

	while (sys != 1 || sys != 0)
	{
		cout << "Please choose system of measurement that we actualy propose, dumbass: 0 for metric, 1 for imperial" << endl;
		cin >> sys;
	}
	if (sys == 0)
	{
		cout << "Enter value: " << endl;
		cin >> m;
		while ( m <= 0 )
		{
			cout << "Enter positive value:" << endl;
			cin >> m;
		}
		ft = (int) (m * FOOTS_IN_METER);
		in = (m * FOOTS_IN_METER  - ft) * INCHES_IN_FOOT; 
		cout << ft << "'" << in << "\"" << endl;
	}
	else
	{
		cout << "Enter VALUE: ";
		cin >> m;
		while ( m <= 0 )
		{
			cout << "Enter positive value:" << endl;
			cin >> m;
		}
		ft = (int) (m * FOOTS_IN_METER);
		in = (m * FOOTS_IN_METER  - ft) * INCHES_IN_FOOT; 
		cout << ft << "'" << in << "\"" << endl;
	}
	return 0;
}