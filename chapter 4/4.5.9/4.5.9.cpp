#include <string>
#include <iostream>
#include <regex>
using namespace std;

int main()
{
	string password;
	getline(cin, password);
	bool isValid = true;
	if(password.size() < 8)
	{
		isValid = false;
		cout << "The password must be 8 characters long" << endl;
	}

	if(!regex_match(password, regex(".*[A-Z].*")))
	{
		isValid = false;
		cout << "The password must have at least one upper case letter" << endl;
	}

	if(!regex_match(password, regex(".*[a-z].*")))
	{
		isValid = false;
		cout << "The password must have at least one lower case letter" << endl;
	}

	if(!regex_match(password, regex(".*[0-9].*")))
	{
		isValid = false;
		cout << "The password must have at least one digit" << endl;
	}

	if(!regex_match(password, regex(".*[`~!@#$%^&\\*()-_=\\+?/.\\<>].*")))
	{
		isValid = false;
		cout << "The password must have at least one special character" << endl;
	}
	if(isValid) cout << "The password is valid" <<endl;
	system("pause");
	return 0;
}