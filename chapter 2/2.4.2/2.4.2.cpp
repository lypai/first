#include <iostream>
using namespace std;

int main(void)
{
	unsigned short int val;
	bool ispalindrome = false;
	cout << "value = ";
	cin >> val;
	string bin = bitset<8>(val).to_string();
    string old_bin = bin;
    reverse(bin.begin(), bin.end());
	if (ispalindrome)
		cout << val << " is a bitwise palindrome" << endl;
	else
		cout << val << " is not a bitwise palindrome" << endl; 
	return 0;
}