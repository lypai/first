#include <iostream>
using namespace std;

int main(void)
{
	int number;
	long long result = 0;
	cout << "Enter the number of iterations: ";
	cin >> number;
	for (int i = 1; i <= number; i++)
	{
		result += i;
	}
	cout << result;
	system("pause");
	return 0;
}