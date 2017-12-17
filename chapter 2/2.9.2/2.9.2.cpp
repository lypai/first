#include <iostream>
using namespace std;

int main(void)
{
	cout << "Enter number of money: ";
	int number, i = 0;
	cin >> number;
	int banknotes[5] = {50, 20, 10, 5, 1};
	while (number > 0)
	{
		if (number < banknotes[i])
			i++;
		else
		{
			cout << banknotes[i] << " ";
			number -= banknotes[i];
		}
	}
	cout << endl;
	system("pause");
	return 0;
}