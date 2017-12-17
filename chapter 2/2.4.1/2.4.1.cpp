#include <iostream>
using namespace std;

int main(void)
{
	unsigned long n;
	cout << "Enter positive: ";
	cin >> n;
	unsigned long count = 0;
    for (; n; count++)
		n &= (n - 1);
	cout << count << endl;
	system("pause");
	return 0;
}