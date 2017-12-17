#include <iostream>
using namespace std;

int main(void) 
{
	double pi4 = 0.0;
	long n;
	int add = 1;
	cout << "Number of iterations? ";
	cin >> n;
	for(long i = 1; i <= n; i++)
	{
		if(add == 1) 
		{
			pi4 += 1.0 / (2.0 * i - 1.0);
		}
		else 
		{
			pi4 -= 1.0 / (2.0 * i - 1.0);
		}
		add = -add;
	}
	cout.precision(20);
	cout << "Pi = " << (pi4 * 4.) << endl;
	system("pause");
	return 0;
}