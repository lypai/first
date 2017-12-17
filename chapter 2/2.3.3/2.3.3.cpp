#include <iostream>
using namespace std;

int main(void)
{
	int n;
	unsigned long long result = 1;
	cout << "Enter the number of power: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		result *= 2;
	}
	cout << result << endl;
	system("pause");
	return 0;
}