#include <iostream>
using namespace std;
 
int main(void)
{
   double year, mounth, day, weekday;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter mounth: ";
	cin >> mounth;
	cout << "Enter day: ";
	cin >> day;
	bool dataIsValid = (year >= 1900 && year < 2100 &&
		mounth >=1 && mounth <= 12 && day > 0 && day < 32);
	if (dataIsValid)
	{
		mounth -= 2;
		if (mounth < 0) 
		{
			mounth +=12;
			year--;
		}
		mounth *= 83;
		mounth /= 32.0;
		mounth += day;
		mounth += year;
		mounth += (year / 4.0);
		mounth -= (year / 100.0);
		mounth += (year / 400.0);
		cout << "month = " << mounth << endl;
		weekday = ((int) mounth) % 7;
		cout << weekday << endl;
	}
	return 0;
}