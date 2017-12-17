#include <iostream>
using namespace std;

int main(void)
{
	const int max = 60;
	int n;
	cout << "Enter a positive integer value greater then 1: ";
	cin >> n;
	while (n <= 1)
	{
		cout << "Enter a positive value or greater then 1: ";
		cin >> n;
	}
	if (n < max)
	{
		cout << '+';
		for(int i = 0; i < (n -2); i++)
		cout << '-';
		cout << '+' << endl;
		for(int i = 0; i < (n - 2); i++) 
		{
		cout << '|';
		for(int j = 0; j < (n -2); j++)
		cout << ' ';
		cout << '|' << endl;
		}
		cout << '+';
		for(int i = 0; i < (n - 2); i++)
		cout << '-';
		cout << '+' << endl;
	}
	else 
	{
		cout << "Sorry, the side size is too big" << endl;
	}
	system("pause");
	return 0;
}