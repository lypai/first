#include <iostream>
using namespace std;

int main(void)
{
	int n;
	double result = 1;
	cout << "Enter the number of negative power: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		result /= 2;
	}
	cout.precision(10);
	cout << result << endl;
	system("pause");
	return 0;
}