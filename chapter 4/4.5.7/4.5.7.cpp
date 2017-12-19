#include <string>
#include <iostream>
#include <regex>
using namespace std;

int main()
{
	string pattern;
	cout << "Enter pattern: ";
	getline(cin, pattern);
	string regexExpression = "";
	string sentence;
	smatch result;
	cout << "enter sentence: ";
	getline(cin, sentence);
	
	for (int i = 0; i < pattern.size(); i++)
	{
		if (pattern[i] == 'D')
			regexExpression += "[0-9]";
		else if (pattern[i] == 'A')
			regexExpression += "[a-zA-Z]";
		else if (pattern[i] == '?')
			regexExpression += ".";
		else if ((pattern[i] >= 'a' && pattern[i] <= 'z') || (pattern[i] >= 'A' && pattern[i] <= 'Z'))
		{
			regexExpression += "[";
			string letter = pattern.substr(i, 1);
			transform(letter.begin(), letter.end(), letter.begin(),(int (*)(int))toupper);
			regexExpression += letter;
			transform(letter.begin(), letter.end(), letter.begin(),(int (*)(int))tolower);
			regexExpression += letter;
			regexExpression += "]";	
		}
		else
			regexExpression += pattern[i];
	}
	regex reg (regexExpression);
	while (regex_search (sentence,result,reg)) 
	{    
		cout << result[0] << endl;
		sentence = result.suffix();
    }
	system("pause");
	return 0;
}