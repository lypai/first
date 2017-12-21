#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
void print(const T & value)
{
	cout<<value<< endl;
}
static int value;
struct Million
{
	bool operator()(const int & a)
    {
		return abs(a - value) <= 1000000;
    }
};

int main()
{
	int t[] = { 24256800, 23500000, 21516000, 12038175, 16970105,16787941, 16060303, 14025000, 13513734, 12478447 };
	vector<int> populations(t, t + 10);
	int new_value;
	cout<< "Enter number: ";
	cin >> new_value;
	value = new_value;
	replace_if(populations.begin(), populations.end(), Million() , new_value);
	for_each(populations.begin(), populations.end(), print<int>);
	system("pause");
	return 0;
}