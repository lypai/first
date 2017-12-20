#include <iostream>
#include <string>
using namespace std;

class StringValidator
{
	public:
	virtual ~StringValidator() {};
	virtual bool isValid(string input) = 0;
};
// Write your code here
class DummyValidator : public StringValidator {
	public:
	virtual bool isValid(string input);
};
bool DummyValidator::isValid(string input)
{
	return true;
}

void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is "
	<< (validator.isValid(input) ? "valid" : "invalid") << endl;
}

class ExactValidator :  public StringValidator {
	private:
	string pattern;
	public:
	bool isValid(string input);
	ExactValidator(string _secret);
};

ExactValidator::ExactValidator(string _secret)
{
	pattern = _secret;
}
bool ExactValidator::isValid(string input)
{
	if(pattern == input) return true;
	return false;
}

int main()
{
	DummyValidator dummy;
	printValid(dummy, "hello");
	cout << endl;
	ExactValidator exact("secret");
	printValid(exact, "hello");
	printValid(exact, "secret");
	system("pause");
	return 0;
}