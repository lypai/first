#include "stdafx.h"
#include <iostream>

using namespace std;

int main(void)
{
	float grossprice, taxrate, netprice, taxvalue;
	cout << "Enter a gross price: ";
	cin >> grossprice;
	cout << "Enter a tax rate: ";
	cin >> taxrate;
	
	while (grossprice < 0)
	{
		cout << "Enter a real gross price: ";
		cin >> grossprice;
	}
	while (taxrate < 0 || taxrate > 100)
	{
		cout << "Enter a reasonable tax rate: ";
		cin >> taxrate;
	}

	netprice = (grossprice / (100 + taxrate)) * 100;
	taxvalue =( netprice / 100 ) * taxrate;

	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	system("pause");
	return 0;
}