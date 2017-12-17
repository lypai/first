#include <iostream>
using namespace std;

int main(void)
{
	cout << "Enter a number: ";
	int n;
	cin >> n;
	long long result = 1;
	if(n != 0) 
	{
		int i = 1;
		while(i <= n)
		{
			result *= i;
			i++;
		}
	}
	cout << result << endl;
	system("pause");
	return 0;
}