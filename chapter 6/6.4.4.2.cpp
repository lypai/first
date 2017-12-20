#include <iostream>
#include <string>
#include <regex>
using namespace std;

class StringValidator
{
	public:
	virtual ~StringValidator() {};
	virtual bool isValid(string input) = 0;
};

void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is "
	<< (validator.isValid(input) ? "valid" : "invalid") << endl;
}

class MinLengthValidator : public StringValidator
{
private:
	int minLenght;
public:
	MinLengthValidator(int lenght);
	bool isValid(string input);
};
MinLengthValidator::MinLengthValidator(int lenght)
{
	minLenght = lenght;
}
bool MinLengthValidator::isValid(string input)
{
	if(input.length() >= minLenght) return true;
	return false;
}

class MaxLengthValidator : public StringValidator
{
	private:
	int maxLenght;
public:
	MaxLengthValidator(int lenght);
	bool isValid(string input);
};
MaxLengthValidator::MaxLengthValidator(int lenght)
{
	maxLenght = lenght;
}
bool MaxLengthValidator::isValid(string input)
{
	if(input.length() <= maxLenght) return true;
	return false;
}

class PatternValidator : public StringValidator
{
private:
	string pattern;
public:
	PatternValidator(string pattern);
	bool isValid(string input);
};

PatternValidator::PatternValidator(string _pattern)
{
	pattern = _pattern;
}

bool PatternValidator::isValid(string input)
{
	string regexExpression = "";
	cmatch cm;
	for(int i = 0; i < pattern.size(); i++)
	{
		if(pattern[i] == 'D') regexExpression += "[0-9]";
		if(pattern[i] == 'A') regexExpression += "[a-zA-Z]";
		if(pattern[i] =='?') regexExpression += ".";
		
		if (regex_match(pattern.substr(i,1), regex("[a-z]")))
		{
			regexExpression += "[";
			string letter = pattern.substr(i, 1);
			transform(letter.begin(), letter.end(), letter.begin(),(int (*)(int))toupper);
			regexExpression += letter;
			transform(letter.begin(), letter.end(), letter.begin(),(int (*)(int))tolower);
			regexExpression += letter;
			regexExpression += "]";		
		}

		if (!regex_match(pattern.substr(i,1), regex("[a-zA-Z0-9\?]")))
		{
			regexExpression += "\\" + pattern.substr(i,1);
		}
	}	
	smatch result;
	regex e (regexExpression);
	return regex_search(input, result, e);
}

int main()
{
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	printValid(min, "hello");
	printValid(min, "welcome");
	cout << endl;
	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	printValid(max, "hello");
	printValid(max, "welcome");
	cout << endl;
	cout << "PatternValidator" << endl;
	PatternValidator digit("D");
	printValid(digit, "there are 2 types of sentences in the world");
	printValid(digit, "valid and invalid ones");
	cout << endl;
	system("pause");
	return 0;
}