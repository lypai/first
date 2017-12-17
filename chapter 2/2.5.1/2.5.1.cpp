#include <iostream>
using namespace std;

int main(void)
{
	cout << "MENU:\n0 - exit\n1 - addition\n2 - subtraction\n" 
 << "3 - multiplication\n4 - division\nYour choice? ";
	int operationNumber;
	cin >> operationNumber;
	while(operationNumber != 0)
	{
		cout << "Enter first number: ";
		int x, y, res = 0;
		cin >> x;
		cout << "Enter second number: ";
		cin >> y;
		switch ( operationNumber ) {
			case 1:
			{
				res = x + y;
				cout << "Result: " << res << endl;
			}
			break;
			case 2:
			{
				res = x - y;
				cout << "Result: " <<res << endl;
			}
			break;
			case 3:
			{
				res = x * y;
				cout << "Result: " <<res << endl;
			}
			break;
			case 4:
				{
			if(y!= 0) 
					{
						res = x / y;
						cout << "Result: " << res << endl;
					}
					else
					{
						cout << "Cannot divide by zero!" << endl;
					}
				}
			break;
		}
		cout << "MENU:\n0 - exit\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\nYour choice? ";
		cin >> operationNumber;
	}
	return 0;
}