#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	bool answer = true;
	float x1, x2;
	cout << "Input first value: ";
	cin >> x1;
	cout << "Input second value: ";
	cin >> x2;
	if (x1 - x2 > 0.000001 || x2 - x1 > 0.000001)
		answer = false;
	cout << (answer ? "Results are equal (by 0.000001 epsilon)" : "Results are not equal (by 0.000001 epsilon)") << endl;
	system("pause");
	return (0);
}