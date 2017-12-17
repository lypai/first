#include <iostream>
using namespace std;

int main(void)
{
	long long x1 = 0, x2 = 1, res = 1;
	int n;
	cout << "Enter number of number Fibonacci: ";
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		res = x1 + x2;
		x2 = x1;
		x1 = res;
	}
	cout << res << endl;
	system("pause");
	return 0;
}