#include <iostream>
using namespace std;

int main(void) 
{
	int side;
	cout << "Enter an odd value (side size): ";
	cin >> side;
	long long res = 1 + 4 * (side / 2) * (side / 2);
	cout << res << endl;	
	system("pause");
	return 0;
}