#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	int x1, x2, x3, x4;
	cin >> x1;
	while (x1 < 1 || x1 > 255)
	{
		cout << "incorrect data please enter again" << endl;
		cin >> x1;
	}
	cin >> x2;
	while (x2 < 1 || x2 > 255)
	{
		cout << "incorrect data please enter again" << endl;
		cin >> x2;
	}
	cin >> x3;
	while (x3 < 1 || x3 > 255)
	{
		cout << "incorrect data please enter again" << endl;
		cin >> x3;
	}
	cin >> x4;
	while (x4 < 1 || x4 > 255)
	{
		cout << "incorrect data please enter again" << endl;
		cin >> x4;
	}
	cout << x1 << '.' << x2 << '.' << x3 << '.' << x4 << endl;
	system("pause");
	return (0);
}