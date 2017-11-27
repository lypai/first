#include <iostream>
#include <iomanip>

using namespace std;

int main(void)
{
	float x1, x2, x3, x4, x5;
	cin >> x1;
	cin >> x2;
	cin >> x3;
	cin >> x4;
	cin >> x5;
	cout<<fixed<<setprecision(1)<<x1<<endl;
	cout<<fixed<<setprecision(2)<<x2<<endl;
	cout<<fixed<<setprecision(6)<<x3<<endl;
	cout<<fixed<<setprecision(2)<<x4<<endl;
	cout<<fixed<<setprecision(0)<<x5<<endl;
	system("pause");
}

